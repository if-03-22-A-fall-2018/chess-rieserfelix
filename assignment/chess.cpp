#include <stdlib.h>
 #include "general.h"
 #include "chess.h"

 bool is_square_ok (File file, Rank rank){
   return file-'a'>=0 && file-'a'<=7 && rank-1>=0 && rank-1<=7;
 }
 bool is_piece (struct ChessPiece pc, enum PieceColor color, enum PieceType type){
   return color==pc.color && type==pc.type;
 }
 void init_chess_board (ChessBoard chess_board){
   for (int i = 0; i < 8; i++) {
     for (int j = 0; j < 8; j++) {
       chess_board[i][j].is_occupied=false;
     }
   }
 }
 struct ChessSquare* get_square (ChessBoard chess_board, File file, Rank rank){
   if(!is_square_ok(file,rank))
   {
     return 0;
   }

   return &chess_board[rank-1][file-'a'];
 }
 bool is_square_occupied (ChessBoard chess_board, File file, Rank rank){
    return chess_board[rank-1][file-'a'].is_occupied;
 }
 bool	add_piece (ChessBoard chess_board, File file, Rank rank, struct ChessPiece piece){
   if(!is_square_ok(file,rank)||chess_board[rank-1][file-'a'].is_occupied==true)
   {
     return false;
   }
   chess_board[rank-1][file-'a'].is_occupied=true;
   chess_board[rank-1][file-'a'].piece=piece;
   return true;
 }
 struct ChessPiece get_piece (ChessBoard chess_board, File file, Rank rank){
   if(!is_square_ok(file,rank)||chess_board[rank-1][file-'a'].is_occupied==false)
   {
     struct ChessPiece return_value;
     return_value.type=NoPiece;
     return return_value;
   }

   return chess_board[rank-1][file-'a'].piece;
 }
 void setup_chess_board (ChessBoard chess_board){
   struct ChessPiece white_pawn = {White, Pawn};
   struct ChessPiece white_rook = {White, Rook};
   struct ChessPiece white_knight = {White, Knight};
   struct ChessPiece white_bishop = {White, Bishop};
   struct ChessPiece white_queen = {White, Queen};
   struct ChessPiece white_king = {White, King};

   struct ChessPiece black_pawn = {Black, Pawn};
   struct ChessPiece black_rook = {Black, Rook};
   struct ChessPiece black_knight = {Black, Knight};
   struct ChessPiece black_bishop = {Black, Bishop};
   struct ChessPiece black_queen = {Black, Queen};
   struct ChessPiece black_king = {Black, King};

   init_chess_board(chess_board);

   for (int i = 'a'; i <= 'h'; i++) {
     add_piece(chess_board, i, 2, white_pawn);
     add_piece(chess_board, i, 7, black_pawn);
   }

   add_piece(chess_board, 'a', 1, white_rook);
   add_piece(chess_board, 'h', 1, white_rook);
   add_piece(chess_board, 'b', 1, white_knight);
   add_piece(chess_board, 'g', 1, white_knight);
   add_piece(chess_board, 'c', 1, white_bishop);
   add_piece(chess_board, 'f', 1, white_bishop);
   add_piece(chess_board, 'd', 1, white_queen);
   add_piece(chess_board, 'e', 1, white_king);

   add_piece(chess_board, 'a', 8, black_rook);
   add_piece(chess_board, 'h', 8, black_rook);
   add_piece(chess_board, 'b', 8, black_knight);
   add_piece(chess_board, 'g', 8, black_knight);
   add_piece(chess_board, 'c', 8, black_bishop);
   add_piece(chess_board, 'f', 8, black_bishop);
   add_piece(chess_board, 'd', 8, black_queen);
   add_piece(chess_board, 'e', 8, black_king);
 }
 bool remove_piece (ChessBoard chess_board, File file, Rank rank){
   if(!is_square_ok(file,rank)||chess_board[rank-1][file-'a'].is_occupied==false)
   {
     return false;
   }
   chess_board[rank-1][file-'a'].is_occupied=false;
   return true;
 }
 bool squares_share_file (File s1_f, Rank s1_r, File s2_f, Rank s2_r){
   return s1_f==s2_f && is_square_ok(s1_f,s1_r) && is_square_ok(s2_f,s2_r);
 }
 bool	squares_share_rank (File s1_f, Rank s1_r, File s2_f, Rank s2_r){
   return s1_r==s2_r && is_square_ok(s1_f,s1_r) && is_square_ok(s2_f,s2_r);
 }
 bool squares_share_diagonal (File s1_f, Rank s1_r, File s2_f, Rank s2_r){
   int file_sum;
   int rank_sum;

   file_sum=s1_f-s2_f;

   if(file_sum<0)
   {
     file_sum*=-1;
   }

   rank_sum=s1_r-s2_r;

   if(rank_sum<0)
   {
     rank_sum*=-1;
   }

   return rank_sum == file_sum && is_square_ok(s1_f,s1_r) && is_square_ok(s2_f,s2_r);
 }
 bool squares_share_knights_move (File s1_f, Rank s1_r, File s2_f, Rank s2_r){
   if(s1_r+2==s2_r&&s1_f+1==s2_f)
   {
     return true;
   }
   else if(s1_r+2==s2_r&&s1_f-1==s2_f)
   {
     return true;
   }
   else if(s1_r-2==s2_r&&s1_f+1==s2_f)
   {
     return true;
   }
   else if(s1_r-2==s2_r&&s1_f-1==s2_f)
   {
     return true;
   }
   else if(s1_r-1==s2_r&&s1_f+2==s2_f)
   {
     return true;
   }
   else if(s1_r+1==s2_r&&s1_f+2==s2_f)
   {
     return true;
   }
   else if(s1_r-1==s2_r&&s1_f-2==s2_f)
   {
     return true;
   }
   else if(s1_r+1==s2_r&&s1_f-2==s2_f)
   {
     return true;
   }
   return false;
 }
 bool squares_share_pawns_move (enum PieceColor color, enum MoveType move, File s1_f, Rank s1_r, File s2_f, Rank s2_r){

  if(move==NormalMove && color==White && s1_f==s2_f && s1_r+2 == s2_r && s1_r==2)
  {
    return true;
  }

  else if(move==NormalMove && color==White && s1_f==s2_f && s1_r+1 == s2_r && s1_r>1)
  {
    return true;
  }

  else if(move==CaptureMove && color==White && (s1_f==s2_f+1 || s1_f==s2_f-1) && s1_r+1 == s2_r)
  {
    return true;
  }

  else if(move==NormalMove && color==Black && s1_f==s2_f && s1_r-2 == s2_r && s1_r==7)
  {
    return true;
  }

  else if(move==NormalMove && color==Black && s1_f==s2_f && s1_r-1 == s2_r && s1_r<8)
  {
    return true;
  }

  else if(move==CaptureMove && color==Black && (s1_f==s2_f+1 || s1_f==s2_f-1) && s1_r-1 == s2_r)
  {
    return true;
  }

  return false;
}
 bool 	squares_share_queens_move (File s1_f, Rank s1_r, File s2_f, Rank s2_r){
   return squares_share_rank(s1_f, s1_r, s2_f, s2_r) || squares_share_file (s1_f, s1_r, s2_f, s2_r) || squares_share_diagonal(s1_f, s1_r, s2_f, s2_r);
 }
 bool 	squares_share_kings_move (File s1_f, Rank s1_r, File s2_f, Rank s2_r){
   if(s1_f+1==s2_f && s1_r==s2_r)
   {
     return true;
   }
   else if(s1_f-1==s2_f && s1_r==s2_r)
   {
     return true;
   }
   else if(s1_f==s2_f && s1_r+1==s2_r)
   {
     return true;
   }
   else if(s1_f==s2_f && s1_r-1==s2_r)
   {
     return true;
   }
   else if(s1_f+1==s2_f && s1_r+1==s2_r)
   {
     return true;
   }
   else if(s1_f-1==s2_f && s1_r-1==s2_r)
   {
     return true;
   }
   else if(s1_f+1==s2_f && s1_r-1==s2_r)
   {
     return true;
   }
   else if(s1_f-1==s2_f && s1_r+1==s2_r)
   {
     return true;
   }
   return false;
 }
