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
#define firstChair(L) (L).firstChair
#define lastChair(L) (L).lastChair
#define nextChair(L) (L).nextChair

#define numChair(L) (L).noKursi

typedef char* String;

typedef struct film *almtFilm;
typedef struct date *almtDate;
typedef struct schedule *almtSchedule;
typedef struct studio *almtStudio;
typedef struct person *almtPerson;
typedef struct chair *almtChair;

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

typedef struct studio {
	String studioName;
	int jmlhPenonton;
	almtChair firstChair;
	almtChair lastChair;
} Studio;

typedef struct person {
	String name;
	int age;
	almtPerson nextPerson;
} Person;

typedef struct chair {
	String noKursi;
	Person person;
	almtChair nextChair;
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
} List;

/*NRLL Date*/
int isDateEmpty(List L);
void createDate(List *L);
void addDateFirst(List *L, int year, int month, int date);
void addDateAfter(Date *prev, List *L, int year, int month, int date);
void addDateLast(List *L, int year, int month, int date);
void printDate(List L);

/*NRLL Film*/
int isFilmEmpty(Date D);
void addFilmFirst(Date *D, String title, String category, int age, int duration);
void addFilmAfter(Film *prev, Date *D, String title, String category, int age, int duration);
void addFilmLast(Date *D, String title, String category, int age, int duration);
void printFilm(Date D);

/*NRLL Schedule*/
int isScheduleEmpty(Film F);
void addScheduleFirst(Film *F, int hour, int minute);
void addScheduleAfter(Schedule *prev, Film *F, int hour, int minute);
void addScheduleLast(Film *F, int hour, int minute);
void printSchedule(Film F);

/*NRLL Stduio*/
int isStudi0Empty(Schedule S);
void addStudio(Schedule *S, String name);
void addStudio(Schedule *S, String name);
void printStudio(Schedule S);

/*NRLL Chair*/
void printChair(Studio St);

/*System*/
void gotoxy(int x,int y);
void setcolor (unsigned short color);

/*Queue*/
int isLocketEmpty(lockets L, int index);
int totalNode(lockets L, int index);
void addPerson(lockets L, String name, int age, int index);
void delPerson(lockets L, int index);

/*Menu*/
void tampilanMenuUtama(lockets queue, List *L);
void pilihTampilanMenuUtama(lockets queue, List *L);
void tampilanMenuPilihLoket(lockets queue, List *L);
void pilihTampilanMenuPilihLoket(lockets queue, List *L);
void printListFilm(lockets queue, List *L);
void printChairStudio(lockets queue, List *L);
void tampilkanPilihanMenuEditFilm(Film F);
void tampilkanPilihanMenuEditJamTayang(Film F);

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


//
int CountSchedule(Film f);
/*Menghitung semua schedule yang tersedia dalam sebuah film dan 
mengembalikan jumlah total schedule yang tersedia tersebut*/

int totalFilm(Date *D);
/*Menghitung semua film yang tersedia di sebuah tanggal yang ditentukan*/

int ScheduleIsAvailable(List L, time_t time, int duration, int hour, int minute, String studio);
/*Mengecek apakah dijam tersebut masih ada film yang ditayangkan atau tidak*/

int isStudioExist(Date D, String studioName);
/*Mengecek apakah sebuah studio dengan nama yang ditentukan sudah ada atau tidak*/

/*Main Proses*/
void CreateFilm(List *L);
/*Proses untuk membuat sebuah film*/

void EditFilm(List *L);
/*Prosese untuk mengedit film yang sudah ada*/
