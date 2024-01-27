SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
int is_running = FALSE;
simon_button red, green, yellow, blue;
int m_x, m_y;

int init_window(void);
void destroy_window(void);
void setup(void);
void process_input(void);
void update(void);
void draw(void);
void setup_rect(char);
int check_in_bounds(simon_button, int , int );
void reset(void);
