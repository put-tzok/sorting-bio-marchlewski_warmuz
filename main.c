#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int ns[] = {10000,5000, 20000, 30000, 12573, 23003, 120, 1211, 17212, 7777};



void fill_increasing(int *t, unsigned int n) {
     for (unsigned int i = 0; i < n; i++)
        t[i] = i+5;
}

void fill_decreasing(int *t, unsigned int n) {
    int start=n;
    int i=0;
        while(start>=0){
            t[i]=start--;
            i++;}
}

void fill_vshape(int *t, unsigned int n) {
    int temp;
   if(n%2!=0){
   temp=(n-1)/2;
   int wart=0;
   while(temp>=0){
t[temp--]=wart;
wart+=2;
   }
      temp=(n+1)/2;
   wart=1;
   while(temp<n){
    t[temp++]=wart;
wart+=2;
   }
   }else{
   temp=(n-2)/2;
   int wart=2;
   while(temp>=0){
t[temp--]=wart;
wart+=2;
   }
      temp=n/2;
   wart=1;
   while(temp<n){
    t[temp++]=wart;
wart+=2;
    }

   }
}

void selection_sort(int *t, unsigned int n) {
int indeks=0;
int *mini;//wskaznik na najmniejszy element w iteracji
int temp;
while(indeks<n-1){
mini= &t[indeks];//ustawnienie pierwszego eltu jako najmniejszego
temp=indeks;
while(temp<=n-1){//przeszukiwanie coraz to mniejszej tablicy
    if(*mini>t[temp])
    mini= &t[temp];//zmiana wskaznika w przypadku trafienia na mniejszy element
    temp++;
}
if(*mini!=t[indeks]){//zamiana pierwszego eltu na najmniejszy w aktualnej tablicy
temp=*mini;
*mini=t[indeks];
t[indeks]=temp;
}
indeks++;//odcięcie posortowanej czesci tablicy
}
}

void insertion_sort(int *t, unsigned int n) {
    int i=1, key, j;
    for (i; i<n; i++){ //dla ka¿dego elementu do zakresu tebeli
        key=t[i]; //przypisuje kluczowi waroœæ pierwszego elementu
        j=i-1;    //zmniejsza j do wartoœci poprzedniego elementu
        while(j>=0&&t[j]>key)    //dopoki j znajduje siê w zakresie tabeli i jest wiêksze od klucza (nastêpnego elementu)
        {
            t[j+1]=t[j]; //przesuwa elementy wiêksze od klucza za klucz
            j--;        //przechodzi do kolejnego elementu
        }
        t[j+1]=key; //przywraca wartoœæ klucza do tabeli
    }
}


int podziall(int *t, int start, int fin){
//podzial metoda Lamuto
int pivot=t[fin];//elementem rozdzielajacym jest ostani element
int s=start;
int temp;
for(int f=start;f!=fin;f++){//f wedruje w poszukiwaniu elementu mniejszego od pivotu
    if(t[f]<pivot){//jesli na taki trafi to zamienia go z t[s] gdzie s to indeks elemtow pierszeych od lewej
        temp=t[s];
        t[s]=t[f];
        t[f]=temp;
        s++;
    }

}
  temp=t[s];//po zakonczeniu oentli for natepuje zamiana pivotu z t[s], wszyskie wartosci o indeksie<s sa mniejsze od pivotu, a o indeksie>s sa wieksze od pivotu
        t[s]=t[fin];
        t[fin]=temp;
        return s;


}

void lastqsort(int *t, int start, int fin){
int pivot;

if(start<fin){//wywolywanie rekurencujne dla coraz to mniejszych fragmentow tablic
    pivot= podziall(t, start,fin);
    lastqsort(t,start,pivot-1);
    lastqsort(t,pivot+1,fin);
}

}

void quick_sort_last(int *t, unsigned int n) {
lastqsort(t, 0, n-1);
}

int podzialr(int *t, int start, int fin){

int temp;
int pivot= (rand()%(fin + 1 - start))+start;//wybor losowego elementu rozdzielajacego
temp=t[fin];
t[fin]=t[pivot];
t[pivot]=temp;
pivot= t[fin];



int s=start;

for(int f=start;f!=fin;f++){
    if(t[f]<pivot){
        temp=t[s];
        t[s]=t[f];
        t[f]=temp;
        s++;
    }

}
  temp=t[s];
        t[s]=t[fin];
        t[fin]=temp;
        return s;

}

void randqsort(int *t, int start, int fin){
    int pivot;

if(start<fin){
    pivot= podzialr(t, start,fin);
    randqsort(t,start,pivot-1);
    randqsort(t,pivot+1,fin);
}
}

void quick_sort_rand(int *t, unsigned int n){

randqsort(t, 0, n-1);
}


void heap_maker (int *heap, int n, int node)
{
    int largest=node; //największy element zostaje element będący aktualnie na "górze" drzewa
    int l=2*node+1;  //gałąź lewa względem elementu na górze
    int r=2*node+2; //gałąź prawa

    if(l<n&&heap[l]>heap[largest]) // jeżeli lewe dziecko jest większe od rodzica
        largest = l;                //dziecko zostaje zapisane jako największy element
    if(r<n&&heap[r]>heap[largest])  //jeżeli prawe dziecko jest większe od rodzica
        largest = r;                //dziecko zostaje zapisane jako największy element
    if(largest!=node)               //jeżeli największy element nie jest rodzicem, czyli w poprzednich punktach nastąpiła zmiana
    {

         //zamień rodzica z większym dzieckiem

         int temp= heap[node];
heap[node]= heap[largest];
heap[largest]=temp;
        heap_maker(heap, n, largest);  //powtórz rekurencyjnie dla nowopowstałego drzewa
    }
}

void heap_sort(int *t, unsigned int n) {
    for (int i=n; i>=0; i--)
        heap_maker(t, n, i); //sortuje dane w podstawowe drzewo

    for (int i=n-1; i>=0; i--) //zmniejsza zakres tabeli z którego pobiera elementy żeby nie brać już posortowanych
    {
        //przesuwa aktualny największy element, czyli korzeń, na koniec tabeli, jako posortowany elemeny
int temp= t[0];
t[0]= t[i];
t[i]=temp;


        heap_maker(t, i, 0); //sortuje nowopowstały kopiec
    }
}

void fill_random(int *t, unsigned int n) {
    for (unsigned int i = 0; i < n; i++) {
        t[i] = rand();
    }
}

void is_random(int *t, unsigned int n) {
    return;
}

void is_increasing(int *t, unsigned int n) {
    for (unsigned int i = 1; i < n; i++) {
        assert(t[i] > t[i - 1]);
    }
}

void is_decreasing(int *t, unsigned int n) {
    for (unsigned int i = 1; i < n; i++) {
        assert(t[i] < t[i - 1]);
    }
}

void is_vshape(int *t, unsigned int n) {
    int *begin = t;
    int *end = t + n - 1;

    while (end - begin > 1) {
        assert(*begin > *end);
        begin++;
        assert(*end > *begin);
        end--;
    }
}

void is_sorted(int *t, unsigned int n) {
    for (unsigned int i = 1; i < n; i++) {
        assert(t[i] >= t[i - 1]);
    }
}

void (*fill_functions[])(int *, unsigned int) = { fill_random, fill_increasing, fill_decreasing, fill_vshape };
void (*check_functions[])(int *, unsigned int) = { is_random, is_increasing, is_decreasing, is_vshape };
void (*sort_functions[])(int *, unsigned int) = { selection_sort, insertion_sort, quick_sort_last, quick_sort_rand, heap_sort };//

char *fill_names[] = { "Random", "Increasing", "Decreasing", "V-Shape" };
char *sort_names[] = { "SelectionSort", "InsertionSort", "QuickSortLast", "QuickSortRand", "HeapSort" };//

int main() {
    for (unsigned int i = 0; i < sizeof(sort_functions) / sizeof(*sort_functions); i++) {
        void (*sort)(int *, unsigned int) = sort_functions[i];

        for (unsigned int j = 0; j < sizeof(fill_functions) / sizeof(*fill_functions); j++) {
            void (*fill)(int *, unsigned int) = fill_functions[j];
            void (*check)(int *, unsigned int) = check_functions[j];

            for (unsigned int k = 0; k < sizeof(ns) / sizeof(*ns); k++) {
                unsigned int n = ns[k];
                int *t =malloc((n+1) * sizeof(int));//konieczna byla ta modyfikacja poniewaz program nie dzialal dla wszyskich rozmiarow tabeli

                fill(t, n);
                check(t, n);

                clock_t begin = clock();
                sort(t, n);
                clock_t end = clock();

                is_sorted(t, n);

                printf("%s\t%s\t%u\t%f\n", sort_names[i], fill_names[j], n, (double)(end - begin) / (double) CLOCKS_PER_SEC);



                free(t);
                t= NULL;
            }
        }
    }

    return 0;
}
