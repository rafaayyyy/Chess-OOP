# Chess-OOP

This is a complete two-player Chess game implemented in C++ using
object-oriented programming. The game includes the following features:

***Board Initialization***

-   The Chess board is initialized with all pieces in their starting
    positions.

***Board Display***

-   The current state of the board is displayed in the form of an 8x8
    grid.

***Player Input***
-   Players can select a piece to move by inputting its coordinates on
    the board.

-   Players can also make moves by clicking on the desired piece and
    then clicking on the destination square.

***Move Validation***

-   The game validates that the selected piece belongs to the player and
    that the move is a legal move for that piece.

-   The game also checks if the move puts the player\'s own king in
    check.

***Board Update***

-   If the move is valid, the game updates the board with the new piece
    positions.

***Turn Change***

-   After a player moves a piece, the turn changes to the other player.

***Piece Classes***

-   All Chess pieces are implemented as classes with their own header
    files.

-   The following classes are defined: King, Queen, Rook, Bishop,
    Knight, and Pawn.

***Highlight Possible Moves***

-   The game highlights all possible moves for a selected piece.

***Game Save***

-   The game can be saved with its current state.

***Game Load***

-   Players can load a saved game to either start a new game or resume a
    saved game.

***Undo/Redo Move***

-   Players can undo or redo moves that have been made in the current
    game.

***Replay Moves***

-   Players can replay all moves that have been made up to the current
    point to get context.

***Check Detection***

-   The game detects if a player\'s king is in check.

***Self-Check Detection***

-   The game detects if a player\'s move would put their own king in
    check.

***Checkmate Detection***

-   The game detects if a player\'s king is in checkmate, meaning there
    is no legal move that can be made to get out of check.

***Stalemate Detection***

-   The game detects if a player is in stalemate, meaning they have no
    legal moves available but their king is not in check.

***Castling***

-   The game allows for castling, a special move where the king moves
    two squares towards a rook and the rook moves to the other side of
    the king.

***Pawn Promotion***

-   If a pawn reaches the other side of the board, it can be promoted to
    a queen, rook, bishop, or knight.

Overall, this Chess game implementation in C++ and it provides a complete Chess experience.
