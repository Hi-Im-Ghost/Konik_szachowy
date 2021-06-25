#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

//funkcja losujaca polozenie konika szachowego, dwie liczba od 0 do 7 zapiwyane do tablicy
int random(int array_konik[2], int array_historia[8][2]){

    int i=0;

    srand(time(0));

    for(i=0; i<=1; i++){

        array_konik[i] = rand()%8;

    }

    dodaj(array_konik, array_historia);


    return array_konik;

}

//funkcja ustawiająca konika w klikniętym polu szachownicy
int ppm(int mous_x, int mous_y, float array_x[8], float array_y[8], int array_konik[2], int width_monitor, int height_monitor, int array_historia[8][2]){

    int i, j;

    //Pętle które służą do sprawdzenia w które pole klikneliszmy
    for(i=0; i<=7; i++){

        for(j=0; j<=7; j++){

            if(mous_x >= array_x[i]-width_monitor*0.01 && mous_x <= array_x[i]+width_monitor*0.035 && mous_y >= array_y[j]-height_monitor*0.005 && mous_y <= array_y[j]+height_monitor*0.075){
                //Przypisanie nowej pozyci konika do tablicy
                array_konik[0] = i;
                array_konik[1] = j;
                dodaj(array_konik, array_historia);

                return array_konik;
            }
        }

    }

}

//Funkcja do przemieszczenia konika wedlug algorytmu
int lpm(int mous_x, int mous_y, float array_x[8], float array_y[8], int array_konik[2], int width_monitor, int height_monitor, int array_ruch[8][2], int array_historia[8][2]){

    int i;

    //Pętla sprawdzająca w które pole szachownicy klikneliszmy

    for(i=1; i<=array_ruch[0][0]; i++){

            if(mous_x >= array_x[array_ruch[i][0]]-width_monitor*0.01 && mous_x <= array_x[array_ruch[i][0]]+width_monitor*0.035 && mous_y >= array_y[array_ruch[i][1]]-height_monitor*0.005 && mous_y <= array_y[array_ruch[i][1]]+height_monitor*0.075){
                //Przypisanie nowej pozyci konika do tablicy
                array_konik[0] = array_ruch[i][0];
                array_konik[1] = array_ruch[i][1];
                array_ruch[0][1] = 1;
                dodaj(array_konik, array_historia);

                return array_konik;

        }

    }

}

//funkcja generujaca obraz na ekranie
int szachownica(int width_monitor, int height_monitor, ALLEGRO_FONT *font,ALLEGRO_FONT *font1, ALLEGRO_BITMAP *bitmap,ALLEGRO_BITMAP *bitmap1, float width_bitmap, float height_bitmap, float bitmap_width, float bitmap_height, float array_x[8], float array_y[8],int array_konik[2], int array_ruch[8][2], int array_historia[8][2]){

    //zmienna ktora jest wykorzystywana do liczenia mozliwych ruchow
    int i=0;

    //wyczysczenie oraz ustawienie koloru ekranu
    al_clear_to_color(al_map_rgb(255,255,255));

    //rysowanie lini pionowych szachownicy
    al_draw_line(width_monitor*0.3,height_monitor*0.14,width_monitor*0.3,height_monitor*0.781,al_map_rgb(0,0,0),0);
    al_draw_line(width_monitor*0.345,height_monitor*0.14,width_monitor*0.345,height_monitor*0.781,al_map_rgb(0,0,0),0);
    al_draw_line(width_monitor*0.39,height_monitor*0.14,width_monitor*0.39,height_monitor*0.781,al_map_rgb(0,0,0),0);
    al_draw_line(width_monitor*0.435,height_monitor*0.14,width_monitor*0.435,height_monitor*0.781,al_map_rgb(0,0,0),0);
    al_draw_line(width_monitor*0.48,height_monitor*0.14,width_monitor*0.48,height_monitor*0.781,al_map_rgb(0,0,0),0);
    al_draw_line(width_monitor*0.525,height_monitor*0.14,width_monitor*0.525,height_monitor*0.781,al_map_rgb(0,0,0),0);
    al_draw_line(width_monitor*0.57,height_monitor*0.14,width_monitor*0.57,height_monitor*0.781,al_map_rgb(0,0,0),0);
    al_draw_line(width_monitor*0.615,height_monitor*0.14,width_monitor*0.615,height_monitor*0.781,al_map_rgb(0,0,0),0);
    al_draw_line(width_monitor*0.66,height_monitor*0.14,width_monitor*0.66,height_monitor*0.781,al_map_rgb(0,0,0),0);

    //rysowanie lini poziomych szachownicy
    al_draw_line(width_monitor*0.3,height_monitor*0.14,width_monitor*0.66,height_monitor*0.14,al_map_rgb(0,0,0),0);
    al_draw_line(width_monitor*0.3,height_monitor*0.22,width_monitor*0.66,height_monitor*0.22,al_map_rgb(0,0,0),0);
    al_draw_line(width_monitor*0.3,height_monitor*0.3,width_monitor*0.66,height_monitor*0.3,al_map_rgb(0,0,0),0);
    al_draw_line(width_monitor*0.3,height_monitor*0.38,width_monitor*0.66,height_monitor*0.38,al_map_rgb(0,0,0),0);
    al_draw_line(width_monitor*0.3,height_monitor*0.46,width_monitor*0.66,height_monitor*0.46,al_map_rgb(0,0,0),0);
    al_draw_line(width_monitor*0.3,height_monitor*0.54,width_monitor*0.66,height_monitor*0.54,al_map_rgb(0,0,0),0);
    al_draw_line(width_monitor*0.3,height_monitor*0.62,width_monitor*0.66,height_monitor*0.62,al_map_rgb(0,0,0),0);
    al_draw_line(width_monitor*0.3,height_monitor*0.7,width_monitor*0.66,height_monitor*0.7,al_map_rgb(0,0,0),0);
    al_draw_line(width_monitor*0.3,height_monitor*0.78,width_monitor*0.66,height_monitor*0.78,al_map_rgb(0,0,0),0);

    //Numeracjia pol szachownicy w pionie literami od A do H
    al_draw_textf(font, al_map_rgb(0, 0, 0), width_monitor*0.285, height_monitor*0.15, ALLEGRO_ALIGN_CENTRE, "A");
    al_draw_textf(font, al_map_rgb(0, 0, 0), width_monitor*0.285, height_monitor*0.23, ALLEGRO_ALIGN_CENTRE, "B");
    al_draw_textf(font, al_map_rgb(0, 0, 0), width_monitor*0.285, height_monitor*0.31, ALLEGRO_ALIGN_CENTRE, "C");
    al_draw_textf(font, al_map_rgb(0, 0, 0), width_monitor*0.285, height_monitor*0.39, ALLEGRO_ALIGN_CENTRE, "D");
    al_draw_textf(font, al_map_rgb(0, 0, 0), width_monitor*0.285, height_monitor*0.47, ALLEGRO_ALIGN_CENTRE, "E");
    al_draw_textf(font, al_map_rgb(0, 0, 0), width_monitor*0.285, height_monitor*0.55, ALLEGRO_ALIGN_CENTRE, "F");
    al_draw_textf(font, al_map_rgb(0, 0, 0), width_monitor*0.285, height_monitor*0.63, ALLEGRO_ALIGN_CENTRE, "G");
    al_draw_textf(font, al_map_rgb(0, 0, 0), width_monitor*0.285, height_monitor*0.71, ALLEGRO_ALIGN_CENTRE, "H");

    //Numeracjia pol szachownicy w poziomie cyframi od 1 do 8
    al_draw_textf(font, al_map_rgb(0, 0, 0), width_monitor*0.322, height_monitor*0.08, ALLEGRO_ALIGN_CENTRE, "1");
    al_draw_textf(font, al_map_rgb(0, 0, 0), width_monitor*0.367, height_monitor*0.08, ALLEGRO_ALIGN_CENTRE, "2");
    al_draw_textf(font, al_map_rgb(0, 0, 0), width_monitor*0.412, height_monitor*0.08, ALLEGRO_ALIGN_CENTRE, "3");
    al_draw_textf(font, al_map_rgb(0, 0, 0), width_monitor*0.457, height_monitor*0.08, ALLEGRO_ALIGN_CENTRE, "4");
    al_draw_textf(font, al_map_rgb(0, 0, 0), width_monitor*0.502, height_monitor*0.08, ALLEGRO_ALIGN_CENTRE, "5");
    al_draw_textf(font, al_map_rgb(0, 0, 0), width_monitor*0.547, height_monitor*0.08, ALLEGRO_ALIGN_CENTRE, "6");
    al_draw_textf(font, al_map_rgb(0, 0, 0), width_monitor*0.592, height_monitor*0.08, ALLEGRO_ALIGN_CENTRE, "7");
    al_draw_textf(font, al_map_rgb(0, 0, 0), width_monitor*0.637, height_monitor*0.08, ALLEGRO_ALIGN_CENTRE, "8");

    //narysowanie konika szachowego na jednym z pol szachownicy
    al_draw_scaled_bitmap(bitmap,0,0, width_bitmap, height_bitmap ,array_x[array_konik[0]], array_y[array_konik[1]], bitmap_width, bitmap_height,0);

    //instrukcje warunkowe ktore sprawdzaja mozliwe ruchy konika szachowego, rysuja na ktore pola moze sie on poruszyc i zliczaja ilosc mozliwych ruchow
    if(array_konik[1]-2>=0 && array_konik[0]-1>=0){
        al_draw_scaled_bitmap(bitmap1,0,0, width_bitmap, height_bitmap ,array_x[array_konik[0]-1], array_y[array_konik[1]-2], bitmap_width, bitmap_height,0);
        i++;
        array_ruch[i][0] = array_konik[0]-1;
        array_ruch[i][1] = array_konik[1]-2;
    }
    if(array_konik[1]-2>=0 && array_konik[0]+1<=7){
        al_draw_scaled_bitmap(bitmap1,0,0, width_bitmap, height_bitmap ,array_x[array_konik[0]+1], array_y[array_konik[1]-2], bitmap_width, bitmap_height,0);
        i++;
        array_ruch[i][0] = array_konik[0]+1;
        array_ruch[i][1] = array_konik[1]-2;
    }
    if(array_konik[1]+2<=7 && array_konik[0]+1<=7){
        al_draw_scaled_bitmap(bitmap1,0,0, width_bitmap, height_bitmap ,array_x[array_konik[0]+1], array_y[array_konik[1]+2], bitmap_width, bitmap_height,0);
        i++;
        array_ruch[i][0] = array_konik[0]+1;
        array_ruch[i][1] = array_konik[1]+2;
    }
    if(array_konik[1]+2<=7 && array_konik[0]-1>=0){
        al_draw_scaled_bitmap(bitmap1,0,0, width_bitmap, height_bitmap ,array_x[array_konik[0]-1], array_y[array_konik[1]+2], bitmap_width, bitmap_height,0);
        i++;
        array_ruch[i][0] = array_konik[0]-1;
        array_ruch[i][1] = array_konik[1]+2;
    }
    if(array_konik[1]+1<=7 && array_konik[0]-2>=0){
        al_draw_scaled_bitmap(bitmap1,0,0, width_bitmap, height_bitmap ,array_x[array_konik[0]-2], array_y[array_konik[1]+1], bitmap_width, bitmap_height,0);
        i++;
        array_ruch[i][0] = array_konik[0]-2;
        array_ruch[i][1] = array_konik[1]+1;
    }
    if(array_konik[1]-1>=0 && array_konik[0]-2>=0){
        al_draw_scaled_bitmap(bitmap1,0,0, width_bitmap, height_bitmap ,array_x[array_konik[0]-2], array_y[array_konik[1]-1], bitmap_width, bitmap_height,0);
        i++;
        array_ruch[i][0] = array_konik[0]-2;
        array_ruch[i][1] = array_konik[1]-1;
    }
    if(array_konik[1]+1<=7 && array_konik[0]+2<=7){
        al_draw_scaled_bitmap(bitmap1,0,0, width_bitmap, height_bitmap ,array_x[array_konik[0]+2], array_y[array_konik[1]+1], bitmap_width, bitmap_height,0);
        i++;
        array_ruch[i][0] = array_konik[0]+2;
        array_ruch[i][1] = array_konik[1]+1;
    }
    if(array_konik[1]-1>=0 && array_konik[0]+2<=7){
        al_draw_scaled_bitmap(bitmap1,0,0, width_bitmap, height_bitmap ,array_x[array_konik[0]+2], array_y[array_konik[1]-1], bitmap_width, bitmap_height,0);
        i++;
        array_ruch[i][0] = array_konik[0]+2;
        array_ruch[i][1] = array_konik[1]-1;
    }

    array_ruch[0][0] = i;

    //wypisanie na ekranie inforamcji jak oblugiwac program, ilosc mozliwych ruchow oraz autorow na ekranie
    al_draw_textf(font, al_map_rgb(0, 0, 0), 1, 1, ALLEGRO_ALIGN_LEFT, "ESC - Wyjscie z programu");
    al_draw_textf(font, al_map_rgb(0, 0, 0), 1, height_monitor*0.04, ALLEGRO_ALIGN_LEFT, "P - Nowa losowa pozycja skoczka");
    al_draw_textf(font, al_map_rgb(0, 0, 0), 1, height_monitor*0.08, ALLEGRO_ALIGN_LEFT, "PPM - Ustawienie pozycji skoczka");
    al_draw_textf(font, al_map_rgb(0, 0, 0), 1, height_monitor*0.12, ALLEGRO_ALIGN_LEFT, "LPM - Ruch skoczka");
    al_draw_textf(font, al_map_rgb(0, 0, 0), width_monitor*0.5, height_monitor*0.9, ALLEGRO_ALIGN_CENTER, "Mozliwa ilosc ruchow to: %d", i);

    al_draw_textf(font1, al_map_rgb(0, 0, 0), width_monitor*0.85, height_monitor*0.4, ALLEGRO_ALIGN_CENTER, "Autorzy:");
    al_draw_textf(font1, al_map_rgb(0, 0, 0), width_monitor*0.85, height_monitor*0.44, ALLEGRO_ALIGN_CENTER, "Adrian Chmielowiec");
    al_draw_textf(font1, al_map_rgb(0, 0, 0), width_monitor*0.85, height_monitor*0.48, ALLEGRO_ALIGN_CENTER, "Marcin Kozera");
    al_draw_textf(font1, al_map_rgb(0, 0, 0), width_monitor*0.85, height_monitor*0.52, ALLEGRO_ALIGN_CENTER, "Marek Prajs");

    //wyswietlenie poprzednich pozycji
    historia(font1, height_monitor, width_monitor, array_historia);

    //odswierzenie ekranu aby pojawily wszystkie elementy od wyczyszczenia ekranu
    al_flip_display();

    return array_ruch;

}

//Funkcja wypisuje na ekranie ostatnie pozycje konika
void historia(ALLEGRO_FONT *font1, int width_monitor, int height_monitor, int array_historia[8][2]){

    int i;

    al_draw_textf(font1, al_map_rgb(0, 0, 0), width_monitor*0.2, height_monitor*0.14, ALLEGRO_ALIGN_CENTER, "Poprzednie porzycie konika:");
    al_draw_textf(font1, al_map_rgb(0, 0, 0), width_monitor*0.2, height_monitor*0.16, ALLEGRO_ALIGN_CENTER, "(Ostatnie 7 pozycji konika)");

    //Petla wypisujaca pozycje na ekranie
    for(i = 1; i <= array_historia[0][0]; i++){

        al_draw_textf(font1, al_map_rgb(0, 0, 0), width_monitor*0.2, height_monitor*(0.16+(0.02*i)), ALLEGRO_ALIGN_CENTER, "%c%d", (array_historia[i][1]+65), (array_historia[i][0]+1));

    }

}

//Funkcja dodaje do tablicy ostanie pozycje skoczka
int dodaj(int array_konik[2], int array_historia[8][2]){

    //Sprawdzenie ilosci elementow tablicy
    if(array_historia[0][0] > 6){

        //zmienne pomocnicze
        int i, j;

        //petle ktore zamieniaja miejscami elementy tablicy
        for(i = 1; i <= 6; i++){

            for(j = 0; j < 2; j++)
                array_historia[i][j] = array_historia[i+1][j];

        }
        //dodawanie ostatniej pozyci skoczka do tablicy
        array_historia[7][0] = array_konik[0];
        array_historia[7][1] = array_konik[1];

    }else{
        //dodawanie ostatniej pozyci skoczka do tablicy
        array_historia[0][0]++;
        array_historia[array_historia[0][0]][0] = array_konik[0];
        array_historia[array_historia[0][0]][1] = array_konik[1];

    }

    return array_historia;

}

int main(){

    //zmienne stosowane do obslugi obrazka konika
    float width_bitmap = 0, height_bitmap = 0, bitmap_width = 0, bitmap_height = 0;

    //zmienne stosowane do obslugo biblioteki allegro
    ALLEGRO_DISPLAY *display;
    ALLEGRO_MONITOR_INFO info;
    ALLEGRO_EVENT_QUEUE *queue;
    ALLEGRO_EVENT event;
    ALLEGRO_FONT *font, *font1;
    ALLEGRO_BITMAP *bitmap, *bitmap1;

    //sprawdzenie poprawnej inicjacji biblioteki
    if (!al_init()) {
        printf("Blad inicjacji Allegro\n");
        return 1;
    }

    //sprawdzenie poprawnej inicjacji myszy
    if(!al_install_mouse()){
        printf("Blad inicjacji myszki\n");
        return 1;
    }

    //sprawdzenie poprawnej inicjacji klawiatury
    if(!al_install_keyboard()){
        printf("Blad inicjacji klawiatury\n");
        return 1;
    }

    //inicjiowanie obslugo rysowania, obrazow oraz fontow w bibliotece
    al_init_primitives_addon();
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();

    //pobranie informacji o ekranie do poprawnego dzialania programu w trybie pelnoekranowym
    al_get_monitor_info(0, &info);
    int width_monitor = info.x2, height_monitor = info.y2;

    //ustawienie dzialania progrmu w trybie pelnoekranowym o rozdzielcosci ekranu
    al_set_new_display_flags(ALLEGRO_FULLSCREEN);
    display = al_create_display(width_monitor, height_monitor);

    //ustawienie fontow
    font = al_load_ttf_font("arial.ttf", height_monitor*0.035, 0);
        if(!font) printf("Blad wczytywania font-u 0\n");
    font1 = al_load_ttf_font("arial.ttf", height_monitor*0.03, 0);
        if(!font) printf("Blad wczytywania font-u 0\n");

    //ustawienie obrazkow konika szachowego
    al_set_new_bitmap_flags(ALLEGRO_MEMORY_BITMAP);
    bitmap = al_load_bitmap("konik.png");
    bitmap1 = al_load_bitmap("konik-ruch.png");

    //pobranie domyslnej rozdzielscosci obrakow
    width_bitmap = al_get_bitmap_width(bitmap);
    height_bitmap = al_get_bitmap_height(bitmap);

    //dopasowanie wymiarow obrazkow do rozdzielcosci ekranu
    bitmap_width = width_bitmap * 0.04;
    bitmap_height = height_bitmap * 0.04;

    //ustawienie zmiennych, ktore sa uzywane do ustawienia konika na szachownicy kolejno zmienne x(od 1-8) oraz y(od A-B) s¹ to numery pikseli od których zaczyna byæ ryssowany konik
    float array_x[8] = {width_monitor*0.31, width_monitor*0.355, width_monitor*0.4, width_monitor*0.445, width_monitor*0.49, width_monitor*0.535, width_monitor*0.58, width_monitor*0.625};
    float array_y[8] = {height_monitor*0.145, height_monitor*0.225, height_monitor*0.305, height_monitor*0.385, height_monitor*0.465, height_monitor*0.545, height_monitor*0.625, height_monitor*0.705};

    //poczatkowe polozenie konika na polu A1
    int array_konik[2] = {0,0};
    int array_ruch[8][2];
    int array_historia[8][2] = {{0,0}};

    //wywolanie funkcji losujace polozenia konika
    random(array_konik, array_historia);

    //wywolanie funkcji ktora tworzy szachownice oraz rysuje konika na odpowiedni polu
    szachownica(width_monitor,height_monitor, font, font1, bitmap, bitmap1, width_bitmap, height_bitmap, bitmap_width, bitmap_height, array_x, array_y, array_konik, array_ruch, array_historia);

    //funkcjia biblioteki allegro, ktora sluzy do pobierania zdarzen z klaiatury, myszy oraz ekranu
    queue = al_create_event_queue();
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));

    //petla ktora utrzymuje dzialanie programu
     while (1) {

        //czekanie na kolejne wydzarzenie
        al_wait_for_event(queue, &event);

        //instrukja ktora rozpoznaje odpowiednie zdarzenie
        switch (event.type) {

            //wcisniecie klawisza na klawiaturze
            case ALLEGRO_EVENT_KEY_DOWN:

                //instrukcja ktora wybiera odpowiednia akcje zalezna od wcisnietego przycisku
                switch(event.keyboard.keycode){

                    //zakonczenie dzialania programu po wcisnieviu klawisza ESC
                    case ALLEGRO_KEY_ESCAPE:

                        //zwolnienie miesjca wykorzystywanego przez zmienne biblioteki oraz zakonczenie dzialania programu
                        al_destroy_bitmap(bitmap);
                        al_destroy_bitmap(bitmap1);
                        al_destroy_event_queue(queue);
                        al_destroy_font(font);
                        al_destroy_font(font1);
                        al_destroy_display(display);
                        return 0;
                        break;

                    //akcja po klikniecju przycisku P
                    case ALLEGRO_KEY_P:

                        //wylosowanie nowej porzycji konika
                        random(array_konik, array_historia);
                        //ponowne wywolanie funkcji rysujacej z nowa pozycja konika
                        szachownica(width_monitor,height_monitor, font, font1, bitmap, bitmap1, width_bitmap, height_bitmap, bitmap_width, bitmap_height, array_x, array_y, array_konik, array_ruch, array_historia);
                        break;

                }

                break;

                //akcja po kliknięciu myszką

            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:

                switch(event.mouse.button){

                    //akcja po kliknięciu prawego przyciszku myszki
                    case 2:

                        ppm(event.mouse.x, event.mouse.y, array_x, array_y, array_konik, width_monitor, height_monitor, array_historia);
                        szachownica(width_monitor,height_monitor, font, font1, bitmap, bitmap1, width_bitmap, height_bitmap, bitmap_width, bitmap_height, array_x, array_y, array_konik, array_ruch, array_historia);

                        break;

                    //akcja po kliknięciu lewego przyciszku myszki
                    case 1:

                        lpm(event.mouse.x, event.mouse.y, array_x, array_y, array_konik, width_monitor, height_monitor, array_ruch, array_historia);

                            if(array_ruch[0][1] != 0){

                                szachownica(width_monitor,height_monitor, font, font1, bitmap, bitmap1, width_bitmap, height_bitmap, bitmap_width, bitmap_height, array_x, array_y, array_konik, array_ruch, array_historia);
                                array_ruch[0][1] = 0;

                            }

                        break;

                }

                break;

        }
     }

}
