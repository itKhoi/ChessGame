ChessGame: ChessGame.c ChessGame.h Board.h Board.o Move.o AI.o
	gcc -ansi -std=c99 ChessGame.c Board.o Move.o AI.o -o ChessGame

clean:
	rm -f khoi
	rm -f *.tar.gz
	rm -f ChessGame
	rm -f *.o
	rm -f BoardTest MoveTest

test: BoardTest MoveTest ChessGameTest #FileIOTest 

Board.o: Board.c Board.h
	gcc -c -ansi -std=c99 -Wall Board.c -o Board.o

BoardTest: Board.c Board.h
	gcc -ansi -std=c99 -Wall Board.c -DDEBUG -o BoardTest

Move.o: Move.c Move.h Board.h Board.c
	gcc -c -ansi -std=c99 -Wall Move.c -o Move.o

MoveTest: Move.c Move.h Board.h Board.o
	gcc -ansi -std=c99 -Wall Move.c Board.o -DDEBUG -o MoveTest
ChessGamek.o: ChessGame.c ChessGame.h Board.h Board.c
	gcc -ansi -std=c99 -Wall -c ChessGame.c -o ChessGame.o
ChessGameTest: ChessGame.c ChessGame.h Board.h Board.o Move.o Move.h
	gcc -ansi -std=c99 -Wall ChessGame.c Board.o Move.o -o khoi

FileIO.o: FileIO.c FileIO.h Board.h
	gcc -c -ansi -std=c99 -Wall FileIO.c -o FileIO.o

FileIOTest: FileIO.c FileIO.h Board.h Board.o
	gcc -ansi -std=c99 -Wall -DDEBUG FileIO.c Board.o -o FileIOTest
	
AI.o: AI.c AI.h Board.h Move.h ChessGame.h
	gcc -c -ansi -std=c99 -Wall AI.c -o AI.o

tar: ChessGame
	rm -f *.tar
	tar -czvf Chess_Alpha.src.tar.gz AI.c AI.h Board.c Board.h ChessGame.c ChessGame.h FileIO.c FileIO.h GUI.c GUI.h Main.c Makefile Move.c Move.h Makefile_2 SpecialFeatures.c SpecialFeatures.h ../README.md


