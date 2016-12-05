#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include "objects.h"

//zmienne globalne
const int WIDTH = 800;
const int HEIGHT = 400;
enum KEYS{UP,DOWN,LEFT,RIGHT,SPACE};
bool keys[ 5 ] = { false,false,false,false,false };

//prototypy
void InitShip(SpaceShip &ship);
void DrawShip(SpaceShip &ship);

int main(void)
{
	//zmienna pierwotna
	bool done = false;

	//zmienne obiektowe
	SpaceShip ship;

	//zmienne allegro
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;

	//inicjalizacja funkcji
	if (!al_init())										
		return -1;

	display = al_create_display(WIDTH, HEIGHT);			
	if (!display)										
		return -1;

	al_init_primitives_addon();
	al_install_keyboard();

	event_queue = al_create_event_queue();


	InitShip(ship);

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	while (!done)
	{
		DrawShip(ship);

		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	al_destroy_display(display);						

	return 0;
}

void InitShip(SpaceShip &ship)
{
	ship.x = 20;
	ship.y = HEIGHT / 2;
	ship.ID = PLAYER;
	ship.lives = 3;
	ship.speed = 7;
	ship.boundx = 6;
	ship.boundy = 7;
	ship.score = 0;
}

void DrawShip(SpaceShip &ship)
{
	al_draw_filled_rectangle(ship.x, ship.y - 9, ship.x + 10, ship.y - 7, al_map_rgb(255, 0, 0));
	al_draw_filled_rectangle(ship.x, ship.y + 9, ship.x + 10, ship.y + 7, al_map_rgb(255, 0, 0));

	al_draw_filled_triangle(ship.x - 12, ship.y - 17, ship.x + 12, ship.y, ship.x - 12, ship.y + 17, al_map_rgb(0, 255, 0));
	al_draw_filled_rectangle(ship.x - 12, ship.y - 2, ship.x + 15, ship.y + 2, al_map_rgb(0, 0, 255));
}