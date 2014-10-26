#include <common.hpp>

using namespace std;
namespace TokenType = Enum::Token::Type;
namespace SyntaxType = Enum::Parser::Syntax;
namespace TokenKind = Enum::Token::Kind;

Token::Token(string data_, FileInfo finfo_) :
	data(data_), token_num(0), total_token_num(0),
	deparsed_data(""), isDeparsed(false), isDeleted(false)
{
	type = TokenType::Undefined;
	stype = SyntaxType::Value;
	info.type = TokenType::Undefined;
	info.kind = TokenKind::Undefined;
	info.name = "";
	info.data = NULL;
	info.has_warnings = false;
	finfo.start_line_num = finfo_.start_line_num;
	finfo.end_line_num = finfo_.start_line_num;
	finfo.filename = finfo_.filename;
	finfo.indent = 0;
}

Token::Token(Tokens *tokens) :
	data(""), isDeparsed(false), isDeleted(false)
{
	total_token_num = 0;
	stype = SyntaxType::Value;
	type =  TokenType::Undefined;
	info.type = TokenType::Undefined;
	info.kind = TokenKind::Undefined;
	info.name = "";
	info.data = NULL;
	info.has_warnings = false;
	size_t size = tokens->size();
	TokenPos pos = tokens->begin();
	tks = (Token **)safe_malloc(size * PTR_SIZE);
	token_num = size;
	size_t i = 0;
	size_t end_line_num = 0;
	finfo.indent = 0;
	for (; i < size; i++) {
		Token *t = (Token *)*pos;
		tks[i] = t;
		if (t->info.has_warnings) {
			info.has_warnings = true;
		}
		if (i == 0) {
			finfo.start_line_num = tks[i]->finfo.start_line_num;
			finfo.filename = tks[i]->finfo.filename;
		}
		if (t->total_token_num > 1) {
			total_token_num += t->total_token_num;
			if (end_line_num < t->finfo.end_line_num) {
				end_line_num = t->finfo.end_line_num;
			}
		} else {
			total_token_num += 1;
			if (end_line_num < t->finfo.start_line_num) {
				end_line_num = t->finfo.start_line_num;
			}
		}
		pos++;
	}
	finfo.end_line_num = end_line_num;
}

const char *Token::deparse(void)
{
	using namespace TokenType;
	if (isDeparsed) return cstr(deparsed_data);
	isDeparsed = true;
	if (this->token_num > 0) {
		if (stype == SyntaxType::Expr) {
			//deparsed_data += "(";
		}
		for (size_t i = 0; i < this->token_num; i++) {
			deparsed_data += string(this->tks[i]->deparse());
		}
		if (stype == SyntaxType::Expr) {
			//deparsed_data += ")";
		}
	} else {
		switch (info.type) {
		case String:
			deparsed_data += " \"" + this->data + "\"";
			break;
		case RawString:
			deparsed_data += " '" + this->data + "'";
			break;
		case ExecString:
			deparsed_data += " `" + this->data + "`";
			break;
		case RegExp: case Pointer:
		case RegReplaceFrom: case RegReplaceTo:
		case RegMiddleDelim: case RegDelim:
		case RegOpt:
			deparsed_data += this->data;
			break;
		case HereDocument:
			deparsed_data += "\n" + this->data;
			break;
		case HereDocumentEnd:
			deparsed_data += this->data + "\n";
			break;
		default:
			deparsed_data += " " + this->data;
			break;
		}
	}
	return cstr(deparsed_data);
}

Tokens::Tokens(void) {}

void Tokens::add(Token *token)
{
	if (token) this->push_back(token);
}

void Tokens::remove(size_t idx)
{
	//this->erase(idx);
}

Token *Tokens::lastToken(void)
{
	size_t size = this->size();
	return (size > 0) ? this->back() : NULL;
}

TokenInfo getTokenInfo(TokenType::Type type)
{
	size_t i = 0;
	for (; decl_tokens[i].type != TokenType::Undefined; i++) {
		if (type == decl_tokens[i].type) {
			return decl_tokens[i];
		}
	}
	return decl_tokens[i];
}

TokenInfo getTokenInfo(const char *data)
{
	size_t i = 0;
	size_t dsize = strlen(data);
	for (; decl_tokens[i].type != TokenType::Undefined; i++) {
		const char *token_data = decl_tokens[i].data;
		size_t tsize = strlen(token_data);
		if (dsize == tsize && !strncmp(token_data, data, dsize)) {
			return decl_tokens[i];
		}
	}
	return decl_tokens[i];
}
