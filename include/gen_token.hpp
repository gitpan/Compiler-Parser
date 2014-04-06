namespace Enum {
namespace Token {
namespace Type {
typedef enum {
	Return,
	Add,
	Sub,
	Mul,
	Div,
	Mod,
	ThreeTermOperator,
	Greater,
	Less,
	StringAdd,
	Ref,
	Glob,
	BitNot,
	BitOr,
	AlphabetOr,
	BitAnd,
	AlphabetAnd,
	BitXOr,
	AlphabetXOr,
	StringMul,
	AddEqual,
	SubEqual,
	MulEqual,
	DivEqual,
	ModEqual,
	StringAddEqual,
	GreaterEqual,
	LessEqual,
	EqualEqual,
	Diamond,
	Compare,
	PolymorphicCompare,
	RegOK,
	RegNot,
	NotEqual,
	StringLess,
	StringLessEqual,
	StringGreater,
	StringGreaterEqual,
	StringEqual,
	StringNotEqual,
	StringCompare,
	Inc,
	Dec,
	Exp,
	PowerEqual,
	DefaultEqual,
	LeftShift,
	RightShift,
	And,
	Or,
	AndBitEqual,
	OrBitEqual,
	NotBitEqual,
	OrEqual,
	AndEqual,
	Slice,
	DefaultOperator,
	ToDo,
	VarDecl,
	FunctionDecl,
	Method,
	Assign,
	ArraySize,
	Is,
	Not,
	AlphabetNot,
	BuiltinFunc,
	RequireDecl,
	Import,
	SpecificKeyword,
	DataWord,
	ModWord,
	AUTOLOAD,
	CORE,
	DESTROY,
	STDIN,
	STDOUT,
	STDERR,
	Redo,
	Next,
	Last,
	Goto,
	Continue,
	Do,
	Break,
	Handle,
	LocalDecl,
	OurDecl,
	StateDecl,
	UseDecl,
	UsedName,
	RequiredName,
	IfStmt,
	ElseStmt,
	ElsifStmt,
	UnlessStmt,
	UntilStmt,
	WhenStmt,
	GivenStmt,
	DefaultStmt,
	Comma,
	Colon,
	SemiColon,
	LeftParenthesis,
	RightParenthesis,
	LeftBrace,
	RightBrace,
	LeftBracket,
	RightBracket,
	ArrayDereference,
	HashDereference,
	ScalarDereference,
	CodeDereference,
	ShortScalarDereference,
	ShortArrayDereference,
	ShortHashDereference,
	ShortCodeDereference,
	ArraySizeDereference,
	Key,
	BareWord,
	Arrow,
	Pointer,
	NamespaceResolver,
	Namespace,
	Package,
	Class,
	CallDecl,
	CodeRef,
	WhileStmt,
	ForStmt,
	ForeachStmt,
	Annotation,
	ArgumentArray,
	SpecificValue,
	ConstValue,
	ProgramArgument,
	LibraryDirectories,
	Environment,
	Include,
	Signal,
	RegOpt,
	RegQuote,
	RegDoubleQuote,
	RegList,
	RegExec,
	RegDecl,
	RegMatch,
	RegDelim,
	HandleDelim,
	RegMiddleDelim,
	RegAllReplace,
	RegReplace,
	RegReplaceFrom,
	RegReplaceTo,
	FieldDecl,
	TypeRef,
	LabelRef,
	LocalVarDecl,
	GlobalVarDecl,
	MultiLocalVarDecl,
	MultiGlobalVarDecl,
	Prototype,
	Var,
	CodeVar,
	ArrayVar,
	HashVar,
	Int,
	Double,
	String,
	RawString,
	ExecString,
	VersionString,
	HereDocumentTag,
	HereDocumentRawTag,
	HereDocumentExecTag,
	RawHereDocument,
	HereDocument,
	HereDocumentEnd,
	FormatDecl,
	Format,
	FormatEnd,
	Object,
	RegExp,
	Array,
	Hash,
	Operator,
	LocalVar,
	LocalArrayVar,
	LocalHashVar,
	GlobalVar,
	GlobalArrayVar,
	GlobalHashVar,
	ArrayRef,
	HashRef,
	ArrayAt,
	HashAt,
	ArraySet,
	HashSet,
	Function,
	Call,
	Argument,
	List,
	Default,
	Pod,
	Comment,
	WhiteSpace,
	Undefined
} Type;
}

namespace Kind {
typedef enum {
	Return,
	Operator,
	Assign,
	Decl,
	Function,
	SingleTerm,
	Import,
	SpecificKeyword,
	DataWord,
	ModWord,
	AUTOLOAD,
	CORE,
	DESTROY,
	Handle,
	Control,
	Do,
	Module,
	Stmt,
	DefaultStmt,
	Comma,
	Colon,
	StmtEnd,
	Symbol,
	Modifier,
	Term,
	Namespace,
	Package,
	Class,
	Annotation,
	RegOpt,
	RegPrefix,
	RegReplacePrefix,
	Ref,
	Get,
	Set,
	Verbose,
	Undefined
} Kind;
}
}
}
