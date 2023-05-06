#include"Cursor.c"

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
	gotoxy(50, 8); printf("1. Memasukkan Antrian");
	gotoxy(50, 9); printf("2. Pesan Tiket");
	gotoxy(50, 10); printf("3. Lihat Jadwal");
	gotoxy(50, 11); printf("4. About");
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
			system("cls");
			tampilanMenuPilihLoket2(queue, L);
			break;
		case 3: 
			printListFilm(queue, L);
			break;
		case 4: break;
		case 5: exit(1); break;
	}
	tampilanMenuUtama(queue, L);
}

void tampilanMenuPilihLoket2(lockets queue, List *L) {
	gotoxy(55, 5); printf("Pilih Antrian");
	gotoxy(50, 8); printf("1. Loket 1 : %d antrian", totalNodePerson(queue, 0));
	gotoxy(50, 9); printf("2. Loket 2 : %d antrian", totalNodePerson(queue, 1));
	gotoxy(50, 10); printf("3. Kembali");
	pilihTampilanMenuPilihLoket2(queue, L);
}

void pilihTampilanMenuPilihLoket2(lockets queue, List *L) {
	int age;
	String name;
	int pilih = Cursor(3, 48, 8);
	switch(pilih) {
		case 1: 
			system("cls");
			gotoxy(55, 5); printf("Loket 1");
			serveQueue(queue, L, pilih-1);
			break;
		case 2: 
			system("cls");
			gotoxy(55, 5); printf("Loket 2");
			serveQueue(queue, L, pilih - 1);
			break;
		case 3:
			system("cls");
			tampilanMenuUtama(queue, L);
			break;
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
	
	if(date != NULL) {

		Film *film = firstFilm(*date);
		Schedule *schedule;
		struct tm *time;

		int i, j, k;
	//	print box
		gotoxy(30, 1); printf("����������������������������ͺ LIST FILM ����������������������������ͻ");
		for(i = 2; i < 26; i++) {
		    gotoxy(30, i); printf("�                                                                     �");
		}
		gotoxy(30, 26); printf("���������������������������������������������������������������������ͼ");
	
		//print list box
		for(j = 0; j <= (CountFilm(date) - 1) * 6; j += 6) {
			schedule = firstSchedule(*film);
			gotoxy(31, 2 + j); printf(" �������ͺ FILM #%d �����������������������������������������������ͻ ", (j / 6) + 1);
			for(i = 0; i < 4;i++) {
				gotoxy(31, 3 + j + i); printf(" �                                                                 � ");
			}
			gotoxy(35, 3 + j) ;printf("%s", filmTitle(*film));
			gotoxy(35, 4 + j) ; printf("%s", filmCategory(*film));
			gotoxy(93, 3 + j); printf("%d", filmAge(*film));
			gotoxy(93, 4 + j); printf("%d", filmDuration(*film));
			
		
			for(k = 0; k < CountSchedule(*film) * 6;k += 8) {
				time = localtime(&schedule->time);
				gotoxy(35 + k, 6 + j); printf("%d.%d", time->tm_hour, time->tm_min);
				schedule = nextSchedule(*schedule);
			}
			gotoxy(31, 7 + j); printf(" �����������������������������������������������������������������ͼ ");
			film = nextFilm(*film);
		}
	
		char cursor;
	
		do{
			cursor=getch();
		} while(cursor != 27);
	
		system("cls");
		tampilanMenuUtama(queue, L);
	} else {
		printf("\nDate Kosong");
	}
}	

void printChairStudio(lockets queue, List *L) {
	Date *date = firstDate(*L);
	Film *film = firstFilm(*date);
	Schedule *schedule = firstSchedule(*film);
	struct tm *time = localtime(&schedule->time);
	
	int i,j,k;
	
	for(i = 0; i < 22;i += 3) {
		gotoxy(20, 4 + i); printf("���������������������������������������������������");
	}
	
	for(i = 0; i < 21; i += 3) {
		for(j = 0; j <= 1; j++) {		
			gotoxy(20, 5+i+j); printf("�    �    �    �    �    �    �    �    �    �    �");
		}
	}
	int bantu = 1;
	for(i = 0; i <= 45; i += 5) {
		for(j = 0; j < 21; j += 3) {
			if(j == 0){
				gotoxy(22 + i, 6+j); printf("G%d", bantu);
			}else if(j == 3){
				gotoxy(22 + i, 6+j); printf("F%d", bantu);
			}else if(j == 6){
				gotoxy(22 + i, 6+j); printf("E%d", bantu);
			}else if(j == 9){
				gotoxy(22 + i, 6+j); printf("D%d", bantu);
			}else if(j == 12){
				gotoxy(22 + i, 6+j); printf("C%d", bantu);
			}else if(j == 15){
				gotoxy(22 + i, 6+j); printf("B%d", bantu);
			}else if(j == 18){
				gotoxy(22 + i, 6+j); printf("A%d", bantu);
			}
		}
			bantu++;
	}
	
	gotoxy(72, 4); printf("�������������ͺ PESAN TIKET �������������ͻ");
	for(i = 0; i < 20;i++) {
		gotoxy(72, 5 + i); printf("�                                         �");
	}
	
	if(date != NULL){
	gotoxy(74, 6); setcolor(15); printf("Film : %s", filmTitle(*film));
	gotoxy(74,7); printf("Durasi : %d Menit", filmDuration(*film));
	gotoxy(74, 8); printf("Usia : %d", filmAge(*film));
	gotoxy(74,9); printf("Jam Tayang : %d.%d", time->tm_hour, time->tm_min);
	gotoxy(74, 10); printf("Studio : %s", film->firstSchedule->nextStudio->studioName);
	}
	gotoxy(74, 15); printf("Pilih kursi");
	gotoxy(74, 16); printf("Tekan enter untuk memilih kursi");
	gotoxy(72, 25); printf("�����������������������������������������ͼ");
	gotoxy(74,21); setcolor(4); printf("A1 : Kursi Tidak Tersedia");
	gotoxy(74,22); setcolor(2); printf("A1 : Kursi Tersedia");
	gotoxy(74,23); setcolor(13); printf("� : Pointer Memilih Kursi");
	CursorPilihKursi();
	system("pause");
	system("cls");
}

void printPilihFilmDanJadwal(lockets queue, List *L) {
		Date *date = firstDate(*L);
		int i, j, k;
		int x = 14, y = 3;
	//	print box
	gotoxy(10, 1); printf("�����������������������ͺ JADWAL FILM HARI INI ����������������������ͻ");
	for(i = 2; i < 26; i++) {
	    gotoxy(10, i); printf("�                                                                     �");
	}
	gotoxy(10, 26); printf("���������������������������������������������������������������������ͼ");
	
	//print list box
	if(date != NULL){
		
		Film *film = firstFilm(*date);
		Schedule *schedule;
		struct tm *time;
		
		for(j = 0; j <= (CountFilm(date)-1) * 6 ; j += 6) {
		schedule = firstSchedule(*film);
		gotoxy(11, 2 + j); printf(" �������ͺ FILM #%d �����������������������������������������������ͻ ", (j / 6) + 1);
		for(i = 0; i < 4;i++) {
			gotoxy(11, 3 + j + i); printf(" �                                                                 � ");
		}
		gotoxy(15, 3 + j) ;printf("%s", filmTitle(*film));
		gotoxy(15, 4 + j); printf("%s", filmCategory(*film));
		gotoxy(67, 3 + j); printf("%d", filmAge(*film));
		gotoxy(67, 4 + j); printf("%d", filmDuration(*film ));
		for(k = 0; k < (CountSchedule(*film)) * 6; k += 8) {
			time = localtime(&schedule->time);
			gotoxy(15 + k, 6 + j); printf("%d.%d", time->tm_hour, time->tm_min);
			schedule = nextSchedule(*schedule);
		}
		gotoxy(11, 7 + j); printf(" �����������������������������������������������������������������ͼ ");
		film = nextFilm(*film);
	}
	}
	
//		gotoxy(72, 3); printf("�������������ͺ PESAN TIKET �������������ͻ");
//	for(i = 0; i < 20;i++) {
//		gotoxy(72, 4 + i); printf("�                                         �");
//	}
	
//	gotoxy(74, 5); setcolor(15); printf("Film : Pirattes of the carribean");
//	gotoxy(74,6); printf("Durasi : 168");
//	gotoxy(74, 7); printf("Usia : 18");
//	gotoxy(74,8); printf("Jam Tayang : 17.24");
//	gotoxy(74, 9); printf("Studio : 4");
//	gotoxy(74, 14); printf("Pilih kursi");
//	gotoxy(74, 15); printf("Tekan enter untuk memilih kursi");
//	gotoxy(72, 24); printf("�����������������������������������������ͼ");
	
	cursorPilihFilm(CountFilm(L->firstDate), &x, &y);
	y += 3;
	cursorPilihJadwal(CountSchedule(*L->firstDate->firstFilm), &x, &y);
}

void tampilkanPilihanMenuEditJamTayang(Film F) {
	if(firstSchedule(F) != NULL) {
		Schedule *bantu;
		struct tm *time;
		int i;
		bantu = firstSchedule(F);
	
		gotoxy(55, 5); printf("Ingin Mengubah Jam Tayang mana ? ");
		for(i = 0; i < CountSchedule(F); i++) {
			time = localtime(&bantu->time);
			gotoxy(50, 8 + i); printf("%d. %d.%d", i + 1,time->tm_hour, time->tm_min);
			bantu = nextSchedule(*bantu);
		}
	} else {
		gotoxy(55, 5); printf("Jam Tayang Kosong!!!");
	}
}

void tampilkanPilihanMenuEditFilm(Film F) {
	gotoxy(55, 5); printf("Ingin mengubah apa ? ");
	gotoxy(50, 8); printf("1. Judul");
	gotoxy(50, 9); printf("2. Kategori");
	gotoxy(50, 10); printf("3. Umur");
	gotoxy(50, 11); printf("4. Durasi");
	if(firstSchedule(F) != NULL) gotoxy(50, 12); printf("5. Jam tayang"); 
}
//
//void pilihTampilanMenuEditFilm(Film *F, int jumlahPilihan) {
//	String tempString = (String) malloc(sizeof(char *));
//	int tempNumber;
//	int i;
//	Schedule *schedule;
//	
//	switch(Cursor(jumlahPilihan, 48, 8)) {
//		case 1:
//			printf("Masukan Judul Baru : "); scanf(" %[^\n]", tempString);
//			filmTitle(*F) = tempString;
//			break;
//		case 2:
//			printf("Masukan kategori baru : "); scanf(" %[^\n]", tempString);
//			filmCategory(*F) = tempString;
//			break;
//		case 3: 
//			printf("Masukan umur baru : "); scanf("%d", &tempNumber);
//			filmAge(*F) = tempNumber;
//			break;
//		case 4:
//			printf("Masukan durasi baru : "); scanf("%d", &tempNumber);
//			filmDuration(*F) = tempNumber;
//			break;
//		case 5:
//			schedule = firstSchedule(*F);
//			tampilkanPilihanMenuEditJamTayang(*F);
//
//			for(i = 0; i < Cursor(CountSchedule(*F), 48, 8) - 1; i++) {
//				schedule = nextSchedule(*F);
//			}
//			time = localtime(&schedule->time);
//			printf("Masukan Jam Tayang : "); scanf("%d", &tempNumber);
//			time->tm_hour = tempNumber;
//			printf("Masuka Meni Tayang : "); scanf("%d", &tempNumber);
//			time->tm_min = tempNumber;
//			schedule->time = mktime(time);
//			break;
//	}
//}
//

