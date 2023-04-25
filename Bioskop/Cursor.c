#include"MainProses.c"

int Cursor(int BanyakPilihan,int x,int y)
{
	int Pilih=1,ysel=(BanyakPilihan+y-1)-y;
	char cursor;
	gotoxy(x,y); printf("%c",62);

	do
	{
		cursor=getch();
		
		if(cursor == 80)
		{
			if(Pilih+1 > BanyakPilihan)
			{
				gotoxy(x,y); printf(" ");
				y=y-ysel;
				Pilih=1;
				gotoxy(x,y); printf("%c",62);
			}
			else
			{
				gotoxy(x,y); printf(" ");
				Pilih ++;
				y++;
				gotoxy(x,y); printf("%c",62);
			}
		}

		if(cursor == 72)
		{
			if(Pilih-1 == 0)
			{
				gotoxy(x,y); printf(" ");
				y=y+ysel;
				Pilih=BanyakPilihan;
				gotoxy(x,y); printf("%c",62);
			}
			else
			{
				gotoxy(x,y); printf(" ");
				Pilih --;
				y --;
				gotoxy(x,y); printf("%c",62);
			}
		}
		gotoxy(0, 0); printf("%d", cursor);
	}while(cursor != 13);

	return Pilih;
}

int CursorPilihKursi() {
	int pilih = 1;
	int x = 24, y = 5;
	char cursor;
	gotoxy(x,y); setcolor(13); printf("Û");

	do
	{
		cursor=getch();
		
		if(cursor == 80) {
			if(pilih + 10 > 70) {
				gotoxy(x, y); printf(" ");
				pilih = pilih - 60;
				y = 5;
				gotoxy(x, y); printf("Û");
			} else {
				gotoxy(x, y); printf(" ");
				pilih = pilih + 10;
				y += 3;
				gotoxy(x, y); printf("Û");
			}
		}

		if(cursor == 72) {
			if((pilih - 20) < 0) {
				gotoxy(x, y); printf(" ");
				pilih = pilih + 60;
				y = 23;
				gotoxy(x, y); printf("Û");
			} else {
				gotoxy(x, y); printf(" ");
				pilih = pilih - 10;
				y -= 3;
				gotoxy(x, y); printf("Û");
			}
		}
		
		if(cursor == 75) {
			gotoxy(x, y); printf(" ");
			if((pilih - 1) % 10 == 0) {
				pilih = pilih + 9;
				x = x + 45;
				gotoxy(x, y); printf("Û");
			} else {
				pilih--;
				x -= 5;
				gotoxy(x, y); printf("Û");
			}
		}
		
		if(cursor == 77) {
			gotoxy(x, y); printf(" ");
			if(pilih % 10 == 0) {
				pilih = pilih - 9;
				x = x - 45;
				gotoxy(x, y); printf("Û");
			} else {
			  	pilih++;
			  	x += 5;
			  	gotoxy(x, y); printf("Û");
			}
		}
	}while(cursor != 13);

	return pilih;
}

int cursorPilihFilm(int opsi, int *x, int *y) {
	int Pilih=1;
	char cursor;
	gotoxy(*x,*y); printf("¯");
	do
	{
		cursor=getch();
		
		if(cursor == 80)
		{
			if(Pilih+1 > opsi)
			{
				gotoxy(*x,*y); printf(" ");
				*y= 3;
				Pilih=1;
				gotoxy(*x,*y); printf("¯");
			}
			else
			{
				gotoxy(*x,*y); printf(" ");
				Pilih++;
				*y += 6;
				gotoxy(*x,*y); printf("¯");
			}
		}

		if(cursor == 72)
		{
			if(Pilih-1 == 0)
			{
				gotoxy(*x,*y); printf(" ");
				*y=21;
				Pilih= 4;
				gotoxy(*x,*y); printf("¯");
			}
			else
			{
				gotoxy(*x,*y); printf(" ");
				Pilih --;
				*y -= 6;
				gotoxy(*x,*y); printf("¯");
			}
		}
		gotoxy(0, 0); printf("%d", Pilih);
	}while(cursor != 13);

	return Pilih;
}

int cursorPilihJadwal(int opsi, int *x, int *y) {
	int Pilih=1;
	char cursor;
	gotoxy(*x,*y); printf("¯");

	do
	{
		cursor=getch();
		
		if(cursor == 77)
		{
			if(Pilih+1 > opsi)
			{
				gotoxy(*x,*y); printf(" ");
				*x= 14;
				Pilih=1;
				gotoxy(*x,*y); printf("¯");
			}
			else
			{
				gotoxy(*x,*y); printf(" ");
				Pilih++;
				*x += 8;
				gotoxy(*x,*y); printf("¯");
			}
		}

		if(cursor == 75)
		{
			if(Pilih-1 == 0)
			{
				gotoxy(*x,*y); printf(" ");
				*x=38;
				Pilih= 4;
				gotoxy(*x ,*y); printf("¯");
			}
			else
			{
				gotoxy(*x, *y); printf(" ");
				Pilih --;
				*x -= 8;
				gotoxy(*x,*y); printf("¯");
			}
		}
	}while(cursor != 13);

	return Pilih;
}
