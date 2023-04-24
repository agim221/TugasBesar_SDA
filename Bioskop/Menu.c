#include"MainProses.c"

COORD coord={0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void setcolor (unsigned short color)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,color);
}

void tampilanMenuUtama(lockets queue, List *L) {
	gotoxy(55, 5); printf("Header");
	gotoxy(50, 8); printf("1. Pesan Tiket");
	gotoxy(50, 9); printf("2. Lihat Jadwal");
	gotoxy(50, 10); printf("3. About");
	gotoxy(50, 11); printf("4. Test");
	gotoxy(50, 12); printf("5. Exit"); 
	pilihTampilanMenuUtama(queue, L);
}

void pilihTampilanMenuUtama(lockets queue, List *L) {
	switch(Cursor(5, 48, 8)) {
		case 1: 
			system("cls");
			tampilanMenuPilihLoket(queue, L);
			break;
		case 2: 
			printListFilm(queue, L);
			break;
		case 3: break;
		case 4: break;
		case 5: break;
	}
}

void tampilanMenuPilihLoket(lockets queue, List *L) {
	gotoxy(55, 5); printf("Pilih Antrian");
	gotoxy(50, 8); printf("1. Loket 1 : %d antrian", totalNodePerson(queue, 0));
	gotoxy(50, 9); printf("2. Loket 2 : %d antrian", totalNodePerson(queue, 1));
	gotoxy(50, 10); printf("3. Kembali");
	pilihTampilanMenuPilihLoket(queue, L);
}

void pilihTampilanMenuPilihLoket(lockets queue, List *L) {
	int age;
	String name;
	int pilih = Cursor(3, 48, 8);
	switch(pilih) {
		case 1: 
			system("cls");
			gotoxy(55, 5); printf("Loket 1");
			addPerson(queue , name, age, pilih - 1);
			break;
		case 2: 
			system("cls");
			gotoxy(55, 5); printf("Loket 2");
			addPerson(queue , name, age, pilih - 1);
			break;
		case 3:
			system("cls");
			tampilanMenuUtama(queue, L);
			break;
	}
}

void printListFilm(lockets queue, List *L) { 
	Date *date = firstDate(*L);
	Film *film = firstFilm(*date);
	Schedule *schedule;
	struct tm *time;

	int i, j, k;
	//	print box
	gotoxy(30, 1); printf("ษออออออออออออออออออออออออออออบ LIST FILM บออออออออออออออออออออออออออออป");
	for(i = 2; i < 26; i++) {
	    gotoxy(30, i); printf("บ                                                                     บ");
	}
	gotoxy(30, 26); printf("ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
	
	//print list box
	for(j = 0; j <= (totalFilm(date) - 1) * 6; j += 6) {
		schedule = firstSchedule(*film);
		gotoxy(31, 2 + j); printf(" ษอออออออบ FILM #%d บอออออออออออออออออออออออออออออออออออออออออออออออป ", (j / 6) + 1);
		for(i = 0; i < 4;i++) {
			gotoxy(31, 3 + j + i); printf(" บ                                                                 บ ");
		}
		gotoxy(35, 3 + j) ;printf("%s", filmTitle(*film));
		gotoxy(35, 4 + j) ; printf("%s", filmCategory(*film));
		gotoxy(93, 3 + j); printf("%d", filmAge(*film));
		gotoxy(93, 4 + j); printf("%d", filmDuration(*film));
		
		
		for(k = 0; k <= CountSchedule(*film) * 6;k += 8) {
			time = localtime(&schedule->time);
			gotoxy(35 + k, 6 + j); printf("%d.%d", time->tm_hour, time->tm_min);
			schedule = nextSchedule(*schedule);
		}
		gotoxy(31, 7 + j); printf(" ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ ");
		film = nextFilm(*film);
	}
	
	char cursor;
	
	do{
		cursor=getch();
	} while(cursor != 27);
	
	system("cls");
	tampilanMenuUtama(queue, L);
}
//
//void printChair(lockets queue, List *L) {
//	int i,j,k;
//	
//	for(i = 0; i < 22;i += 3) {
//		gotoxy(20, 4 + i); printf("ฮออออฮออออฮออออฮออออฮออออฮออออฮออออฮออออฮออออฮออออฮ");
//	}
//	
//	for(i = 0; i < 21; i += 3) {
//		for(j = 0; j <= 1; j++) {		
//			gotoxy(20, 5+i+j); printf("บ    บ    บ    บ    บ    บ    บ    บ    บ    บ    บ");
//		}
//	}
//	
//	for(i = 0; i <= 45; i += 5) {
//		for(j = 0; j < 21; j += 3) {
//			gotoxy(22 + i, 6+j); printf("A1");
//		}
//	}
//	
//	gotoxy(72, 4); printf("ษอออออออออออออบ PESAN TIKET บอออออออออออออป");
//	for(i = 0; i < 20;i++) {
//		gotoxy(72, 5 + i); printf("บ                                         บ");
//	}
//	
//	gotoxy(74, 6); setcolor(15); printf("Film : Pirattes of the carribean");
//	gotoxy(74,7); printf("Durasi : 168");
//	gotoxy(74, 8); printf("Usia : 18");
//	gotoxy(74,9); printf("Jam Tayang : 17.24");
//	gotoxy(74, 10); printf("Studio : 4");
//	gotoxy(74, 15); printf("Pilih kursi");
//	gotoxy(74, 16); printf("Tekan enter untuk memilih kursi");
//	gotoxy(72, 25); printf("ศอออออออออออออออออออออออออออออออออออออออออผ");
//	gotoxy(74,21); setcolor(4); printf("A1 : Kursi Tidak Tersedia");
//	gotoxy(74,22); setcolor(2); printf("A1 : Kursi Tersedia");
//	gotoxy(74,23); setcolor(13); printf("Û : Pointer Memilih Kursi");
//	CursorPilihKursi();
//}
//
//void printPilihFilmDanJadwal() {
//		int i, j, k;
//		int x = 14, y = 3;
//	//	print box
//	gotoxy(10, 1); printf("ษอออออออออออออออออออออออบ JADWAL FILM HARI INI บออออออออออออออออออออออป");
//	for(i = 2; i < 26; i++) {
//	    gotoxy(10, i); printf("บ                                                                     บ");
//	}
//	gotoxy(10, 26); printf("ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
//	
//	//print list box
//	for(j = 0; j <= 18; j += 6) {
//		gotoxy(11, 2 + j); printf(" ษอออออออบ FILM #%d บอออออออออออออออออออออออออออออออออออออออออออออออป ", (j / 6) + 1);
//		for(i = 0; i < 4;i++) {
//			gotoxy(11, 3 + j + i); printf(" บ                                                                 บ ");
//		}
//		gotoxy(15, 3 + j) ;printf("Pirates of the carribean");
//		gotoxy(67, 3 + j); printf("18+");
//		gotoxy(67, 4 + j); printf("168");
//		for(k = 0; k <= 24;k += 8) {
//			gotoxy(15 + k, 6 + j); printf("17.00");
//		}
//		gotoxy(11, 7 + j); printf(" ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ ");
//	}
//	
//		gotoxy(72, 3); printf("ษอออออออออออออบ PESAN TIKET บอออออออออออออป");
//	for(i = 0; i < 20;i++) {
//		gotoxy(72, 4 + i); printf("บ                                         บ");
//	}
//	
//	gotoxy(74, 5); setcolor(15); printf("Film : Pirattes of the carribean");
//	gotoxy(74,6); printf("Durasi : 168");
//	gotoxy(74, 7); printf("Usia : 18");
//	gotoxy(74,8); printf("Jam Tayang : 17.24");
//	gotoxy(74, 9); printf("Studio : 4");
//	gotoxy(74, 14); printf("Pilih kursi");
//	gotoxy(74, 15); printf("Tekan enter untuk memilih kursi");
//	gotoxy(72, 24); printf("ศอออออออออออออออออออออออออออออออออออออออออผ");
//	
//	cursorPilihFilm(4, &x, &y);
//	y += 3;
//	cursorPilihJadwal(4, &x, &y);
//}

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
	gotoxy(*x,*y); printf("ฏ");
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
				gotoxy(*x,*y); printf("ฏ");
			}
			else
			{
				gotoxy(*x,*y); printf(" ");
				Pilih++;
				*y += 6;
				gotoxy(*x,*y); printf("ฏ");
			}
		}

		if(cursor == 72)
		{
			if(Pilih-1 == 0)
			{
				gotoxy(*x,*y); printf(" ");
				*y=21;
				Pilih= 4;
				gotoxy(*x,*y); printf("ฏ");
			}
			else
			{
				gotoxy(*x,*y); printf(" ");
				Pilih --;
				*y -= 6;
				gotoxy(*x,*y); printf("ฏ");
			}
		}
		gotoxy(0, 0); printf("%d", Pilih);
	}while(cursor != 13);

	return Pilih;
}

int cursorPilihJadwal(int opsi, int *x, int *y) {
	int Pilih=1;
	char cursor;
	gotoxy(*x,*y); printf("ฏ");

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
				gotoxy(*x,*y); printf("ฏ");
			}
			else
			{
				gotoxy(*x,*y); printf(" ");
				Pilih++;
				*x += 8;
				gotoxy(*x,*y); printf("ฏ");
			}
		}

		if(cursor == 75)
		{
			if(Pilih-1 == 0)
			{
				gotoxy(*x,*y); printf(" ");
				*x=38;
				Pilih= 4;
				gotoxy(*x ,*y); printf("ฏ");
			}
			else
			{
				gotoxy(*x, *y); printf(" ");
				Pilih --;
				*x -= 8;
				gotoxy(*x,*y); printf("ฏ");
			}
		}
	}while(cursor != 13);

	return Pilih;
}
