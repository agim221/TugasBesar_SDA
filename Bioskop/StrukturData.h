/*
	File 				: StrukturData.h
	Nama Program 		: Polban Cinema (Bioskop)
	Tanggal Dibuat		: 9 Mei 2023
	Author				: Muhamad Agim, Septyana Agustina, Thoriq Muhammad Fadhli
	Versi				: 1.0
	Deskripsi Program	: Membuat program simulasi pelayanan bioskop.
*/

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <time.h>

#define locketName(L, I) (L[I]).loket
#define age(L) (L).age
#define namePerson(L) (L).name
#define nextPerson(L) (L).nextPerson
#define firstPerson(L, I) (L[I]).firstPerson
#define lastPerson(L, I) (L[I]).lastPerson

#define nextStudio(L) (L).nextStudio

#define firstFilm(L) (L).firstFilm
#define lastFilm(L) (L).lastFilm
#define filmTitle(L) (L).judul
#define filmDuration(L) (L).durasi
#define filmCategory(L) (L).kategori
#define filmPrice(L) (L).harga
#define filmAge(L) (L).umur
#define nextFilm(L) (L).nextFilm

#define firstDate(L) (L).firstDate
#define lastDate(L) (L).lastDate
#define nextDate(L) (L).nextDate

#define nextSchedule(L) (L).nextSchedule
#define firstSchedule(L) (L).firstSchedule
#define lastSchedule(L) (L).lastSchedule

#define jmlhPenonton(L) (L).jmlhPenonton
#define studioName(L) (L).studioName
//#define firstChair(L) (L).firstChair
//#define lastChair(L) (L).lastChair
//#define nextChair(L) (L).nextChair

#define numChair(L) (L).noKursi

typedef char* String;

typedef struct film *almtFilm;
typedef struct date *almtDate;
typedef struct schedule *almtSchedule;
typedef struct studio *almtStudio;
typedef struct person *almtPerson;
typedef struct chair *almtChair;
typedef struct kursi *almtKursi;
typedef struct transaction *almtTransaction;

typedef struct date {
	time_t time;
	almtFilm nextFilm;
	almtDate nextDate;
	almtFilm firstFilm;
	almtFilm lastFilm;	
} Date;

typedef struct film {
	String judul;
	int durasi;
	String kategori;
	int umur;
	double harga;
	almtFilm nextFilm;
	almtSchedule firstSchedule;
	almtSchedule lastSchedule;
	almtSchedule nextSchedule;
} Film;

typedef struct schedule {
	time_t time;
	almtSchedule nextSchedule;
	almtStudio nextStudio;
} Schedule;

typedef struct kursi {
	almtChair A[10], B[10], C[10], D[10], E[10], F[10], G[10];
} Kursi;

typedef struct studio {
	String studioName;
	int jmlhPenonton;
	almtKursi Chair;
} Studio;

typedef struct person {
	String name;
	int age;
	almtPerson nextPerson;
} Person;

typedef struct chair {
	int status;
	int noKursi;
	char KodeKursi;
	Person person;
} Chair;

typedef struct loket {
	String loket;
	almtPerson firstPerson;
	almtPerson lastPerson;
} Loket;
typedef Loket lockets[2];

typedef struct {
	almtDate firstDate;
	almtDate lastDate;
	almtTransaction firstTransaction;
	almtTransaction lastTransaction;
} List;

struct tm *timeLocalStruct;
time_t timeLocalTime_t;

typedef struct transaction{
	almtChair chair;
	almtFilm film;
	char* waktuPembelian;
	almtTransaction nextTransaction;
} TransactionHistory;

/*Histori Transaksi*/
void addTransaction(List *L, Film *film, Chair *chair, Schedule *schedule);
void printTransaction(List *L, int jam, int menit);
int isTransactionEmpty(List *L);

/*NRLL Date*/
int isDateEmpty(List L);
void createDate(List *L);
void addDateFirst(List *L, int year, int month, int date);
void addDateAfter(Date *prev, List *L, int year, int month, int date);
void addDateLast(List *L, int year, int month, int date);
void delDateFirst(List *L);
void delDateFirst(List *L);
void delDateAfter(Date *prev, List *L) ;
void delDateLast(List *L);
void printDate(List L);

/*NRLL Film*/
int isFilmEmpty(Date D);
void addFilmFirst(Date *D, String title, String category, int age, int duration, double harga);
void addFilmAfter(Film *prev, Date *D, String title, String category, int age, int duration, double harga);
void addFilmLast(Date *D, String title, String category, int age, int duration, double harga);
void delFilmFirst(Date *D);
void delFilmAfter(Film *prev, Date *D);
void delFilmLast(Date *D);
void printFilm(Date D);

/*NRLL Schedule*/
int isScheduleEmpty(Film F);
void addScheduleFirst(Film *F, int hour, int minute);
void addScheduleAfter(Schedule *prev, Film *F, int hour, int minute);
void addScheduleLast(Film *F, int hour, int minute);
void delScheduleFirst(Film *F);
void delScheduleAfter(Schedule *prev, Film *F);
void delScheduleLast(Film *F);
void printSchedule(Film F);

/*NRLL Stduio*/
int isStudi0Empty(Schedule S);
void addStudio(Schedule *S, String name);
void delStudio(Schedule *S);
void printStudio(Schedule S);

/*NRLL Chair*/
void printChair(Studio St);

/*System*/
void gotoxy(int x,int y);
void setcolor (unsigned short color);

/*Queue*/
int isLocketEmpty(lockets L, int index);
int totalNode(lockets L, int index);
void addPerson(lockets L, int age, int index);
void delPerson(lockets L, int index);

/*Menu*/
void tampilanMenuUtama(lockets queue, List *L);
void tampilanMenuAdmin(lockets queue, List *L);
void pilihTampilanMenuUtama(lockets queue, List *L);
void pilihTampilanMenuAdmin(lockets queue, List *L);
void tampilanMenuPilihLoket2(lockets queue, List *);
void tampilanMenuPilihLoket(lockets queue, List *L);
void pilihTampilanMenuPilihLoket2(lockets queue, List *L);
void pilihTampilanMenuPilihLoket(lockets queue, List *L);
void printListFilm(lockets queue, List *L);
void printChairStudio(lockets queue, List *L, Film *film, Schedule *schedule, int index);
void tampilkanPilihanMenuEditFilm(Film F);
void tampilkanPilihanMenuEditJamTayang(Film F);
void tampilanTicket(Film *film, Schedule *schedule, Chair *ch, lockets queue, List *L, int index);
void tampilkanMenuPilihDelete(lockets queue, List *L);
void pilihTampilanMenuDelete(lockets queue, List *L);

void tampilkanPilihTimeLocal(lockets queue, List *L);
void pilihTampilanTimeLocal(lockets queue, List *L);
void tampilanAbout();

/*Local Time*/
void increaseTime(int minute);

/*Cursor*/
int Cursor(int BanyakPilihan, int x, int y);
int CursorPilihKursi();
int cursorPilihFilm(int opsi, int *x, int *y);
int cursorPilihJadwal(int opsi, int *x, int *y);

/*SEARCH*/
almtFilm SearchFilm(Date D,String name);
almtFilm GetFilm(List L, time_t time, String name);
/* Mencari apakah ada node Film dengan filmTitle = name */
/* Jika ada, mengirimkan address node tsb. */
/* Jika tidak ada, mengirimkan NULL */

almtDate SearchDate(List L, time_t time);
almtDate GetDate(List L, time_t time);
/* Mencari apakah ada node Date dengan Date->time = time */
/* Jika ada, mengirimkan address node tsb. */
/* Jika tidak ada, mengirimkan NULL */

almtSchedule SearchSchedule(Film F, time_t time);
almtSchedule GetSchedule(List L, time_t timeDate, String name,time_t timeFilm);
/* Mencari apakah ada node Schedule dengan Schedule->time = time */
/* Jika ada, mengirimkan address node tsb. */
/* Jika tidak ada, mengirimkan NULL */

almtSchedule SearchSchedulePrev(Film f, int hour, int minute);
/* Mencari apakah ada node Schedule dengan Schedule->time, menit dan jamnya sama */
/* Jika ada, mengirimkan address node tsb. */
/* Jika tidak ada, mengirimkan NULL */

almtStudio SearchStudio(Schedule S, String name);
almtStudio GetStudio(List L, time_t timeDate, String name, time_t timeFilm,String studioName);
/* Mencari apakah ada node Studio dengan studioName = name */
/* Jika ada, mengirimkan address node tsb. */
/* Jika tidak ada, mengirimkan NULL */

/*MANIPULATION FILE*/
void saveAllDate(Date date, FILE *fp);

//
int CountSchedule(Film f);
/*Menghitung semua schedule yang tersedia dalam sebuah film dan 
mengembalikan jumlah total schedule yang tersedia tersebut*/

int CountFilm(Date *D);
/*Menghitung semua film yang tersedia di sebuah tanggal yang ditentukan*/

int ScheduleIsAvailable(List L, Date date, String studioName, int duration, int hour, int minute);
//int ScheduleIsAvailable(List L, time_t time, int duration, int hour, int minute, String studio);
/*Mengecek apakah dijam tersebut masih ada film yang ditayangkan atau tidak*/

//int isStudioExist(List L, String studioName);
int isStudioExist(Film *film, String studioName);
/*Mengecek apakah sebuah studio dengan nama yang ditentukan sudah ada atau tidak*/

/*Main Proses*/
void CreateFilm(List *L);
/*Proses untuk membuat sebuah film*/

void EditFilm(List *L);
/*Prosese untuk mengedit film yang sudah ada*/

void printPilihFilmDanJadwal(lockets queue, List *L);

void serveQueue(lockets L, List *X, int index);
