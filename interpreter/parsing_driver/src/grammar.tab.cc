// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "grammar.tab.hh"


// Unqualified %code blocks.
#line 28 "grammar.yy"

    #include "parsing_driver.h"

#line 50 "grammar.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 142 "grammar.tab.cc"

  /// Build a parser object.
  parser::parser (ParsingDriver& drv_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      yy_lac_established_ (false),
      drv (drv_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_MOVE_OPERATOR: // MOVE_OPERATOR
        value.YY_MOVE_OR_COPY< MoveDirection > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_info: // type_info
        value.YY_MOVE_OR_COPY< TypeHolder > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DIRECTION: // DIRECTION
        value.YY_MOVE_OR_COPY< WallPlaceholder > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_SIGNED_NUM: // SIGNED_NUM
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_SIMPLE_TYPE: // SIMPLE_TYPE
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_func_call: // func_call
        value.YY_MOVE_OR_COPY< std::unique_ptr<FuncCallNode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_func_decl: // func_decl
        value.YY_MOVE_OR_COPY< std::unique_ptr<FuncDeclNode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_sentence: // sentence
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_assign: // assign
      case symbol_kind::S_if_clause: // if_clause
      case symbol_kind::S_while_clause: // while_clause
      case symbol_kind::S_cell_literal: // cell_literal
      case symbol_kind::S_arithmetic_operand: // arithmetic_operand
      case symbol_kind::S_arithmetic_expr: // arithmetic_expr
        value.YY_MOVE_OR_COPY< std::unique_ptr<INode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_initialization: // initialization
        value.YY_MOVE_OR_COPY< std::unique_ptr<InitializationNode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_print: // print
        value.YY_MOVE_OR_COPY< std::unique_ptr<PrintNode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program_block: // program_block
      case symbol_kind::S_sentence_group: // sentence_group
      case symbol_kind::S_sentence_list: // sentence_list
        value.YY_MOVE_OR_COPY< std::unique_ptr<StatementListNode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_decl: // var_decl
        value.YY_MOVE_OR_COPY< std::unique_ptr<VarDeclNode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_ref: // var_ref
        value.YY_MOVE_OR_COPY< std::unique_ptr<VarReferenceNode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cell_literal_list: // cell_literal_list
        value.YY_MOVE_OR_COPY< std::vector<WallPlaceholder> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument_list: // argument_list
        value.YY_MOVE_OR_COPY< std::vector<std::unique_ptr<INode>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_param_list: // param_list
        value.YY_MOVE_OR_COPY< std::vector<std::unique_ptr<VarDeclNode>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_UNSIGNED_NUM: // UNSIGNED_NUM
        value.YY_MOVE_OR_COPY< unsigned int > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_MOVE_OPERATOR: // MOVE_OPERATOR
        value.move< MoveDirection > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_info: // type_info
        value.move< TypeHolder > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_DIRECTION: // DIRECTION
        value.move< WallPlaceholder > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_SIGNED_NUM: // SIGNED_NUM
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_SIMPLE_TYPE: // SIMPLE_TYPE
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_func_call: // func_call
        value.move< std::unique_ptr<FuncCallNode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_func_decl: // func_decl
        value.move< std::unique_ptr<FuncDeclNode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_sentence: // sentence
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_assign: // assign
      case symbol_kind::S_if_clause: // if_clause
      case symbol_kind::S_while_clause: // while_clause
      case symbol_kind::S_cell_literal: // cell_literal
      case symbol_kind::S_arithmetic_operand: // arithmetic_operand
      case symbol_kind::S_arithmetic_expr: // arithmetic_expr
        value.move< std::unique_ptr<INode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_initialization: // initialization
        value.move< std::unique_ptr<InitializationNode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_print: // print
        value.move< std::unique_ptr<PrintNode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_program_block: // program_block
      case symbol_kind::S_sentence_group: // sentence_group
      case symbol_kind::S_sentence_list: // sentence_list
        value.move< std::unique_ptr<StatementListNode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_decl: // var_decl
        value.move< std::unique_ptr<VarDeclNode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_var_ref: // var_ref
        value.move< std::unique_ptr<VarReferenceNode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_cell_literal_list: // cell_literal_list
        value.move< std::vector<WallPlaceholder> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_argument_list: // argument_list
        value.move< std::vector<std::unique_ptr<INode>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_param_list: // param_list
        value.move< std::vector<std::unique_ptr<VarDeclNode>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_UNSIGNED_NUM: // UNSIGNED_NUM
        value.move< unsigned int > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_MOVE_OPERATOR: // MOVE_OPERATOR
        value.copy< MoveDirection > (that.value);
        break;

      case symbol_kind::S_type_info: // type_info
        value.copy< TypeHolder > (that.value);
        break;

      case symbol_kind::S_DIRECTION: // DIRECTION
        value.copy< WallPlaceholder > (that.value);
        break;

      case symbol_kind::S_SIGNED_NUM: // SIGNED_NUM
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_SIMPLE_TYPE: // SIMPLE_TYPE
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_func_call: // func_call
        value.copy< std::unique_ptr<FuncCallNode> > (that.value);
        break;

      case symbol_kind::S_func_decl: // func_decl
        value.copy< std::unique_ptr<FuncDeclNode> > (that.value);
        break;

      case symbol_kind::S_sentence: // sentence
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_assign: // assign
      case symbol_kind::S_if_clause: // if_clause
      case symbol_kind::S_while_clause: // while_clause
      case symbol_kind::S_cell_literal: // cell_literal
      case symbol_kind::S_arithmetic_operand: // arithmetic_operand
      case symbol_kind::S_arithmetic_expr: // arithmetic_expr
        value.copy< std::unique_ptr<INode> > (that.value);
        break;

      case symbol_kind::S_initialization: // initialization
        value.copy< std::unique_ptr<InitializationNode> > (that.value);
        break;

      case symbol_kind::S_print: // print
        value.copy< std::unique_ptr<PrintNode> > (that.value);
        break;

      case symbol_kind::S_program_block: // program_block
      case symbol_kind::S_sentence_group: // sentence_group
      case symbol_kind::S_sentence_list: // sentence_list
        value.copy< std::unique_ptr<StatementListNode> > (that.value);
        break;

      case symbol_kind::S_var_decl: // var_decl
        value.copy< std::unique_ptr<VarDeclNode> > (that.value);
        break;

      case symbol_kind::S_var_ref: // var_ref
        value.copy< std::unique_ptr<VarReferenceNode> > (that.value);
        break;

      case symbol_kind::S_cell_literal_list: // cell_literal_list
        value.copy< std::vector<WallPlaceholder> > (that.value);
        break;

      case symbol_kind::S_argument_list: // argument_list
        value.copy< std::vector<std::unique_ptr<INode>> > (that.value);
        break;

      case symbol_kind::S_param_list: // param_list
        value.copy< std::vector<std::unique_ptr<VarDeclNode>> > (that.value);
        break;

      case symbol_kind::S_UNSIGNED_NUM: // UNSIGNED_NUM
        value.copy< unsigned int > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_MOVE_OPERATOR: // MOVE_OPERATOR
        value.move< MoveDirection > (that.value);
        break;

      case symbol_kind::S_type_info: // type_info
        value.move< TypeHolder > (that.value);
        break;

      case symbol_kind::S_DIRECTION: // DIRECTION
        value.move< WallPlaceholder > (that.value);
        break;

      case symbol_kind::S_SIGNED_NUM: // SIGNED_NUM
        value.move< int > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_SIMPLE_TYPE: // SIMPLE_TYPE
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_func_call: // func_call
        value.move< std::unique_ptr<FuncCallNode> > (that.value);
        break;

      case symbol_kind::S_func_decl: // func_decl
        value.move< std::unique_ptr<FuncDeclNode> > (that.value);
        break;

      case symbol_kind::S_sentence: // sentence
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_assign: // assign
      case symbol_kind::S_if_clause: // if_clause
      case symbol_kind::S_while_clause: // while_clause
      case symbol_kind::S_cell_literal: // cell_literal
      case symbol_kind::S_arithmetic_operand: // arithmetic_operand
      case symbol_kind::S_arithmetic_expr: // arithmetic_expr
        value.move< std::unique_ptr<INode> > (that.value);
        break;

      case symbol_kind::S_initialization: // initialization
        value.move< std::unique_ptr<InitializationNode> > (that.value);
        break;

      case symbol_kind::S_print: // print
        value.move< std::unique_ptr<PrintNode> > (that.value);
        break;

      case symbol_kind::S_program_block: // program_block
      case symbol_kind::S_sentence_group: // sentence_group
      case symbol_kind::S_sentence_list: // sentence_list
        value.move< std::unique_ptr<StatementListNode> > (that.value);
        break;

      case symbol_kind::S_var_decl: // var_decl
        value.move< std::unique_ptr<VarDeclNode> > (that.value);
        break;

      case symbol_kind::S_var_ref: // var_ref
        value.move< std::unique_ptr<VarReferenceNode> > (that.value);
        break;

      case symbol_kind::S_cell_literal_list: // cell_literal_list
        value.move< std::vector<WallPlaceholder> > (that.value);
        break;

      case symbol_kind::S_argument_list: // argument_list
        value.move< std::vector<std::unique_ptr<INode>> > (that.value);
        break;

      case symbol_kind::S_param_list: // param_list
        value.move< std::vector<std::unique_ptr<VarDeclNode>> > (that.value);
        break;

      case symbol_kind::S_UNSIGNED_NUM: // UNSIGNED_NUM
        value.move< unsigned int > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // Discard the LAC context in case there still is one left from a
    // previous invocation.
    yy_lac_discard_ ("init");

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (drv));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        if (!yy_lac_establish_ (yyla.kind ()))
          goto yyerrlab;

        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    yy_lac_discard_ ("shift");
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_MOVE_OPERATOR: // MOVE_OPERATOR
        yylhs.value.emplace< MoveDirection > ();
        break;

      case symbol_kind::S_type_info: // type_info
        yylhs.value.emplace< TypeHolder > ();
        break;

      case symbol_kind::S_DIRECTION: // DIRECTION
        yylhs.value.emplace< WallPlaceholder > ();
        break;

      case symbol_kind::S_SIGNED_NUM: // SIGNED_NUM
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_SIMPLE_TYPE: // SIMPLE_TYPE
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_func_call: // func_call
        yylhs.value.emplace< std::unique_ptr<FuncCallNode> > ();
        break;

      case symbol_kind::S_func_decl: // func_decl
        yylhs.value.emplace< std::unique_ptr<FuncDeclNode> > ();
        break;

      case symbol_kind::S_sentence: // sentence
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_assign: // assign
      case symbol_kind::S_if_clause: // if_clause
      case symbol_kind::S_while_clause: // while_clause
      case symbol_kind::S_cell_literal: // cell_literal
      case symbol_kind::S_arithmetic_operand: // arithmetic_operand
      case symbol_kind::S_arithmetic_expr: // arithmetic_expr
        yylhs.value.emplace< std::unique_ptr<INode> > ();
        break;

      case symbol_kind::S_initialization: // initialization
        yylhs.value.emplace< std::unique_ptr<InitializationNode> > ();
        break;

      case symbol_kind::S_print: // print
        yylhs.value.emplace< std::unique_ptr<PrintNode> > ();
        break;

      case symbol_kind::S_program_block: // program_block
      case symbol_kind::S_sentence_group: // sentence_group
      case symbol_kind::S_sentence_list: // sentence_list
        yylhs.value.emplace< std::unique_ptr<StatementListNode> > ();
        break;

      case symbol_kind::S_var_decl: // var_decl
        yylhs.value.emplace< std::unique_ptr<VarDeclNode> > ();
        break;

      case symbol_kind::S_var_ref: // var_ref
        yylhs.value.emplace< std::unique_ptr<VarReferenceNode> > ();
        break;

      case symbol_kind::S_cell_literal_list: // cell_literal_list
        yylhs.value.emplace< std::vector<WallPlaceholder> > ();
        break;

      case symbol_kind::S_argument_list: // argument_list
        yylhs.value.emplace< std::vector<std::unique_ptr<INode>> > ();
        break;

      case symbol_kind::S_param_list: // param_list
        yylhs.value.emplace< std::vector<std::unique_ptr<VarDeclNode>> > ();
        break;

      case symbol_kind::S_UNSIGNED_NUM: // UNSIGNED_NUM
        yylhs.value.emplace< unsigned int > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // program: program_block $end
#line 88 "grammar.yy"
                        {drv.tree_ = {std::move(yystack_[1].value.as < std::unique_ptr<StatementListNode> > ())};}
#line 937 "grammar.tab.cc"
    break;

  case 3: // program_block: %empty
#line 91 "grammar.yy"
           {yylhs.value.as < std::unique_ptr<StatementListNode> > () = std::make_unique<StatementListNode>();}
#line 943 "grammar.tab.cc"
    break;

  case 4: // program_block: func_decl program_block
#line 92 "grammar.yy"
                              {
        yystack_[0].value.as < std::unique_ptr<StatementListNode> > ()->AddStatement(std::move(yystack_[1].value.as < std::unique_ptr<FuncDeclNode> > ()));
        yylhs.value.as < std::unique_ptr<StatementListNode> > () = std::move(yystack_[0].value.as < std::unique_ptr<StatementListNode> > ());
        yylhs.location = {yystack_[1].location.begin, yystack_[0].location.end};
        }
#line 953 "grammar.tab.cc"
    break;

  case 5: // program_block: sentence program_block
#line 97 "grammar.yy"
                             {
        yystack_[0].value.as < std::unique_ptr<StatementListNode> > ()->AddStatement(std::move(yystack_[1].value.as < std::unique_ptr<INode> > ()));
        yylhs.value.as < std::unique_ptr<StatementListNode> > () = std::move(yystack_[0].value.as < std::unique_ptr<StatementListNode> > ());
        yylhs.location = {yystack_[1].location.begin, yystack_[0].location.end};
        }
#line 963 "grammar.tab.cc"
    break;

  case 6: // program_block: if_clause program_block
#line 102 "grammar.yy"
                              {
        yystack_[0].value.as < std::unique_ptr<StatementListNode> > ()->AddStatement(std::move(yystack_[1].value.as < std::unique_ptr<INode> > ()));
        yylhs.value.as < std::unique_ptr<StatementListNode> > () = std::move(yystack_[0].value.as < std::unique_ptr<StatementListNode> > ());
        yylhs.location = {yystack_[1].location.begin, yystack_[0].location.end};
        }
#line 973 "grammar.tab.cc"
    break;

  case 7: // program_block: while_clause program_block
#line 107 "grammar.yy"
                                 {
        yystack_[0].value.as < std::unique_ptr<StatementListNode> > ()->AddStatement(std::move(yystack_[1].value.as < std::unique_ptr<INode> > ()));
        yylhs.value.as < std::unique_ptr<StatementListNode> > () = std::move(yystack_[0].value.as < std::unique_ptr<StatementListNode> > ());
        yylhs.location = {yystack_[1].location.begin, yystack_[0].location.end};
        }
#line 983 "grammar.tab.cc"
    break;

  case 8: // func_decl: FUNC IDENTIFIER LPAREN param_list RPAREN sentence_group
#line 114 "grammar.yy"
                                                            {
        location_type loc(yystack_[5].location.begin, yystack_[3].location.end);
        yylhs.location = loc;
        yylhs.value.as < std::unique_ptr<FuncDeclNode> > () = std::make_unique<FuncDeclNode>(yystack_[4].value.as < std::string > (), std::move(yystack_[0].value.as < std::unique_ptr<StatementListNode> > ()), std::move(yystack_[2].value.as < std::vector<std::unique_ptr<VarDeclNode>> > ()), loc);
        }
#line 993 "grammar.tab.cc"
    break;

  case 9: // func_call: CALL IDENTIFIER LPAREN argument_list RPAREN
#line 122 "grammar.yy"
                                                {
        location_type loc(yystack_[4].location.begin, yystack_[0].location.end);
        yylhs.location = loc;
        yylhs.value.as < std::unique_ptr<FuncCallNode> > () = std::make_unique<FuncCallNode>(yystack_[3].value.as < std::string > (), std::move(yystack_[1].value.as < std::vector<std::unique_ptr<INode>> > ()), loc);
        }
#line 1003 "grammar.tab.cc"
    break;

  case 10: // func_call: CALL IDENTIFIER error
#line 127 "grammar.yy"
                            {drv.DetectError();}
#line 1009 "grammar.tab.cc"
    break;

  case 11: // param_list: param_list COMMA var_decl
#line 131 "grammar.yy"
                              {
        yystack_[2].value.as < std::vector<std::unique_ptr<VarDeclNode>> > ().emplace(yystack_[2].value.as < std::vector<std::unique_ptr<VarDeclNode>> > ().begin(), std::move(yystack_[0].value.as < std::unique_ptr<VarDeclNode> > ()));
        yylhs.value.as < std::vector<std::unique_ptr<VarDeclNode>> > () = std::move(yystack_[2].value.as < std::vector<std::unique_ptr<VarDeclNode>> > ());
        yylhs.location = {yystack_[2].location.begin, yystack_[0].location.end};
        }
#line 1019 "grammar.tab.cc"
    break;

  case 12: // param_list: var_decl
#line 136 "grammar.yy"
               {
        yylhs.value.as < std::vector<std::unique_ptr<VarDeclNode>> > ();
        yylhs.value.as < std::vector<std::unique_ptr<VarDeclNode>> > ().emplace(yylhs.value.as < std::vector<std::unique_ptr<VarDeclNode>> > ().begin(), std::move(yystack_[0].value.as < std::unique_ptr<VarDeclNode> > ()));
        yylhs.location = yystack_[0].location;
        }
#line 1029 "grammar.tab.cc"
    break;

  case 13: // param_list: %empty
#line 141 "grammar.yy"
             {}
#line 1035 "grammar.tab.cc"
    break;

  case 14: // argument_list: argument_list COMMA arithmetic_expr
#line 145 "grammar.yy"
                                        {
        yystack_[2].value.as < std::vector<std::unique_ptr<INode>> > ().emplace(yystack_[2].value.as < std::vector<std::unique_ptr<INode>> > ().begin(), std::move(yystack_[0].value.as < std::unique_ptr<INode> > ()));
        yylhs.value.as < std::vector<std::unique_ptr<INode>> > () = std::move(yystack_[2].value.as < std::vector<std::unique_ptr<INode>> > ());
        yylhs.location = {yystack_[2].location.begin, yystack_[0].location.end};
        }
#line 1045 "grammar.tab.cc"
    break;

  case 15: // argument_list: arithmetic_expr
#line 150 "grammar.yy"
                      {
        yylhs.value.as < std::vector<std::unique_ptr<INode>> > ();
        yylhs.value.as < std::vector<std::unique_ptr<INode>> > ().emplace(yylhs.value.as < std::vector<std::unique_ptr<INode>> > ().begin(), std::move(yystack_[0].value.as < std::unique_ptr<INode> > ()));
        yylhs.location = yystack_[0].location;
        }
#line 1055 "grammar.tab.cc"
    break;

  case 16: // argument_list: %empty
#line 155 "grammar.yy"
             {}
#line 1061 "grammar.tab.cc"
    break;

  case 17: // sentence_group: LPAREN sentence_list RPAREN
#line 159 "grammar.yy"
                                {
        yylhs.value.as < std::unique_ptr<StatementListNode> > () = std::move(yystack_[1].value.as < std::unique_ptr<StatementListNode> > ());
        yylhs.location = yystack_[1].location;
        }
#line 1070 "grammar.tab.cc"
    break;

  case 18: // sentence_group: LPAREN error RPAREN
#line 163 "grammar.yy"
                          {drv.DetectError();}
#line 1076 "grammar.tab.cc"
    break;

  case 19: // sentence_list: sentence sentence_list
#line 167 "grammar.yy"
                          {
        yystack_[0].value.as < std::unique_ptr<StatementListNode> > ()->AddStatement(std::move(yystack_[1].value.as < std::unique_ptr<INode> > ()));
        yylhs.value.as < std::unique_ptr<StatementListNode> > () = std::move(yystack_[0].value.as < std::unique_ptr<StatementListNode> > ());
        yylhs.location = {yystack_[1].location.begin, yystack_[0].location.end};
        }
#line 1086 "grammar.tab.cc"
    break;

  case 20: // sentence_list: if_clause sentence_list
#line 172 "grammar.yy"
                             {
        yystack_[0].value.as < std::unique_ptr<StatementListNode> > ()->AddStatement(std::move(yystack_[1].value.as < std::unique_ptr<INode> > ()));
        yylhs.value.as < std::unique_ptr<StatementListNode> > () = std::move(yystack_[0].value.as < std::unique_ptr<StatementListNode> > ());
        yylhs.location = {yystack_[1].location.begin, yystack_[0].location.end};
        }
#line 1096 "grammar.tab.cc"
    break;

  case 21: // sentence_list: while_clause sentence_list
#line 177 "grammar.yy"
                                 {
        yystack_[0].value.as < std::unique_ptr<StatementListNode> > ()->AddStatement(std::move(yystack_[1].value.as < std::unique_ptr<INode> > ()));
        yylhs.value.as < std::unique_ptr<StatementListNode> > () = std::move(yystack_[0].value.as < std::unique_ptr<StatementListNode> > ());
        yylhs.location = {yystack_[1].location.begin, yystack_[0].location.end};
    }
#line 1106 "grammar.tab.cc"
    break;

  case 22: // sentence_list: if_clause
#line 182 "grammar.yy"
                {
        yylhs.value.as < std::unique_ptr<StatementListNode> > () = std::make_unique<StatementListNode>();
        yylhs.value.as < std::unique_ptr<StatementListNode> > ()->AddStatement(std::move(yystack_[0].value.as < std::unique_ptr<INode> > ()));
        yylhs.location = yystack_[0].location;
        }
#line 1116 "grammar.tab.cc"
    break;

  case 23: // sentence_list: while_clause
#line 187 "grammar.yy"
                   {
        yylhs.value.as < std::unique_ptr<StatementListNode> > () = std::make_unique<StatementListNode>();
        yylhs.value.as < std::unique_ptr<StatementListNode> > ()->AddStatement(std::move(yystack_[0].value.as < std::unique_ptr<INode> > ()));
        yylhs.location = yystack_[0].location;
        }
#line 1126 "grammar.tab.cc"
    break;

  case 24: // sentence_list: sentence
#line 192 "grammar.yy"
               {
        yylhs.value.as < std::unique_ptr<StatementListNode> > () = std::make_unique<StatementListNode>();
        yylhs.value.as < std::unique_ptr<StatementListNode> > ()->AddStatement(std::move(yystack_[0].value.as < std::unique_ptr<INode> > ()));
        yylhs.location = yystack_[0].location;
        }
#line 1136 "grammar.tab.cc"
    break;

  case 25: // sentence: statement SEMICOLON
#line 200 "grammar.yy"
                        {
        yylhs.value.as < std::unique_ptr<INode> > () = std::move(yystack_[1].value.as < std::unique_ptr<INode> > ());
        yylhs.location = {yystack_[1].location.begin, yystack_[0].location.end};
        }
#line 1145 "grammar.tab.cc"
    break;

  case 26: // sentence: error SEMICOLON
#line 204 "grammar.yy"
                      {drv.DetectError();}
#line 1151 "grammar.tab.cc"
    break;

  case 27: // statement: arithmetic_expr
#line 208 "grammar.yy"
                    {yylhs.value.as < std::unique_ptr<INode> > () = std::move(yystack_[0].value.as < std::unique_ptr<INode> > ()); yylhs.location = yystack_[0].location;}
#line 1157 "grammar.tab.cc"
    break;

  case 28: // statement: assign
#line 209 "grammar.yy"
             {yylhs.value.as < std::unique_ptr<INode> > () = std::move(yystack_[0].value.as < std::unique_ptr<INode> > ()); yylhs.location = yystack_[0].location;}
#line 1163 "grammar.tab.cc"
    break;

  case 29: // statement: initialization
#line 210 "grammar.yy"
                     {yylhs.value.as < std::unique_ptr<INode> > () = std::move(yystack_[0].value.as < std::unique_ptr<InitializationNode> > ()); yylhs.location = yystack_[0].location;}
#line 1169 "grammar.tab.cc"
    break;

  case 30: // statement: MOVE_OPERATOR
#line 211 "grammar.yy"
                    {yylhs.value.as < std::unique_ptr<INode> > () = std::make_unique<RobotMoveNode>(yystack_[0].location, yystack_[0].value.as < MoveDirection > ()); yylhs.location = yystack_[0].location;}
#line 1175 "grammar.tab.cc"
    break;

  case 31: // statement: print
#line 212 "grammar.yy"
            {yylhs.value.as < std::unique_ptr<INode> > () = std::move(yystack_[0].value.as < std::unique_ptr<PrintNode> > ()); yylhs.location = yystack_[0].location;}
#line 1181 "grammar.tab.cc"
    break;

  case 32: // statement: %empty
#line 213 "grammar.yy"
             {yylhs.value.as < std::unique_ptr<INode> > () = nullptr;}
#line 1187 "grammar.tab.cc"
    break;

  case 33: // print: PRINT LPAREN arithmetic_expr RPAREN
#line 217 "grammar.yy"
                                        {
        location_type loc(yystack_[3].location.begin, yystack_[0].location.end);
        yylhs.location = loc;
        yylhs.value.as < std::unique_ptr<PrintNode> > () = std::make_unique<PrintNode>(std::move(yystack_[1].value.as < std::unique_ptr<INode> > ()), loc);
    }
#line 1197 "grammar.tab.cc"
    break;

  case 34: // print: PRINT error
#line 222 "grammar.yy"
                  {drv.DetectError();}
#line 1203 "grammar.tab.cc"
    break;

  case 35: // type_info: SIMPLE_TYPE
#line 226 "grammar.yy"
                {
        if(yystack_[0].value.as < std::string > () == "signed")
            yylhs.value.as < TypeHolder > () = {TypeToken::Signed};
        else if(yystack_[0].value.as < std::string > () == "unsigned")
            yylhs.value.as < TypeHolder > () = {TypeToken::Unsigned};
        else
            yylhs.value.as < TypeHolder > () = {TypeToken::Cell};
        yylhs.location = yystack_[0].location;
        }
#line 1217 "grammar.tab.cc"
    break;

  case 36: // type_info: MATRIX LESS type_info GREATER
#line 235 "grammar.yy"
                                    {
        yylhs.location = {yystack_[3].location.begin, yystack_[0].location.end};
        yylhs.value.as < TypeHolder > () = yystack_[1].value.as < TypeHolder > ();
        yylhs.value.as < TypeHolder > ().MakeMatrixWrap();
        }
#line 1227 "grammar.tab.cc"
    break;

  case 37: // var_decl: type_info var_ref
#line 243 "grammar.yy"
                      {
        location_type loc(yystack_[1].location.begin, yystack_[0].location.end);
        yylhs.location = loc;
        yylhs.value.as < std::unique_ptr<VarDeclNode> > () = std::make_unique<VarDeclNode>(std::move(yystack_[0].value.as < std::unique_ptr<VarReferenceNode> > ()), yystack_[1].value.as < TypeHolder > (), loc);
        }
#line 1237 "grammar.tab.cc"
    break;

  case 38: // var_decl: CONST type_info var_ref
#line 248 "grammar.yy"
                              {
        location_type loc(yystack_[2].location.begin, yystack_[0].location.end);
        yylhs.location = loc;
        yystack_[1].value.as < TypeHolder > ().MakeConst();
        yylhs.value.as < std::unique_ptr<VarDeclNode> > () = std::make_unique<VarDeclNode>(std::move(yystack_[0].value.as < std::unique_ptr<VarReferenceNode> > ()), yystack_[1].value.as < TypeHolder > (), loc, true);
        }
#line 1248 "grammar.tab.cc"
    break;

  case 39: // initialization: var_decl
#line 257 "grammar.yy"
             {yylhs.value.as < std::unique_ptr<InitializationNode> > () = std::make_unique<InitializationNode>(std::move(yystack_[0].value.as < std::unique_ptr<VarDeclNode> > ()), nullptr, yystack_[0].location); yylhs.location = yystack_[0].location;}
#line 1254 "grammar.tab.cc"
    break;

  case 40: // initialization: var_decl ASSIGN arithmetic_expr
#line 258 "grammar.yy"
                                      {
        location_type loc(yystack_[2].location.begin, yystack_[0].location.end);
        yylhs.location = loc;
        yylhs.value.as < std::unique_ptr<InitializationNode> > () = std::make_unique<InitializationNode>(std::move(yystack_[2].value.as < std::unique_ptr<VarDeclNode> > ()), std::move(yystack_[0].value.as < std::unique_ptr<INode> > ()), loc);
        }
#line 1264 "grammar.tab.cc"
    break;

  case 41: // initialization: var_decl ASSIGN XRAY
#line 263 "grammar.yy"
                           {
        location_type loc(yystack_[2].location.begin, yystack_[0].location.end);
        yylhs.location = loc;
        std::unique_ptr<INode> xray = std::make_unique<XrayNode>(yystack_[0].location);
        yylhs.value.as < std::unique_ptr<InitializationNode> > () = std::make_unique<InitializationNode>(std::move(yystack_[2].value.as < std::unique_ptr<VarDeclNode> > ()), std::move(xray), loc);
        }
#line 1275 "grammar.tab.cc"
    break;

  case 42: // assign: var_ref ASSIGN arithmetic_expr
#line 272 "grammar.yy"
                                   {
        location_type loc(yystack_[2].location.begin, yystack_[0].location.end);
        yylhs.location = loc;
        yylhs.value.as < std::unique_ptr<INode> > () = std::make_unique<AssignNode>(std::move(yystack_[2].value.as < std::unique_ptr<VarReferenceNode> > ()), std::move(yystack_[0].value.as < std::unique_ptr<INode> > ()), loc);
        }
#line 1285 "grammar.tab.cc"
    break;

  case 43: // assign: var_ref ASSIGN XRAY
#line 277 "grammar.yy"
                          {
        location_type loc(yystack_[2].location.begin, yystack_[0].location.end);
        yylhs.location = loc;
        std::unique_ptr<INode> xray = std::make_unique<XrayNode>(yystack_[0].location);
        yylhs.value.as < std::unique_ptr<INode> > () = std::make_unique<AssignNode>(std::move(yystack_[2].value.as < std::unique_ptr<VarReferenceNode> > ()), std::move(xray), loc);
        }
#line 1296 "grammar.tab.cc"
    break;

  case 44: // if_clause: TESTONCE LPAREN arithmetic_expr RPAREN sentence_group
#line 286 "grammar.yy"
                                                          {
        location_type loc(yystack_[4].location.begin, yystack_[0].location.end);
        yylhs.location = loc;
        yylhs.value.as < std::unique_ptr<INode> > () = std::make_unique<IfNode>(std::move(yystack_[2].value.as < std::unique_ptr<INode> > ()), std::move(yystack_[0].value.as < std::unique_ptr<StatementListNode> > ()), loc);
        }
#line 1306 "grammar.tab.cc"
    break;

  case 45: // if_clause: TESTONCE error
#line 291 "grammar.yy"
                     {drv.DetectError();}
#line 1312 "grammar.tab.cc"
    break;

  case 46: // while_clause: TESTREP LPAREN arithmetic_expr RPAREN sentence_group
#line 295 "grammar.yy"
                                                         {
        location_type loc(yystack_[4].location.begin, yystack_[0].location.end);
        yylhs.location = loc;
        yylhs.value.as < std::unique_ptr<INode> > () = std::make_unique<WhileNode>(std::move(yystack_[2].value.as < std::unique_ptr<INode> > ()), std::move(yystack_[0].value.as < std::unique_ptr<StatementListNode> > ()), loc);
        }
#line 1322 "grammar.tab.cc"
    break;

  case 47: // while_clause: TESTREP error
#line 300 "grammar.yy"
                    {drv.DetectError();}
#line 1328 "grammar.tab.cc"
    break;

  case 48: // cell_literal: LPAREN cell_literal_list RPAREN
#line 304 "grammar.yy"
                                    {
        location_type loc(yystack_[2].location.begin, yystack_[0].location.end);
        yylhs.location = loc;
        yylhs.value.as < std::unique_ptr<INode> > () = std::make_unique<CellLiteralNode>(std::move(yystack_[1].value.as < std::vector<WallPlaceholder> > ()), loc);
        }
#line 1338 "grammar.tab.cc"
    break;

  case 49: // cell_literal_list: cell_literal_list COMMA DIRECTION
#line 311 "grammar.yy"
                                      {
        yystack_[2].value.as < std::vector<WallPlaceholder> > ().emplace_back(yystack_[0].value.as < WallPlaceholder > ());
        yylhs.value.as < std::vector<WallPlaceholder> > () = std::move(yystack_[2].value.as < std::vector<WallPlaceholder> > ());
        yylhs.location = {yystack_[2].location.begin, yystack_[0].location.end};
        }
#line 1348 "grammar.tab.cc"
    break;

  case 50: // cell_literal_list: DIRECTION
#line 316 "grammar.yy"
                {
        yylhs.value.as < std::vector<WallPlaceholder> > ();
        yylhs.value.as < std::vector<WallPlaceholder> > ().emplace_back(yystack_[0].value.as < WallPlaceholder > ());
        yylhs.location = yystack_[0].location;
        }
#line 1358 "grammar.tab.cc"
    break;

  case 51: // var_ref: IDENTIFIER
#line 324 "grammar.yy"
               {
        yylhs.value.as < std::unique_ptr<VarReferenceNode> > () = std::make_unique<VarReferenceNode>(yystack_[0].value.as < std::string > (), yystack_[0].location);
        yylhs.location = yystack_[0].location;
        }
#line 1367 "grammar.tab.cc"
    break;

  case 52: // var_ref: IDENTIFIER LPAREN arithmetic_expr COMMA arithmetic_expr RPAREN
#line 328 "grammar.yy"
                                                                     {
        yylhs.value.as < std::unique_ptr<VarReferenceNode> > () = std::make_unique<MatrixElementReferenceNode>(yystack_[5].value.as < std::string > (), std::move(yystack_[3].value.as < std::unique_ptr<INode> > ()), std::move(yystack_[1].value.as < std::unique_ptr<INode> > ()), yystack_[5].location);
        yylhs.location = {yystack_[5].location.begin, yystack_[0].location.end};
        }
#line 1376 "grammar.tab.cc"
    break;

  case 53: // arithmetic_operand: SIGNED_NUM
#line 334 "grammar.yy"
               {yylhs.value.as < std::unique_ptr<INode> > () = std::make_unique<SignedLiteralNode>(yystack_[0].value.as < int > (), yystack_[0].location); yylhs.location = yystack_[0].location;}
#line 1382 "grammar.tab.cc"
    break;

  case 54: // arithmetic_operand: UNSIGNED_NUM
#line 335 "grammar.yy"
                   {yylhs.value.as < std::unique_ptr<INode> > () = std::make_unique<UnsignedLiteralNode>(yystack_[0].value.as < unsigned int > (), yystack_[0].location); yylhs.location = yystack_[0].location;}
#line 1388 "grammar.tab.cc"
    break;

  case 55: // arithmetic_operand: cell_literal
#line 336 "grammar.yy"
                   {yylhs.value.as < std::unique_ptr<INode> > () = std::move(yystack_[0].value.as < std::unique_ptr<INode> > ()); yylhs.location = yystack_[0].location;}
#line 1394 "grammar.tab.cc"
    break;

  case 56: // arithmetic_operand: var_ref
#line 337 "grammar.yy"
              {yylhs.value.as < std::unique_ptr<INode> > () = std::move(yystack_[0].value.as < std::unique_ptr<VarReferenceNode> > ()); yylhs.location = yystack_[0].location;}
#line 1400 "grammar.tab.cc"
    break;

  case 57: // arithmetic_operand: func_call
#line 338 "grammar.yy"
                {yylhs.value.as < std::unique_ptr<INode> > () = std::move(yystack_[0].value.as < std::unique_ptr<FuncCallNode> > ()); yylhs.location = yystack_[0].location;}
#line 1406 "grammar.tab.cc"
    break;

  case 58: // arithmetic_expr: arithmetic_operand
#line 342 "grammar.yy"
                       {
        yylhs.location = yystack_[0].location;
        yylhs.value.as < std::unique_ptr<INode> > () = std::move(yystack_[0].value.as < std::unique_ptr<INode> > ());
        }
#line 1415 "grammar.tab.cc"
    break;

  case 59: // arithmetic_expr: arithmetic_expr PLUS arithmetic_expr
#line 346 "grammar.yy"
                                           {
        location_type loc(yystack_[2].location.begin, yystack_[0].location.end);
        yylhs.location = loc;
        yylhs.value.as < std::unique_ptr<INode> > () = std::make_unique<BinaryOpNode>(BinaryOpKind::Plus, std::move(yystack_[2].value.as < std::unique_ptr<INode> > ()), std::move(yystack_[0].value.as < std::unique_ptr<INode> > ()), loc);
        }
#line 1425 "grammar.tab.cc"
    break;

  case 60: // arithmetic_expr: arithmetic_expr MINUS arithmetic_expr
#line 351 "grammar.yy"
                                            {
        location_type loc(yystack_[2].location.begin, yystack_[0].location.end);
        yylhs.location = loc;
        yylhs.value.as < std::unique_ptr<INode> > () = std::make_unique<BinaryOpNode>(BinaryOpKind::Minus, std::move(yystack_[2].value.as < std::unique_ptr<INode> > ()), std::move(yystack_[0].value.as < std::unique_ptr<INode> > ()), loc);
        }
#line 1435 "grammar.tab.cc"
    break;

  case 61: // arithmetic_expr: arithmetic_expr STAR arithmetic_expr
#line 356 "grammar.yy"
                                           {
        location_type loc(yystack_[2].location.begin, yystack_[0].location.end);
        yylhs.location = loc;
        yylhs.value.as < std::unique_ptr<INode> > () = std::make_unique<BinaryOpNode>(BinaryOpKind::Star, std::move(yystack_[2].value.as < std::unique_ptr<INode> > ()), std::move(yystack_[0].value.as < std::unique_ptr<INode> > ()), loc);
        }
#line 1445 "grammar.tab.cc"
    break;

  case 62: // arithmetic_expr: arithmetic_expr SLASH arithmetic_expr
#line 361 "grammar.yy"
                                            {
        location_type loc(yystack_[2].location.begin, yystack_[0].location.end);
        yylhs.location = loc;
        yylhs.value.as < std::unique_ptr<INode> > () = std::make_unique<BinaryOpNode>(BinaryOpKind::Slash, std::move(yystack_[2].value.as < std::unique_ptr<INode> > ()), std::move(yystack_[0].value.as < std::unique_ptr<INode> > ()), loc);
        }
#line 1455 "grammar.tab.cc"
    break;

  case 63: // arithmetic_expr: arithmetic_expr PERCENT arithmetic_expr
#line 366 "grammar.yy"
                                              {
        location_type loc(yystack_[2].location.begin, yystack_[0].location.end);
        yylhs.location = loc;
        yylhs.value.as < std::unique_ptr<INode> > () = std::make_unique<BinaryOpNode>(BinaryOpKind::Percent, std::move(yystack_[2].value.as < std::unique_ptr<INode> > ()), std::move(yystack_[0].value.as < std::unique_ptr<INode> > ()), loc);
        }
#line 1465 "grammar.tab.cc"
    break;

  case 64: // arithmetic_expr: MINUS arithmetic_expr
#line 371 "grammar.yy"
                                        {
        location_type loc(yystack_[1].location.begin, yystack_[0].location.end);
        yylhs.location = loc;
        yylhs.value.as < std::unique_ptr<INode> > () = std::make_unique<UnaryOpNode>(UnaryOpKind::Minus, std::move(yystack_[0].value.as < std::unique_ptr<INode> > ()), loc);
        }
#line 1475 "grammar.tab.cc"
    break;

  case 65: // arithmetic_expr: PLUS arithmetic_expr
#line 376 "grammar.yy"
                                       {
         location_type loc(yystack_[1].location.begin, yystack_[0].location.end);
         yylhs.location = loc;
         yylhs.value.as < std::unique_ptr<INode> > () = std::make_unique<UnaryOpNode>(UnaryOpKind::Plus, std::move(yystack_[0].value.as < std::unique_ptr<INode> > ()), loc);
    }
#line 1485 "grammar.tab.cc"
    break;

  case 66: // arithmetic_expr: HASH arithmetic_expr
#line 381 "grammar.yy"
                           {
        location_type loc(yystack_[1].location.begin, yystack_[0].location.end);
        yylhs.location = loc;
        yylhs.value.as < std::unique_ptr<INode> > () = std::make_unique<UnaryOpNode>(UnaryOpKind::Hash, std::move(yystack_[0].value.as < std::unique_ptr<INode> > ()), loc);
    }
#line 1495 "grammar.tab.cc"
    break;

  case 67: // arithmetic_expr: LPAREN arithmetic_expr RPAREN
#line 386 "grammar.yy"
                                    {
        location_type loc(yystack_[2].location.begin, yystack_[0].location.end);
        yylhs.location = loc;
        yylhs.value.as < std::unique_ptr<INode> > () = std::move(yystack_[1].value.as < std::unique_ptr<INode> > ());
        }
#line 1505 "grammar.tab.cc"
    break;

  case 68: // arithmetic_expr: arithmetic_expr LESS arithmetic_expr
#line 391 "grammar.yy"
                                           {
        location_type loc(yystack_[2].location.begin, yystack_[0].location.end);
        yylhs.location = loc;
        yylhs.value.as < std::unique_ptr<INode> > () = std::make_unique<BinaryOpNode>(BinaryOpKind::Less, std::move(yystack_[2].value.as < std::unique_ptr<INode> > ()), std::move(yystack_[0].value.as < std::unique_ptr<INode> > ()), loc);
        }
#line 1515 "grammar.tab.cc"
    break;

  case 69: // arithmetic_expr: arithmetic_expr GREATER arithmetic_expr
#line 396 "grammar.yy"
                                              {
        location_type loc(yystack_[2].location.begin, yystack_[0].location.end);
        yylhs.location = loc;
        yylhs.value.as < std::unique_ptr<INode> > () = std::make_unique<BinaryOpNode>(BinaryOpKind::Greater, std::move(yystack_[2].value.as < std::unique_ptr<INode> > ()), std::move(yystack_[0].value.as < std::unique_ptr<INode> > ()), loc);
        }
#line 1525 "grammar.tab.cc"
    break;

  case 70: // arithmetic_expr: arithmetic_expr EQUAL arithmetic_expr
#line 401 "grammar.yy"
                                            {
        location_type loc(yystack_[2].location.begin, yystack_[0].location.end);
        yylhs.location = loc;
        yylhs.value.as < std::unique_ptr<INode> > () = std::make_unique<BinaryOpNode>(BinaryOpKind::Equal, std::move(yystack_[2].value.as < std::unique_ptr<INode> > ()), std::move(yystack_[0].value.as < std::unique_ptr<INode> > ()), loc);
        }
#line 1535 "grammar.tab.cc"
    break;

  case 71: // arithmetic_expr: LPAREN error RPAREN
#line 406 "grammar.yy"
                          {drv.DetectError();}
#line 1541 "grammar.tab.cc"
    break;


#line 1545 "grammar.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      yy_lac_discard_ ("error recovery");
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "end of file", "error", "invalid token", "ASSIGN", "MINUS", "PLUS",
  "STAR", "SLASH", "HASH", "LPAREN", "RPAREN", "PERCENT", "LESS",
  "GREATER", "EQUAL", "CONST", "NEW_LINE", "SEMICOLON", "CALL", "FUNC",
  "TESTREP", "TESTONCE", "MATRIX", "COMMA", "XRAY", "PRINT", "IDENTIFIER",
  "SIGNED_NUM", "UNSIGNED_NUM", "SIMPLE_TYPE", "DIRECTION",
  "MOVE_OPERATOR", "UMINUS", "$accept", "program", "program_block",
  "func_decl", "func_call", "param_list", "argument_list",
  "sentence_group", "sentence_list", "sentence", "statement", "print",
  "type_info", "var_decl", "initialization", "assign", "if_clause",
  "while_clause", "cell_literal", "cell_literal_list", "var_ref",
  "arithmetic_operand", "arithmetic_expr", YY_NULLPTR
    };
    return yy_sname[yysymbol];
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

#if YYDEBUG
    // Execute LAC once. We don't care if it is successful, we
    // only do it for the sake of debugging output.
    if (!yyparser_.yy_lac_established_)
      yyparser_.yy_lac_check_ (yyla_.kind ());
#endif

    for (int yyx = 0; yyx < YYNTOKENS; ++yyx)
      {
        symbol_kind_type yysym = YY_CAST (symbol_kind_type, yyx);
        if (yysym != symbol_kind::S_YYerror
            && yysym != symbol_kind::S_YYUNDEF
            && yyparser_.yy_lac_check_ (yysym))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
      }
    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }




  bool
  parser::yy_lac_check_ (symbol_kind_type yytoken) const
  {
    // Logically, the yylac_stack's lifetime is confined to this function.
    // Clear it, to get rid of potential left-overs from previous call.
    yylac_stack_.clear ();
    // Reduce until we encounter a shift and thereby accept the token.
#if YYDEBUG
    YYCDEBUG << "LAC: checking lookahead " << symbol_name (yytoken) << ':';
#endif
    std::ptrdiff_t lac_top = 0;
    while (true)
      {
        state_type top_state = (yylac_stack_.empty ()
                                ? yystack_[lac_top].state
                                : yylac_stack_.back ());
        int yyrule = yypact_[+top_state];
        if (yy_pact_value_is_default_ (yyrule)
            || (yyrule += yytoken) < 0 || yylast_ < yyrule
            || yycheck_[yyrule] != yytoken)
          {
            // Use the default action.
            yyrule = yydefact_[+top_state];
            if (yyrule == 0)
              {
                YYCDEBUG << " Err\n";
                return false;
              }
          }
        else
          {
            // Use the action from yytable.
            yyrule = yytable_[yyrule];
            if (yy_table_value_is_error_ (yyrule))
              {
                YYCDEBUG << " Err\n";
                return false;
              }
            if (0 < yyrule)
              {
                YYCDEBUG << " S" << yyrule << '\n';
                return true;
              }
            yyrule = -yyrule;
          }
        // By now we know we have to simulate a reduce.
        YYCDEBUG << " R" << yyrule - 1;
        // Pop the corresponding number of values from the stack.
        {
          std::ptrdiff_t yylen = yyr2_[yyrule];
          // First pop from the LAC stack as many tokens as possible.
          std::ptrdiff_t lac_size = std::ptrdiff_t (yylac_stack_.size ());
          if (yylen < lac_size)
            {
              yylac_stack_.resize (std::size_t (lac_size - yylen));
              yylen = 0;
            }
          else if (lac_size)
            {
              yylac_stack_.clear ();
              yylen -= lac_size;
            }
          // Only afterwards look at the main stack.
          // We simulate popping elements by incrementing lac_top.
          lac_top += yylen;
        }
        // Keep top_state in sync with the updated stack.
        top_state = (yylac_stack_.empty ()
                     ? yystack_[lac_top].state
                     : yylac_stack_.back ());
        // Push the resulting state of the reduction.
        state_type state = yy_lr_goto_state_ (top_state, yyr1_[yyrule]);
        YYCDEBUG << " G" << int (state);
        yylac_stack_.push_back (state);
      }
  }

  // Establish the initial context if no initial context currently exists.
  bool
  parser::yy_lac_establish_ (symbol_kind_type yytoken)
  {
    /* Establish the initial context for the current lookahead if no initial
       context is currently established.

       We define a context as a snapshot of the parser stacks.  We define
       the initial context for a lookahead as the context in which the
       parser initially examines that lookahead in order to select a
       syntactic action.  Thus, if the lookahead eventually proves
       syntactically unacceptable (possibly in a later context reached via a
       series of reductions), the initial context can be used to determine
       the exact set of tokens that would be syntactically acceptable in the
       lookahead's place.  Moreover, it is the context after which any
       further semantic actions would be erroneous because they would be
       determined by a syntactically unacceptable token.

       yy_lac_establish_ should be invoked when a reduction is about to be
       performed in an inconsistent state (which, for the purposes of LAC,
       includes consistent states that don't know they're consistent because
       their default reductions have been disabled).

       For parse.lac=full, the implementation of yy_lac_establish_ is as
       follows.  If no initial context is currently established for the
       current lookahead, then check if that lookahead can eventually be
       shifted if syntactic actions continue from the current context.  */
    if (yy_lac_established_)
      return true;
    else
      {
#if YYDEBUG
        YYCDEBUG << "LAC: initial context established for "
                 << symbol_name (yytoken) << '\n';
#endif
        yy_lac_established_ = true;
        return yy_lac_check_ (yytoken);
      }
  }

  // Discard any previous initial lookahead context.
  void
  parser::yy_lac_discard_ (const char* event)
  {
   /* Discard any previous initial lookahead context because of Event,
      which may be a lookahead change or an invalidation of the currently
      established initial context for the current lookahead.

      The most common example of a lookahead change is a shift.  An example
      of both cases is syntax error recovery.  That is, a syntax error
      occurs when the lookahead is syntactically erroneous for the
      currently established initial context, so error recovery manipulates
      the parser stacks to try to find a new initial context in which the
      current lookahead is syntactically acceptable.  If it fails to find
      such a context, it discards the lookahead.  */
    if (yy_lac_established_)
      {
        YYCDEBUG << "LAC: initial context discarded due to "
                 << event << '\n';
        yy_lac_established_ = false;
      }
  }


  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
         In the first two cases, it might appear that the current syntax
         error should have been detected in the previous state when
         yy_lac_check was invoked.  However, at that time, there might
         have been a different syntax error that discarded a different
         initial context during error recovery, leaving behind the
         current lookahead.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -93;

  const signed char parser::yytable_ninf_ = -33;

  const short
  parser::yypact_[] =
  {
      72,    -9,   235,   235,   235,   196,    17,   -13,    14,    41,
     106,     5,   119,    36,   -93,   -93,   -93,   -93,    59,    61,
      72,   -93,    72,    62,   -93,    76,   101,   -93,   -93,    72,
      72,   -93,   102,   -93,   322,   -93,   -93,   -93,   -93,   -93,
      99,   -93,    -4,   267,    76,   124,   107,   -93,   235,   -93,
     235,    17,   -93,   235,   235,   -93,   -93,   -93,   -93,   -93,
     -93,   203,   -93,   -93,   228,   235,   235,   235,   235,   235,
     235,   235,   235,   -93,   -93,    81,   -93,   -93,   -93,   235,
      26,   278,   289,   131,   300,   253,   -93,   322,   -93,   322,
      51,    51,   -93,   -93,   -93,   333,   333,   333,   -93,    28,
     322,    33,   -93,   123,   123,   -93,   -93,   235,   -93,   235,
     123,    26,   167,   -93,   -93,   311,   322,   -93,   -93,    65,
     135,     6,   109,   138,   -93,   -93,   -93,   -93,   -93,   -93
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    51,    53,    54,    35,    30,     0,     0,
       0,    57,     0,     0,    31,     0,    39,    29,    28,     0,
       0,    55,    56,    58,    27,    26,    56,    64,    65,    66,
       0,    50,     0,     0,     0,     0,     0,    47,     0,    45,
       0,     0,    34,     0,     0,     1,     2,     4,     5,    25,
      37,     0,     6,     7,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    71,    48,     0,    67,    38,    10,    16,
      13,     0,     0,     0,     0,     0,    41,    40,    43,    42,
      60,    59,    61,    62,    63,    68,    69,    70,    49,     0,
      15,     0,    12,     0,     0,    36,    33,     0,     9,     0,
       0,     0,     0,    46,    44,     0,    14,     8,    11,     0,
       0,     0,     0,     0,    52,    18,    17,    19,    20,    21
  };

  const signed char
  parser::yypgoto_[] =
  {
     -93,   -93,    66,   -93,   -93,   -93,   -93,   -92,    94,   -38,
     -93,   -93,     3,   -75,   -93,   -93,    29,    58,   -93,   -93,
       0,   -93,    -1
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,    18,    19,    20,    21,   101,    99,   113,   120,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    42,
      36,    33,    34
  };

  const short
  parser::yytable_[] =
  {
      32,    37,    38,    39,    43,   102,    74,     1,    35,    44,
       2,     3,   114,    45,     4,     5,   -24,    51,   117,    75,
      32,     6,    32,   -32,     7,    60,     9,    10,    11,    32,
      32,    12,    13,    14,    15,    16,   118,    17,   108,    11,
      46,     6,    47,   110,    77,    54,    16,    81,    11,    82,
      48,   109,    84,    85,    83,    16,   111,    67,    68,    55,
      87,    56,    69,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    -3,     1,   121,   125,     2,     3,   100,    59,
       4,     5,    35,   121,   121,   121,    57,     6,    58,   -32,
       7,     8,     9,    10,    11,    62,    63,    12,    13,    14,
      15,    16,    13,    17,    61,    64,   115,    49,   116,    73,
       1,    98,    32,     2,     3,    50,    80,     4,     5,   -22,
      52,    32,    32,    32,     6,    78,   -32,     7,    53,     9,
      10,    11,   112,    79,    12,    13,    14,    15,    16,     1,
      17,   122,     2,     3,   105,   126,     4,     5,   -23,     0,
     122,   122,   122,     6,     0,   -32,     7,     0,     9,    10,
      11,     0,     0,    12,    13,    14,    15,    16,   119,    17,
     123,     2,     3,     0,     0,     4,     5,     0,     0,   123,
     123,   123,     6,     0,   -32,     7,     0,     9,    10,    11,
       0,     0,    12,    13,    14,    15,    16,    40,    17,     0,
       2,     3,     0,     0,     4,     5,     0,     2,     3,     0,
       0,     4,     5,     0,     7,   127,   128,   129,     0,     0,
       0,     7,    13,    14,    15,     0,    41,    86,     0,    13,
      14,    15,     2,     3,     0,     0,     4,     5,     0,     2,
       3,     0,     0,     4,     5,     0,     7,     0,     0,     0,
       0,     0,    88,     7,    13,    14,    15,    65,    66,    67,
      68,    13,    14,    15,    69,    70,    71,    72,     0,     0,
       0,    65,    66,    67,    68,     0,   107,    76,    69,    70,
      71,    72,    65,    66,    67,    68,     0,     0,   103,    69,
      70,    71,    72,    65,    66,    67,    68,     0,     0,   104,
      69,    70,    71,    72,    65,    66,    67,    68,     0,     0,
     106,    69,    70,    71,    72,    65,    66,    67,    68,     0,
       0,   124,    69,    70,    71,    72,    65,    66,    67,    68,
       0,     0,     0,    69,    70,    71,    72,    65,    66,    67,
      68,     0,     0,     0,    69
  };

  const signed char
  parser::yycheck_[] =
  {
       0,     2,     3,     4,     5,    80,    10,     1,    17,     6,
       4,     5,   104,    26,     8,     9,    10,    12,   110,    23,
      20,    15,    22,    17,    18,    25,    20,    21,    22,    29,
      30,    25,    26,    27,    28,    29,   111,    31,    10,    22,
      26,    15,     1,    10,    44,     9,    29,    48,    22,    50,
       9,    23,    53,    54,    51,    29,    23,     6,     7,     0,
      61,     0,    11,    64,    65,    66,    67,    68,    69,    70,
      71,    72,     0,     1,   112,    10,     4,     5,    79,    17,
       8,     9,    17,   121,   122,   123,    20,    15,    22,    17,
      18,    19,    20,    21,    22,    29,    30,    25,    26,    27,
      28,    29,    26,    31,     3,     3,   107,     1,   109,    10,
       1,    30,   112,     4,     5,     9,     9,     8,     9,    10,
       1,   121,   122,   123,    15,     1,    17,    18,     9,    20,
      21,    22,     9,     9,    25,    26,    27,    28,    29,     1,
      31,   112,     4,     5,    13,    10,     8,     9,    10,    -1,
     121,   122,   123,    15,    -1,    17,    18,    -1,    20,    21,
      22,    -1,    -1,    25,    26,    27,    28,    29,     1,    31,
     112,     4,     5,    -1,    -1,     8,     9,    -1,    -1,   121,
     122,   123,    15,    -1,    17,    18,    -1,    20,    21,    22,
      -1,    -1,    25,    26,    27,    28,    29,     1,    31,    -1,
       4,     5,    -1,    -1,     8,     9,    -1,     4,     5,    -1,
      -1,     8,     9,    -1,    18,   121,   122,   123,    -1,    -1,
      -1,    18,    26,    27,    28,    -1,    30,    24,    -1,    26,
      27,    28,     4,     5,    -1,    -1,     8,     9,    -1,     4,
       5,    -1,    -1,     8,     9,    -1,    18,    -1,    -1,    -1,
      -1,    -1,    24,    18,    26,    27,    28,     4,     5,     6,
       7,    26,    27,    28,    11,    12,    13,    14,    -1,    -1,
      -1,     4,     5,     6,     7,    -1,    23,    10,    11,    12,
      13,    14,     4,     5,     6,     7,    -1,    -1,    10,    11,
      12,    13,    14,     4,     5,     6,     7,    -1,    -1,    10,
      11,    12,    13,    14,     4,     5,     6,     7,    -1,    -1,
      10,    11,    12,    13,    14,     4,     5,     6,     7,    -1,
      -1,    10,    11,    12,    13,    14,     4,     5,     6,     7,
      -1,    -1,    -1,    11,    12,    13,    14,     4,     5,     6,
       7,    -1,    -1,    -1,    11
  };

  const signed char
  parser::yystos_[] =
  {
       0,     1,     4,     5,     8,     9,    15,    18,    19,    20,
      21,    22,    25,    26,    27,    28,    29,    31,    34,    35,
      36,    37,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    53,    54,    55,    17,    53,    55,    55,    55,
       1,    30,    52,    55,    45,    26,    26,     1,     9,     1,
       9,    12,     1,     9,     9,     0,     0,    35,    35,    17,
      53,     3,    35,    35,     3,     4,     5,     6,     7,    11,
      12,    13,    14,    10,    10,    23,    10,    53,     1,     9,
       9,    55,    55,    45,    55,    55,    24,    55,    24,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    30,    39,
      55,    38,    46,    10,    10,    13,    10,    23,    10,    23,
      10,    23,     9,    40,    40,    55,    55,    40,    46,     1,
      41,    42,    49,    50,    10,    10,    10,    41,    41,    41
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    33,    34,    35,    35,    35,    35,    35,    36,    37,
      37,    38,    38,    38,    39,    39,    39,    40,    40,    41,
      41,    41,    41,    41,    41,    42,    42,    43,    43,    43,
      43,    43,    43,    44,    44,    45,    45,    46,    46,    47,
      47,    47,    48,    48,    49,    49,    50,    50,    51,    52,
      52,    53,    53,    54,    54,    54,    54,    54,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,     0,     2,     2,     2,     2,     6,     5,
       3,     3,     1,     0,     3,     1,     0,     3,     3,     2,
       2,     2,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     0,     4,     2,     1,     4,     2,     3,     1,
       3,     3,     3,     3,     5,     2,     5,     2,     3,     3,
       1,     1,     6,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     2,     2,     2,     3,     3,     3,
       3,     3
  };




#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    88,    88,    91,    92,    97,   102,   107,   114,   122,
     127,   131,   136,   141,   145,   150,   155,   159,   163,   167,
     172,   177,   182,   187,   192,   200,   204,   208,   209,   210,
     211,   212,   213,   217,   222,   226,   235,   243,   248,   257,
     258,   263,   272,   277,   286,   291,   295,   300,   304,   311,
     316,   324,   328,   334,   335,   336,   337,   338,   342,   346,
     351,   356,   361,   366,   371,   376,   381,   386,   391,   396,
     401,   406
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 2234 "grammar.tab.cc"

#line 408 "grammar.yy"


void yy::parser::error (const location_type& l, const std::string& m){
    std::cerr << l << ": " << m << '\n';
}
