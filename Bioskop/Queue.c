#include"Menu.c"

int isDateEmpty(List L) {
	
	if(firstDate(L) == NULL) return 1;
	
	return 0;
}

int isLocketEmpty(lockets L, int index) {
	
	if(firstPerson(L, index) == NULL) return 1;
	
	return 0;
}

int totalNodePerson(lockets L, int index) {
	Person *bantu;
	bantu = firstPerson(L, index);
	int hasil = 0;
	
	while(bantu != NULL) {
		hasil++;
		bantu = nextPerson(*bantu);
	}
	
	return hasil;
}

void addPerson(lockets L, String name, int age, int index) {
	Person *baru;
	baru = (Person *) malloc(sizeof(Person));
	age(*baru) = age;
	namePerson(*baru) = name;
	
	if(baru != NULL) {
		if(isLocketEmpty(L, index)) {
			firstPerson(L, index) = baru;
			lastPerson(L, index) = baru;
		} else {
			nextPerson(*lastPerson(L, index)) = baru;
			lastPerson(L, index) = baru;
		}
		nextPerson(*baru) = NULL;
	} else {
		printf("\nMemori Penuh");
	}
}

void delPerson(lockets L, int index) {
	if(isLocketEmpty(L, index)) {
		printf("\nData Kosong\n");
	} else {
		Person *hapus;
		hapus = firstPerson(L, index);
		if(nextPerson(*hapus) == NULL) {
			firstPerson(L, index) = NULL;
			lastPerson(L, index) = NULL;
		} else {
			firstPerson(L, index) = nextPerson(*hapus); 
			nextPerson(*hapus) = NULL;
		}
		free(hapus);
	}
}

void printQueue(lockets L, int index) {
	Person *bantu;
	bantu = firstPerson(L, index);
	
	while(bantu != NULL) {
		printf("%d %s\n", age(*bantu),namePerson(*bantu));
		bantu = nextPerson(*bantu);
	}
}
