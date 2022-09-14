grammar Query;

// Parser

query: querytermortermassoc (logicalop querytermortermassoc)* EOF // Query = (QueryTerm / QueryTermAssoc) *(LogicalOp (QueryTerm / QueryTermAssoc))
    ;
querytermortermassoc: queryterm
            | querytermassoc
    ;
querytermassoc : openingpar queryterm (logicalop queryterm)* closingpar // QueryTermAssoc = %x28 QueryTerm *(LogicalOp QueryTerm) %x29
    ;

queryterm   : attribute // QueryTerm = Attribute
            | attribute qoperator comparablevalue // QueryTerm =/ Attribute Operator ComparableValue
            | attribute equal compequalityvalue // QueryTerm =/ Attribute equal CompEqualityValue
            | attribute unequal compequalityvalue // QueryTerm =/ Attribute unequal CompEqualityValue
            | attribute patternop regex // QueryTerm =/ Attribute patternOp RegExp
            | attribute patternnoop regex // QueryTerm =/ Attribute notPatternOp RegExp
    ;
dottedpath: DOTTEDATTRNAME  // DottedPath = AttrName *(%x2E AttrName)
    ;
attribute : dottedpath ('['dottedpath']')? // WARNING: specs says "Attribute = DottedPath *1(%x5B DottedPath %x5D)" but also seems to allow for "Attribute = DottedPath *(%x5B DottedPath %x5D)"
    ;
qoperator : equal // Operator = equal / unequal / greaterEq / greater / lessEq / less
        | unequal
        | greatereq
        | greater
        | less
        | lesseq
    ;
patternop: PATTERNOP;
patternnoop: PATTERNNOOP;
greatereq: GREATEREQ
   ;
greater: GREATER
   ;
less: LESS
   ;
lesseq: LESSEQ
   ;

equal: EQUAL
    ;
unequal: UNEQUAL
    ;
othervalue: qfalse // OtherValue = false / true
    | qtrue
    ;
qtrue: TRUE
    ;
qfalse: FALSE
    ;
value: comparablevalue // Value = ComparableValue / OtherValue
    | othervalue
    ;
range: comparablevalue DOTS comparablevalue // Range = ComparableValue dots ComparableValue
    ;

valuelist: value (',' value)* // ValueList = Value 1*(%x2C Value)
    ;
compequalityvalue: othervalue // CompEqualityValue = OtherValue / ValueList / Range / URI
    | valuelist
    | range
    | uri
    ;

uri: URI
    ;
logicalop : orop // LogicalOp = andOp / orOp
    | andop
    ;

orop: OROP
    ;
andop: ANDOP
    ;
comparablevalue : number // ComparableValue = Number / quotedStr / dateTime / date / time
                | quotedstr
                | datetime
                | date
                | time
    ;

quotedstr: QUOTE quotedstringchar+ QUOTE
    ;
notaquote: ~QUOTE
    ;
quotedstringchar: notaquote|ESCAPEDBACKSLASH| BACKSLASH QUOTE
    ;
/* Our suggestion would be to use this instead of RE(<regex>)
regex: quotedstr
    ;
*/
// For Orion
regex: 'RE(' regexchar+ ')'
    ;
regexchar: notaparenthesis
    |BACKSLASH OPENINGPAR
    |BACKSLASH CLOSINGPAR
    |ESCAPEDBACKSLASH
    ;
notaparenthesis: ~(OPENINGPAR|CLOSINGPAR)
    ;

datetime: DATETIME
    ;

date: DATE
    ;
time: TIME
    ;

// IETF 8259 section 6
number : (MINUS)? qint (frac)? (EXP)? // = [ minus ] int [ frac ] [ exp ]
    ;

frac: DOT (anydigit)+      // frac = decimal-point 1*DIGIT
    ;
qint: ZERO
    | NONZERODIGIT (anydigit)*
    ;

// END IETF 8259 section 6

anydigit: (ZERO | NONZERODIGIT)+
    ;

// necessary for querytermassoc in the listener so that it does not consume query's logic
openingpar: OPENINGPAR
    ;
closingpar: CLOSINGPAR
    ;
//
// Lexer

DOTS: '..';
DOT: '.';
FALSE: 'false';
TRUE: 'true';
EQUAL : '==';
UNEQUAL : '!=';
GREATEREQ :'>=';
GREATER: '>';
LESSEQ: '<=';
LESS : '<';
EXP: [eE][+\-]?[1-9][0-9]*; // exp = e [ minus / plus ] 1*DIGIT
DOTTEDATTRNAME: ATTRNAME ('.' ATTRNAME)*;
ATTRNAME: [a-zA-Z][a-zA-Z0-9_]*; // TODO: should be unicode letters. This is pretty hard to do though
QUOTE: '"';
ZERO: '0';
NONZERODIGIT: [1-9];
PLUS: '+';
MINUS: '-';
OROP : '|';
ANDOP : ';';
DATE: [0-9][0-9][0-9][0-9]'-'[0-9][0-9]'-'[0-9][0-9];
TIME: [0-9][0-9]':'[0-9][0-9]':'[0-9][0-9] (('.' | ',')[0-9]*)?'Z';
// Date and time YYYY-MM-DDThh:mm:ssZ or YYYY-MM-DDThh:mm:ss.ssssssZ
// a comma can be used instead of a dot
DATETIME: DATE 'T' TIME;
// END date and time
URI: SCHEME ':' URICHAR+;
SCHEME: [a-zA-Z]([a-zA-Z] | [0-9] | PLUS | MINUS | '.')*; // scheme = ALPHA *( ALPHA / DIGIT / "+" / "-" / "." )
URICHAR: [a-zA-Z] | [0-9] | MINUS | PLUS | '~' | '&' | DOT | '/' | '?' | '%' | '='| '#' | '@' | '_' | ':'; // unreserved  = ALPHA / DIGIT / "-" / "." / "_" / "~"
PATTERNOP : '~=';
PATTERNNOOP : '!~=';
OPENINGPAR :'(';
CLOSINGPAR :')';
ESCAPEDBACKSLASH: BACKSLASH BACKSLASH;
BACKSLASH: '\\';
// it's alright if they're just mentioned here. If they're tokens, the lexer will identify them as candidates when a rule says "not this char"
OTHERLEXEDCHAR: ' '|'*'|'{'|'}'|'^'|'$'|'|'|'\'';
UNICODE: '\u007F'..'\uFFFF';