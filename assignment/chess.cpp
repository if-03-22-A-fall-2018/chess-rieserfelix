/*----------------------------------------------------------
 *				HTBLA-Leonding / Klasse: 2AHDV
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			chess.c
 * Author:			P. Bauer
 * Due Date:		November 03, 2010
 * ----------------------------------------------------------
 * Description:
 * Implementation of basic chess functions.
 * ----------------------------------------------------------
 */
 #include "chess.h"
 #include <stdio.h>

  bool is_square_ok (File file, Rank rank)
  {
    return (file >= 'a' && file <= 'h') && (rank >= 1 && rank <= 8);
  }

  int nr (Rank rank)
  {
    return 0;
  }

  int nf (File file)
  {
    return 0;
  }

  bool is_move_from_base_line (enum PieceColor color, Rank rank)
  {
    return false;
  }

  bool is_piece (struct ChessPiece pc, enum PieceColor color, enum PieceType type)
  {
     return (pc.color == color && pc.type == type);
  }

  void init_chess_board (ChessBoard chess_board)
  {
     for(int i = 0; i < 8; i++)
     {
       for(int a = 0; a < 8; a++)
       {
         chess_board[i][a].is_occupied = false;
         chess_board[i][a].piece.type = NoPiece;
       }
     }
  }

  struct ChessSquare *get_square (ChessBoard chess_board, File file, Rank rank)
  {


    if (is_square_ok(file,rank))
    {
        return &chess_board[rank - 1][file - 'a'];
    }
    else
    {
      return 0;
    }
  }

  bool is_square_occupied (ChessBoard chess_board, File file, Rank rank)
  {
    return chess_board[rank - 1][file - 'a'].is_occupied;
  }

  bool add_piece (ChessBoard chess_board, File file, Rank rank, struct ChessPiece piece)
  {
    if (is_square_ok(file, rank) && (!is_square_occupied(chess_board, file, rank)))
    {
      chess_board[rank -1][file - 'a'].is_occupied = true;
      chess_board[rank -1][file - 'a'].piece = piece;
      return true;
    }
    else
    {
      return false;
    }
  }

  struct ChessPiece get_piece (ChessBoard chess_board, File file, Rank rank)
  {
    struct ChessPiece piece;
    piece.type = NoPiece;

    if (is_square_ok(file,rank) && is_square_occupied(chess_board, file, rank))
   {
      return chess_board[rank - 1][file - 'a'].piece;
   }

    else
    {
      return piece;
    }
  }

  void setup_chess_board (ChessBoard chess_board)
  {

  }

  bool remove_piece (ChessBoard chess_board, File file, Rank rank)
  {
    return false;
  }

  bool squares_share_file (File file1, Rank rank1, File file2, Rank rank2)
  {
    return false;
  }

  bool squares_share_rank (File file1, Rank rank1, File file2, Rank rank2)
  {
    return false;
  }

  bool squares_share_diagonal (File file1, Rank rank1, File file2, Rank rank2)
  {
    return false;
  }

  bool squares_share_knights_move (File file1, Rank rank1, File file2, Rank rank2)
  {
    return false;
  }

  bool squares_share_pawns_move (enum PieceColor color, enum MoveType move, File file1, Rank rank1, File file2, Rank rank2)
  {
    return false;
  }

  bool squares_share_queens_move (File file1, Rank rank1, File file2, Rank rank2)
  {
    return false;
  }

  bool squares_share_kings_move (File file1, Rank rank1, File file2, Rank rank2)
  {
    return false;
 }
