/*
	File 				: Menu.c
	Nama Program 		: Polban Cinema (Bioskop)
	Tanggal Dibuat		: 9 Mei 2023
	Author				: Muhamad Agim, Septyana Agustina, Thoriq Muhammad Fadhli
	Versi				: 1.0
	Deskripsi Program	: Membuat program simulasi pelayanan bioskop.
*/

#include"Cursor.c"

void tampilanAbout(){
	gotoxy(50, 5); printf("About");
	gotoxy(15, 7); printf("1. Pilih loket antrian untuk memesan tiket");
	gotoxy(15, 8); printf("2. Tunggu sampai dilayani oleh kasir");
	gotoxy(15, 9); printf("3. Jika sudah dilayani pilih film sesuai umur penonton");
	gotoxy(15, 10); printf("4. Jika penonton dibawah umur yang ditentukan maka tidak bisa menonton film tersebut");
	gotoxy(15, 11); printf("5. Jika sudah memilih film lalu pilih jam tayang yang ingin ditonton");
	gotoxy(15, 12); printf("6. Lalu pilih kursi untuk menonton film tersebut sesuai yang diinginkan");
	gotoxy(15, 13); printf("7. Jika kursi berwarna hijau berarti kosong, jika merah berarti sudah terisi");
	gotoxy(15, 14); printf("8. Setiap pemilihan film, jam tayang, dan kursi menggunakan cursor keyboard");
	gotoxy(15,15); printf("lalu click enter jika ingin memilih pilihan tersebut\n\n");
}

void tampilanHistoriTransaksi(List *L, lockets queue){
	gotoxy(55, 5); printf("Riwayat Transaksi");
	
	struct tm *time = localtime(&L->firstTransaction->film->firstSchedule->time);
	int jam = time->tm_hour;
	int menit = time->tm_min;
	
	if(L->firstTransaction != NULL){
		gotoxy(50, 9); printTransaction(L, jam, menit);
		char key;
			do{
				key=getch();
			} while(key != 27);
		system("cls");
		tampilanMenuAdmin(queue, L);
	}else{
		gotoxy(0, 8); printf("No.");
		gotoxy(10, 8); printf("Judul Film");
		gotoxy(30, 8); printf("Studio");
		gotoxy(40, 8); printf("Kursi");
		gotoxy(50, 8); printf("Waktu Tayang");
		gotoxy(70, 8); printf("Waktu Pembelian");
		gotoxy(90, 8); printf("Harga Tiket");
		gotoxy(50, 10); printf("Belum ada riwayat pembelian.");
		gotoxy(50, 11); system("pause");
		system("cls");
	}
}

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


void tampilanTicket(Film *film, Schedule *schedule, Chair *ch, lockets queue, List *L, int index){
	struct tm *time = localtime(&schedule->time);
	char keyboard;
		gotoxy(55, 5); printf("Konfirmasi Pembelian : ");
		gotoxy(50, 8); printf("Judul Film : %s", film->judul);
		gotoxy(50, 9); printf("Kursi : %c%d", ch->KodeKursi, ch->noKursi+1);
		gotoxy(50, 10); printf("Durasi : %d", film->durasi);
		gotoxy(50, 11); printf("Kategori : %s", film->kategori);
		gotoxy(50, 12); printf("Kategori Umur : %d", film->umur); 
		gotoxy(50, 13); printf("Harga Tiket : Rp. %.f", film->harga); 
		gotoxy(50, 14); printf("Yakin membeli tiket ? [y/n]"); keyboard = getch();
		
	if(keyboard != 121 || keyboard == 27){
		system("cls");
		ch->status = 0;
		tampilanMenuUtama(queue, L);
	}
	
	system("cls");
		gotoxy(55, 5); printf("Polban Cinema.ID");
		gotoxy(50, 6); printf("Terimakasih telah mempercayai kami.");
		gotoxy(50, 8); printf("Judul Film : %s", film->judul);
		gotoxy(50, 9); printf("Jam Tayang : %d:%d", time->tm_hour, time->tm_min);
		gotoxy(50, 10); printf("Studio : %s", schedule->nextStudio->studioName);
		gotoxy(50, 11); printf("Kursi : %c%d", ch->KodeKursi, ch->noKursi+1);
		gotoxy(50, 12); printf("Harga Tiket : Rp. %.f", film->harga);
		gotoxy(50, 13); system("pause");
		delPerson(queue, index);
	system("cls");
}

void tampilanMenuUtama(lockets queue, List *L) {
	gotoxy(55, 5); printf("Polban Cinema");
	gotoxy(50, 8); printf("1. Masuk Antrian");
	gotoxy(50, 9); printf("2. Pesan Tiket");
	gotoxy(50, 10); printf("3. Lihat Jadwal");
	gotoxy(50, 11); printf("4. About");
	gotoxy(50, 12); printf("5. Pindah ke UI Admin");
	gotoxy(50, 13); printf("6. Exit"); 
	gotoxy(40, 20); printf("(C)Copyright. All right reserved. Kelompok B1");
	pilihTampilanMenuUtama(queue, L);
}

void tampilanMenuAdmin(lockets queue, List *L) {
	gotoxy(55, 5); printf("Polban Cinema Admin");
	gotoxy(50, 8); printf("1. Lihat Riwayat Transaksi");
	gotoxy(50, 9); printf("2. Lihat Jadwal");
	gotoxy(50, 10); printf("3. Buat Film");
	gotoxy(50, 11); printf("4. Ubah Film");
	gotoxy(50, 12); printf("5. Hapus Film");
	gotoxy(50, 13); printf("6. Ubah Waktu Lokal");
	gotoxy(50, 14); printf("7. Pindah ke UI Customer"); 
	gotoxy(50, 15); printf("8. Exit");
	gotoxy(40, 20); printf("(C)Copyright. All right reserved. Kelompok B1");
	pilihTampilanMenuAdmin(queue, L);
}

void pilihTampilanMenuUtama(lockets queue, List *L) {
	switch(Cursor(6, 48, 8)) {
		case 1: 
			system("cls");
			tampilanMenuPilihLoket(queue, L);
			system("cls");
			break;
		case 2: 
			system("cls");
			if(timeLocalStruct->tm_hour <= 10 || timeLocalStruct->tm_hour >= 20) {
				system("cls");
				gotoxy(45, 7); printf("Bioskop Masih tutup!!!");
				gotoxy(0, 17);
				system("pause");
				break;
			}
			tampilanMenuPilihLoket2(queue, L);
			break;
		case 3: 
			system("cls");
			printListFilm(queue, L);
			system("pause");
			system("cls");
			break;
		case 4: 
			system("cls");
			tampilanAbout();
			system("pause");
			system("cls");
			break;
		case 5: 
			system("cls");
			tampilanMenuAdmin(queue, L);
			break;
		case 6:
			saveAllData(*L);
			exit(1); 
			break;
	}
	system("cls");
	tampilanMenuUtama(queue, L);
}

void pilihTampilanMenuAdmin(lockets queue, List *L) {
switch(Cursor(8, 48, 8)) {
		case 1: 
			system("cls");
			tampilanHistoriTransaksi(L, queue);
			system("pause");
			system("cls");
		break;
		case 2: 
			system("cls");
			printListFilm(queue, L);
			system("pause");
			system("cls");
			break;
		case 3: 
			system("cls");
			CreateFilm(L);
			system("cls");
			break;
		case 4: 
			system("cls");
			EditFilm(L);
			system("cls");
			break;
		case 5:
		 	system("cls");
		 	tampilkanMenuPilihDelete(queue, L);
		 	break;
		case 6:
			system("cls");
			tampilkanPilihTimeLocal(queue, L);
			break;
		case 7:
			system("cls");
			tampilanMenuUtama(queue, L);
			break;
		case 8: system("cls");exit(1); break;
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
			system("cls");
			gotoxy(55, 5); printf("Masukan umur : "); scanf("%d", &age);
			if(CountPerson(queue, 1) < CountPerson(queue, 0) && CountPerson(queue, 0) != 0){
				gotoxy(30, 7); printf("Antrian loket 2 lebih sedikit.. Ditambahkan ke antrian loket 2..\n");
				system("pause");
				addPerson(queue , age, pilih);
			} else {
				addPerson(queue , age, pilih - 1);
			}
			break;
		case 2: 
			system("cls");
			gotoxy(55, 5); printf("Loket 2");
			system("cls");
			gotoxy(55, 5); printf("Masukan umur : "); scanf("%d", &age);
			if(CountPerson(queue, 0) < CountPerson(queue, 1) && CountPerson(queue, 1) != 0){
				gotoxy(30, 7); printf("Antrian loket 1 lebih sedikit.. Ditambahkan ke antrian loket 1..\n");
				system("pause");
				addPerson(queue , age, pilih - 2);
			} else {
				addPerson(queue , age, pilih - 1);
			}
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
		gotoxy(30, 1); printf("ษออออออออออออออออออออออออออออบ LIST FILM บออออออออออออออออออออออออออออป");
		for(i = 2; i < 26; i++) {
		    gotoxy(30, i); printf("บ                                                                     บ");
		}
		gotoxy(30, 26); printf("ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
	
		//print list box
		for(j = 0; j <= (CountFilm(date) - 1) * 6; j += 6) {
			schedule = firstSchedule(*film);
			gotoxy(31, 2 + j); printf(" ษอออออออบ FILM #%d บอออออออออออออออออออออออออออออออออออออออออออออออป ", (j / 6) + 1);
			for(i = 0; i < 4;i++) {
				gotoxy(31, 3 + j + i); printf(" บ                                                                 บ ");
			}
			gotoxy(35, 3 + j) ;printf("%s", filmTitle(*film));
			gotoxy(35, 4 + j) ; printf("%s", filmCategory(*film));
			gotoxy(85, 3 + j); printf("Umur : %d", filmAge(*film));
			gotoxy(85, 4 + j); printf("%d Menit", filmDuration(*film));
			
		
			for(k = 0; k < CountSchedule(*film) * 6;k += 8) {
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
	} else {
		printf("\nDate Kosong");
	}
}	

void printChairStudio(lockets queue, List *L, Film *film, Schedule *schedule, int index) {
	struct tm *time = localtime(&schedule->time);
	Kursi *kursis = schedule->nextStudio->Chair;
	
	int i,j,k;
	
	for(i = 0; i < 22;i += 3) {
		gotoxy(20, 4 + i); printf("ฮออออฮออออฮออออฮออออฮออออฮออออฮออออฮออออฮออออฮออออฮ");
	}
	
	for(i = 0; i < 21; i += 3) {
		for(j = 0; j <= 1; j++) {		
			gotoxy(20, 5+i+j); printf("บ    บ    บ    บ    บ    บ    บ    บ    บ    บ    บ");
		}
	}
	
	int bantu = 1;
	for(i = 0; i <= 45; i += 5) {
		for(j = 0; j < 21; j += 3) {
						if(j == 0){
							gotoxy(22 + i, 6+j); 	
							if(kursis->G[bantu-1]->status == 0){ 
									setcolor(2);
								}else{ 
									setcolor(4);
								} printf("G%d", bantu);
						}else if(j == 3){
							gotoxy(22 + i, 6+j); 
							if(kursis->F[bantu-1]->status == 0){ 
								setcolor(2);
								}else{ 
									setcolor(4);
								} printf("F%d", bantu);
						}else if(j == 6){
							gotoxy(22 + i, 6+j); 
							if(kursis->E[bantu-1]->status == 0){ 
								setcolor(2);
								}else{ 
									setcolor(4);
								} printf("E%d", bantu);
						}else if(j == 9){
							gotoxy(22 + i, 6+j); 
							if(kursis->D[bantu-1]->status == 0){ 
								setcolor(2);
								}else{ 
									setcolor(4);
								} printf("D%d", bantu);
						}else if(j == 12){
							gotoxy(22 + i, 6+j); 
							if(kursis->C[bantu-1]->status == 0){ 
								setcolor(2);
								}else{ 
									setcolor(4);
								} printf("C%d", bantu);
						}else if(j == 15){
							gotoxy(22 + i, 6+j); 
							if(kursis->B[bantu-1]->status == 0){ 
								setcolor(2);
								}else{ 
									setcolor(4);
								} printf("B%d", bantu);
						}else if(j == 18){
							gotoxy(22 + i, 6+j); 
							if(kursis->A[bantu-1]->status == 0){ 
								setcolor(2);
								}else{ 
									setcolor(4);
								} printf("A%d", bantu);
						}
		}
			bantu++;
	}
	
	gotoxy(72, 4); setcolor(15); printf("ษอออออออออออออบ PESAN TIKET บอออออออออออออป");
	for(i = 0; i < 20;i++) {
		setcolor(15); gotoxy(72, 5 + i); printf("บ                                         บ");
	}
	
	if(L->firstDate != NULL){
	gotoxy(74, 6); setcolor(15); printf("Film : %s", filmTitle(*film));
	gotoxy(74,7); printf("Durasi : %d Menit", filmDuration(*film));
	gotoxy(74, 8); printf("Usia : %d", filmAge(*film));
	gotoxy(74,9); printf("Jam Tayang : %d.%d", time->tm_hour, time->tm_min);
	gotoxy(74, 10); printf("Studio : %s", schedule->nextStudio->studioName);
	gotoxy(74, 15); printf("Pilih kursi");
	gotoxy(74, 16); printf("Tekan enter untuk memilih kursi");
	gotoxy(72, 25); setcolor(15); printf("ศอออออออออออออออออออออออออออออออออออออออออผ");
	gotoxy(74,21); setcolor(4); printf("A1 : Kursi Tidak Tersedia");
	gotoxy(74,22); setcolor(2); printf("A1 : Kursi Tersedia");
	gotoxy(74,23); setcolor(13); printf("Û : Pointer Memilih Kursi");
	int pilih = CursorPilihKursi();
	
	int nomor;
	char kode;
	system("cls");
	setcolor(15);

	if(pilih < 11){
			if(kursis->G[pilih-1]->status != 1){
				kursis->G[pilih-1]->status = 1;	
				kode = kursis->G[pilih-1]->KodeKursi = 'G';
				nomor = kursis->G[pilih-1]->noKursi = pilih - 1;
				tampilanTicket(film, schedule, kursis->G[pilih-1], queue, L, index);
				addTransaction(L, film, kursis->G[pilih-1], schedule);
			}else{                             
				system("cls");
				setcolor(15);
				puts("Kursi sudah dipilih silahkan pilih yang lain");
				system("pause");
				system("cls");
				printChairStudio(queue, L, film, schedule, index);
			}
		}else if(pilih < 21){
			if(kursis->F[pilih-11]->status != 1){
				kursis->F[pilih-11]->status = 1;	
				kode = kursis->F[pilih-11]->KodeKursi = 'F';
				nomor = kursis->F[pilih-11]->noKursi = pilih - 11;
				tampilanTicket(film, schedule, kursis->F[pilih-11], queue, L, index);
				addTransaction(L, film, kursis->F[pilih-11], schedule);
			}else{                             
				system("cls");
				setcolor(15);
				puts("Kursi sudah dipilih silahkan pilih yang lain");
				system("pause");
				system("cls");
				printChairStudio(queue, L, film, schedule, index);
			}
		}else if(pilih < 31){
			if(kursis->E[pilih-21]->status != 1){
				kursis->E[pilih-21]->status = 1;	
				kode = kursis->E[pilih-21]->KodeKursi = 'E';
				nomor = kursis->E[pilih-21]->noKursi = pilih - 21;
				tampilanTicket(film, schedule, kursis->E[pilih-21], queue, L, index);
				addTransaction(L, film, kursis->E[pilih-21], schedule);
			}else{                             
				system("cls");
				setcolor(15);
				puts("Kursi sudah dipilih silahkan pilih yang lain");
				system("pause");
				system("cls");
				printChairStudio(queue, L, film, schedule, index);
			}
		}else if(pilih < 41){
			if(kursis->D[pilih-31]->status != 1){
				kursis->D[pilih-31]->status = 1;	
				kode = kursis->D[pilih-31]->KodeKursi = 'D';
				nomor = kursis->D[pilih-31]->noKursi = pilih - 31;
				tampilanTicket(film, schedule, kursis->D[pilih-31], queue, L, index);
				addTransaction(L, film, kursis->D[pilih-31], schedule);
			}else{                             
				system("cls");
				setcolor(15);
				puts("Kursi sudah dipilih silahkan pilih yang lain");
				system("pause");
				system("cls");
				printChairStudio(queue, L, film, schedule, index);
			}
		}else if(pilih < 51){
			if(kursis->C[pilih-41]->status != 1){
				kursis->C[pilih-41]->status = 1;	
				kode = kursis->C[pilih-41]->KodeKursi = 'C';
				nomor = kursis->C[pilih-41]->noKursi = pilih - 41;
				tampilanTicket(film, schedule, kursis->C[pilih-41], queue, L, index);
				addTransaction(L, film, kursis->C[pilih-41], schedule);
			}else{                             
				system("cls");
				setcolor(15);
				puts("Kursi sudah dipilih silahkan pilih yang lain");
				system("pause");
				system("cls");
				printChairStudio(queue, L, film, schedule, index);
			}
		}else if(pilih < 61){
			if(kursis->B[pilih-51]->status != 1){
				kursis->B[pilih-51]->status = 1;	
				kode = kursis->B[pilih-51]->KodeKursi = 'B';
				nomor = kursis->B[pilih-51]->noKursi = pilih - 51;
				tampilanTicket(film, schedule, kursis->B[pilih-51], queue, L, index);
				addTransaction(L, film, kursis->B[pilih-51], schedule);
			}else{                             
				system("cls");
				setcolor(15);
				puts("Kursi sudah dipilih silahkan pilih yang lain");
				system("pause");
				system("cls");
				printChairStudio(queue, L, film, schedule, index);
			}
		}else if(pilih < 71){
			if(kursis->A[pilih-61]->status != 1){
				kursis->A[pilih-61]->status = 1;	
				kode = kursis->A[pilih-61]->KodeKursi = 'A';
				nomor = kursis->A[pilih-61]->noKursi = pilih - 61;
				tampilanTicket(film, schedule, kursis->A[pilih-61], queue, L, index);
				addTransaction(L, film, kursis->A[pilih-61], schedule);
			}else{                             
				system("cls");
				setcolor(15);
				puts("Kursi sudah dipilih silahkan pilih yang lain");
				system("pause");
				system("cls");
				printChairStudio(queue, L, film, schedule, index);
			}
		}
	}
}

void printPilihFilmDanJadwal(lockets queue, List *L) {
		Date *date = firstDate(*L);
		int i, j, k;
	//	print box
	gotoxy(10, 0); 	printf("%s", ctime(&timeLocalTime_t));
	gotoxy(10, 1); printf("ษอออออออออออออออออออออออบ JADWAL FILM HARI INI บออออออออออออออออออออออป");
	for(i = 2; i < 26; i++) {
	    gotoxy(10, i); printf("บ                                                                     บ");
	}
	gotoxy(10, 26); printf("ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
	
	//print list box
	if(date != NULL){
		
		Film *film = firstFilm(*date);
		Schedule *schedule;
		struct tm *time;
		
		for(j = 0; j <= (CountFilm(date)-1) * 6 ; j += 6) {
		schedule = firstSchedule(*film);
		gotoxy(11, 2 + j); printf(" ษอออออออบ FILM #%d บอออออออออออออออออออออออออออออออออออออออออออออออป ", (j / 6) + 1);
		for(i = 0; i < 4;i++) {
			gotoxy(11, 3 + j + i); printf(" บ                                                                 บ ");
		}
		gotoxy(15, 3 + j) ;printf("%s", filmTitle(*film));
		gotoxy(15, 4 + j); printf("%s", filmCategory(*film));
		gotoxy(67, 3 + j); printf("%d", filmAge(*film));
		gotoxy(67, 4 + j); printf("%d", filmDuration(*film ));
		for(k = 0; k < (CountSchedule(*film)) * 6; k += 8) {
			time = localtime(&schedule->time);
			if(time->tm_hour < timeLocalStruct->tm_hour || time->tm_hour == timeLocalStruct->tm_hour && time->tm_min <= timeLocalStruct->tm_min) setcolor(4);
			else setcolor(2);
			gotoxy(15 + k, 6 + j); printf("%d.%d", time->tm_hour, time->tm_min);
			schedule = nextSchedule(*schedule);
			setcolor(15);
		}
		gotoxy(11, 7 + j); printf(" ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ ");
		film = nextFilm(*film);
	}
	}
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

void tampilkanMenuPilihDelete(lockets queue, List *L) {
	gotoxy(55, 5); printf("Pilih opsi hapus ? ");
	gotoxy(50, 8); printf("1. Pilih Judul");
	gotoxy(50, 9); printf("2. Hapus Semua");
	gotoxy(50, 10); printf("3. Kembali");
	pilihTampilanMenuDelete(queue, L);
}

void pilihTampilanMenuDelete(lockets queue, List *L) {
	char pilih;
	switch(Cursor(3, 48, 8)) {
		case 1:
			system("cls");
			printAllFilm(*L);
			DeleteFilm(L);
			break;
		case 2:
			system("cls");
			printf("\nYakin ingin menghapus semua data ? (Y/N) ");
			scanf("%c", &pilih);
			if(pilih == 'Y') DeleteAllData(L);
			else tampilkanMenuPilihDelete(queue, L);
			system("cls");
			break;
		case 3:
			system("cls");
			tampilkanMenuPilihDelete(queue, L);
			break;
	}
	tampilanMenuAdmin(queue, L);
}


void tampilkanPilihTimeLocal(lockets queue, List *L) {
	gotoxy(55, 5); printf("Ingin menambahkan waktu berapa menit ? ");
	gotoxy(50, 8); printf("1. 10 menit");
	gotoxy(50, 9); printf("2. 20 menit");
	gotoxy(50, 10); printf("3. 30 menit");
	gotoxy(50, 11); printf("4. Lainnya");
	gotoxy(50, 12); printf("5. Kembali");
	pilihTampilanTimeLocal(queue, L);
}

void pilihTampilanTimeLocal(lockets queue, List *L) {
	char pilih;
	int menit;
	switch(Cursor(4, 48, 8)) {
		case 1:
			system("cls");
			increaseTime(10);
			break;
		case 2:
			system("cls");
			increaseTime(20);
			break;
		case 3:
			system("cls");
			increaseTime(30);
			break;
		case 4:
			system("cls");
			gotoxy(45, 5); printf("Masukan Menit : ");
			scanf("%d", &menit);
			increaseTime(menit);
			break;
		case 5: break;
	}
	tampilanMenuAdmin(queue, L);
}
