grammar Scopesq;

// Parser
scopesq : orscopeq (OROP orscopeq)* EOF                             // OrScopeQ *(orOp OrScopeQ)
    | toplevelwildcard EOF                                          // %x2F %23
    ;
toplevelwildcard: SCOPESEPARATOR SCOPEHIERARCHYWILDCARD
    ;
orscopeq : scopeq
    | '(' scopeq (ANDOP scopeq)* ')'                                // %x28 ScopeQ *(andOp ScopeQ) %x29
    | scopeq SCOPESEPARATOR  SCOPEHIERARCHYWILDCARD                 // ScopeQ *1(%x2F %23)
    ;
scopeq  : SCOPESEPARATOR scopeqlevel (SCOPESEPARATOR scopeqlevel)*  // %x2F ScopeQLevel *(%x2F ScopeQLevel)
    ;
scopeqlevel : IDENTIFIER
    | SCOPELEVELWILDCARD
    ;

// Lexer
SCOPESEPARATOR : '/' ;
OROP : '|' | ',';
ANDOP : ';';
IDENTIFIER: [a-zA-Z\u0080-\ufffe][_0-9a-zA-Z\u0080-\ufffe]*; // no real solution for this "unicode letter" and "unicode digit" thing so we accept ASCII letters or any unicode character as first character followed by any letter or digit or unicode characters
SCOPEHIERARCHYWILDCARD : '#';
SCOPELEVELWILDCARD : '+';
