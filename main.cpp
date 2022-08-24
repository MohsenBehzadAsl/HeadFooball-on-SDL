#include <string>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <SDL2/SDL2_gfx.h>
#include <fstream>
#include<algorithm>


using namespace std;

void texture(SDL_Renderer *m_renderer,int xp,int yp,string addressOfImage,int width,int height);
void window_color(SDL_Renderer *Renderer, int R, int G, int B);
void textColor(SDL_Renderer *renderer,int x,int y,const char * text,const char * font,int font_size,SDL_Color textColor,double angle,short flip_num);


typedef enum{
     NONE = 0,
     HORIZENTAL = 1,
     VERTICAL = 2,
     HORVER = 3
}short;




int main( int argc, char * argv[] )
{
    Uint32 SDL_flags = SDL_Init ( SDL_INIT_EVERYTHING );

    int H = 750;
    int W = 1500;

    TTF_Init();

    Uint32 WND_flags = SDL_WINDOW_SHOWN ;
    SDL_Window * m_window;
    SDL_Renderer * m_renderer;




    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,MIX_DEFAULT_FORMAT,2,2048); //Define Audio type

    string sound = "resources\\0.mp3"; //Background sound Address
    string chunk_sound = "resources\\collision.ogg"; //Chunk sound Address
    Mix_Music *GameSound = Mix_LoadMUS(sound.c_str()); //Load background sound
    Mix_Chunk *collision = Mix_LoadWAV(chunk_sound.c_str()); //Load sound for wall collision
    Mix_PlayMusic(GameSound,-1); //Play the sound.  -1 means play it till the end

    Mix_VolumeMusic(500);
    //Mix_FreeMusic(GameSound);



    SDL_CreateWindowAndRenderer( W, H, WND_flags, &m_window, &m_renderer );
    //Pass the focus to the drawing window
    SDL_RaiseWindow(m_window);
    //Get screen resolution
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);




    SDL_SetRenderDrawColor( m_renderer, 100, 100,100, 255 );
    SDL_RenderClear( m_renderer );


    // Show the window
    SDL_RenderPresent( m_renderer );






    srand(time(NULL));


    SDL_Event *e = new SDL_Event();

    const Uint8 *keyboard_state_array = SDL_GetKeyboardState(NULL);
    //*********************************************
    int x_mouse,y_mouse;
    int r_starting=30,x_starting=1450,y_starting=50,x_starting2=1450,y_starting2=50,dx_starting=10,dy_starting=10;
    //**********************************************
    int setTime=90;int setTime0=90;
    //**********************************************
    const char * font_address_01="resources\\HARLOWSI.ttf"; //define some fonts with extension 'ttf'
    const char * font_address_02="resources\\Ubuntu-C_0.ttf";
    const char * font_address_03="resources\\DK Longreach.ttf";
    int font_size = 36;
    int font_size_enter_name = 60;
    double angle = 0.0;
    //************************************
    SDL_Color text_color = { 250, 250, 250};

    SDL_Color text_color_setting = { 250, 100,100};

    SDL_Color text_color_setting_loading = { 250, 0, 0};

    SDL_Color text_color_setting_loading2= {255, 255, 255};
    //**********************************************
    int x_text_welcome=250,y_text_welcome=100;
    const char * text_welcome ="Welcome  To  Head   Football ( UEFA champions league eddition )" ;


    int x_text_developed=360,y_text_developed=650;
//    const char * text_developed ="Developed by Mohsen BehzadAsl & Mehdi Fattahi";
    const char * text_developed ="Developed by Mohsen BehzadAsl";

    //**********************************************
    bool  redraw=true;

    bool flag_control_whole_game=true,flag1=true,flag2=false,flag3=false,flag4=false,flag5=false,flag6=false,flag7=false,flag8=false,flag_setting_compile_game=false,flag9=false,flag10=false,flag11=false,flag12=false,flag13=false,flag_exit=false;
    // *************************************************
    char counter_setting_player1='1',counter_setting_player2='1';

    char counter_setting_stadium='1',counter_setting_ball='1';

    char counter_play_playing_player1='0',counter_play_playing_player2='0';

    //**************************************************

    double x_player1=200,y_player1=480,dx_player1=25,dx_player1_help=25,dy_player1=25,dy_player1_help=25;
    double x_player2=1200,y_player2=480,dx_player2=-25,dy_player2=25,dx_player2_help=25,dy_player2_help=25;


    int W_player1=100,H_player1=220;
    int W_player2=100,H_player2=220;

    int min_W_player1=W_player1 ,_min_H_player1=H_player1;
    int min_W_player2=W_player2 ,_min_H_player2=H_player2;

    //**************************************************
    int x_firstgoal=0,y_firstgoal=380;
    int x_secondgoal=1320,y_secondgoal=380;

    int W_firstgoal=180,H_firstgoal=320;
    int W_secondgoal=180,H_secondgoal=320;

    //**************************************************

    char counter_numGoal_player1='0';
    char counter_numGoal_player2='0';
    //**************************************************

    double dx_helpBall=0.5,dx0_ball=-15;
    double dx_ball=dx0_ball,dy0_ball=-24,dy_ball=-24,dy0_helpBall=0.95,dy_helpBall=dy0_helpBall,more_control_dy_ball=22;
    double x0_ball=710,y0_ball=181;
    double x_ball=x0_ball,y_ball=y0_ball;
    double x_ball_goal=750,y_ball_goal=500,dx_ball_goal=0,dy_ball_goal=0;

    //**************************************************

    bool come_out_from_for=true;

    bool hasintersection=false;

    bool first_collision_ball=true;

    int firstWWW_collision_ball=0;

    bool help=true;

    //**************************************************

        double start;
        bool start_clocking=false;

        int font_size_timer=90;

        double start_clocking_full_time_game;
        int start_clocking_full_time_game_tostring;
        string start_clocking_full_time_game_tostring_type;

        const char *start_clocking_full_time_game_tochar;

        bool start_clocking_full=true;

        int x_timer=678;
        int y_timer=40;

        SDL_Color text_color_timer = { 0, 110,110};



        double counter_power_handling_player1=0;
        double counter_power_handling_player2=0;

        double start_kick_player1;
        bool start_clocking_kick_player1=false;



        double start_kick_player2;
        bool start_clocking_kick_player2=false;



        bool flag_first_collision_by_player=true;



        double start_jump_player1=-40;
        bool start_clocking_jump_player1=false;
        bool control_jump_player1=true;


        double start_jump_player2=-40;
        bool start_clocking_jump_player2=false;
        bool control_jump_player2=true;




        bool control_ball_while_hits_ground=false;
        bool second_control_ball_while_hits_ground=false;
        bool third_control_ball_while_hits_ground=false;
        bool fourth_control_ball_while_hits_ground=false;
        bool fifth_control_ball_while_hits_ground=false;


        double t_helping;



        double control_hitsurface_player1=0;
        double control_hitsurface_player2=0;
        double control_hitsurface_goal1=0;
        double control_hitsurface_goal2=0;



        bool to_handle_ball_around_player1;
        bool to_handle_ball_around_player2;
        bool more_control_on_ball;
        bool second_more_control_on_ball=false;


        bool control_ball1=false;
        bool control_ball2=false;

        bool flag_aboutMe=false;

//************************************************

int y1_fans=110;

int y2_fans=170;

int y3_fans=230;

int y4_fans=290;

double start_clock_fans=0;

double start_clocking_countdown=0;

//***********************************************

        SDL_Rect ball_rect;

        SDL_Rect headplayer1;

        SDL_Rect body1player1;

        SDL_Rect body2player1;

        SDL_Rect footplayer1;

        SDL_Rect headplayer2;

        SDL_Rect body1player2;

        SDL_Rect body2player2;

        SDL_Rect footplayer2;









        SDL_Rect headplayer12;

        SDL_Rect body1player12;

        SDL_Rect body2player12;

        SDL_Rect footplayer12;

        SDL_Rect headplayer22;

        SDL_Rect body1player22;

        SDL_Rect body2player22;

        SDL_Rect footplayer22;







        SDL_Rect headplayer13;

        SDL_Rect body1player13;

        SDL_Rect body2player13;

        SDL_Rect footplayer13;

        SDL_Rect headplayer23;

        SDL_Rect body1player23;

        SDL_Rect body2player23;

        SDL_Rect footplayer23;





        SDL_Rect rect_top_goal_first;

        SDL_Rect rect_top_goal_second;

        SDL_Rect rect_beside_box1;

        SDL_Rect rect_beside_box2;

        SDL_Rect rect_detect_goal_player1;

        SDL_Rect rect_detect_goal_player2;


        SDL_Rect rect_goal_counter_player1;

        rect_goal_counter_player1.x=520;
        rect_goal_counter_player1.y=10;
        rect_goal_counter_player1.w=140;
        rect_goal_counter_player1.h=150;

        SDL_Rect rect_goal_counter_player2;

        rect_goal_counter_player2.x=850;
        rect_goal_counter_player2.y=10;
        rect_goal_counter_player2.w=140;
        rect_goal_counter_player2.h=150;
//******************************************

    double clock_player_hit=0;

//******************************************

    bool flag_visible_ball=true;

//*****************************************

    int num=0,k=0;
    int tedad_goal_khorde1=0,tedad_goal_zade1=0,tedad_bord1=0,tedad_mosavi1=0,tedad_bakht1=0,tedad_bazi1=0,point1=0,ekhtelaf1=0;
    int tedad_goal_khorde2=0,tedad_goal_zade2=0,tedad_bord2=0,tedad_mosavi2=0,tedad_bakht2=0,tedad_bazi2=0,point2=0,ekhtelaf2=0;
    string asami[100];

//*****************************************

int counter_goal_plyer1=0,counter_goal_plyer2=0;
//*****************************************

bool flag_power_headfireball_player1=false,flag_help_power_headfireball_player1=false,flag_help2_power_headfireball_player1=false,flag_help3_power_headfireball_player1=false,flag_help4_power_headfireball_player1=false;
double start_clock_help4_headfireball=0,start_clock_help3_headfireball=0;


//****************************************

int count_dx_player2=0;

//***************************************

bool flag_power_headfireball_player2=false,flag_help_power_headfireball_player2=false,flag_help2_power_headfireball_player2=false,flag_help3_power_headfireball_player2=false,flag_help4_power_headfireball_player2=false;
double start_clock_help4_headfireball2=0,start_clock_help3_headfireball2=0;


//****************************************

int count_dx_player1=200;


//**************************************

bool flag_power_kickfireball_player1=false,flag_help_power_kickfireball_player1=false,flag_help2_power_kickfireball_player1=false,flag_help3_power_kickfireball_player1=false,flag_help4_power_kickfireball_player1=false;
double start_clock_help4_kickfireball=0,start_clock_help3_kickfireball=0;

//************************************

bool flag_power_kickfireball_player2=false,flag_help_power_kickfireball_player2=false,flag_help2_power_kickfireball_player2=false,flag_help3_power_kickfireball_player2=false,flag_help4_power_kickfireball_player2=false;
double start_clock_help4_kickfireball2=0,start_clock_help3_kickfireball2=0;


//***********************************

int rand_power;



//***********************************


bool flag_power_invisibleball_player1=false,flag_help_power_invisibleball_kick_player1=false,flag_help2_power_invisibleball_kick_player1=false;
bool flag_help_power_invisibleball_head_player1=false,flag_help2_power_invisibleball_head_player1=false,flag_help3_power_invisibleball_head_player1=false,flag_help4_power_invisibleball_head_player1=false;


bool flag_power_invisibleball_player2=false,flag_help_power_invisibleball_kick_player2=false,flag_help2_power_invisibleball_kick_player2=false;
bool flag_help_power_invisibleball_head_player2=false,flag_help2_power_invisibleball_head_player2=false,flag_help3_power_invisibleball_head_player2=false,flag_help4_power_invisibleball_head_player2=false;

bool invisibleball_power=false;
double start_clock_invisibleball_power=0;


//***************************************


bool flag_power_punch_player1=false,flag_help_power_punch_player1=false,flag_help2_power_punch_player1=false;
double start_clock_help_punch=0,start_clock_help2_punch=0;

int w_punch=0;


bool flag_power_punch_player2=false,flag_help_power_punch_player2=false,flag_help2_power_punch_player2=false;
double start_clock_help_punch2=0,start_clock_help2_punch2=0;




bool flag_power_tripleclone_player1=false,flag_power_tripleclone_player2=false;
double start_clock_tripleclone_player1=0,start_clock_tripleclone_player2=0;


//**************************************************

    string name_player1="",name_player2="";
string name_player1_help="",name_player2_help="";
int last_char_of_name_player1_help=0,last_char_of_name_player2_help=0;
    bool caps_lock = false;
    bool quit_enter_name = false ;
    char ch=0;


bool draw_score_board=true;

bool draw_table=false;

bool ever_played_player1=false,ever_played_player2=false;

int directer_ever_played_player1=-1,directer_ever_played_player2=-1;

string table;


//*************************************

bool pause_player1=false;
bool pause_player2=false;

//*************************************

double start_clocking_pause_player1=0,start_clocking_pause_player2=0;

bool save_result=false;


int i=0;

//***************************************

double start_clock_player1_setting=0;
double start_clock_player2_setting=0;


char counter_play_ball='1';
double start_clock_ball=0;


bool flag_sure=false;
bool flag_ads=false;
bool flag_ads2=false;
int yyy=0;












    for ( int i = 0; i < 1000; i++)
    {
        aalineRGBA(m_renderer, 0, i, W, i, (i%100),55,78, 255);
        SDL_RenderPresent( m_renderer );
        SDL_Delay( 1.5 );
    }


    for ( int i = 0; i < 4000; i++)
    {
        SDL_PollEvent(e);

        filledCircleRGBA(m_renderer,x_starting,y_starting,r_starting,20,191,0,255);

        x_starting+=dx_starting;
        y_starting+=dy_starting;

        if ((x_starting<r_starting-dx_starting)||(x_starting>W-r_starting-dx_starting))
            dx_starting=-dx_starting;
        if((y_starting<r_starting-dy_starting)||(y_starting>H-r_starting-dy_starting))
            dy_starting=-dy_starting;


        SDL_RenderPresent(m_renderer);


    }



        for ( int i = 0; i < 4000; i++)
    {
        SDL_PollEvent(e);

        filledCircleRGBA(m_renderer,x_starting,y_starting,r_starting,220,191,0,255);

        x_starting+=dx_starting;
        y_starting+=dy_starting;

        if ((x_starting<r_starting-dx_starting)||(x_starting>W-r_starting-dx_starting))
            dx_starting=-dx_starting;
        if((y_starting<r_starting-dy_starting)||(y_starting>H-r_starting-dy_starting))
            dy_starting=-dy_starting;


        SDL_RenderPresent(m_renderer);


    }

while(flag_control_whole_game)
{

    SDL_RenderClear(m_renderer);


    while(flag1)
    {
        SDL_PollEvent(e);

        if(redraw)
        {
            texture(m_renderer,0,0,"first_backGround.png",1500,750);
            texture(m_renderer,130,220,"UEFA_Champions_League_logo.png",300,300);
            texture(m_renderer,1020,220,"UEFA_Champions_League_logo.png",300,300);

            textColor(m_renderer,x_text_welcome+60,y_text_welcome,text_welcome,font_address_02 ,font_size,text_color,angle,NONE);
            textColor(m_renderer,x_text_developed+120,y_text_developed,text_developed,font_address_03 ,font_size,text_color_setting,angle,NONE);
            texture(m_renderer,550,240,"startGame.png",350,110);
            texture(m_renderer,550,370,"load_sign.png",350,100);
            texture(m_renderer,550,490,"setting_sign.png",350,100);

            texture(m_renderer,990,645,"aboutMe.png",150,50);


            SDL_RenderPresent( m_renderer );

            redraw=false;
        }


         if(e->type==SDL_MOUSEBUTTONDOWN)
         {
             x_mouse=e->motion.x;
             y_mouse=e->motion.y;

             for(int i=0;i<8;i++)
            {
                aacircleRGBA(m_renderer,x_mouse,y_mouse,30*i/5,255,0,0,255);
            }

            SDL_RenderPresent(m_renderer);

            string chunk_sound = "resources\\mouse_button.ogg"; //Chunk sound Address
            Mix_Chunk *collision = Mix_LoadWAV(chunk_sound.c_str()); //Load sound for wall collision
            Mix_PlayChannel(-1,collision,0);



             if(x_mouse > 550 && x_mouse < 900 && y_mouse > 250 && y_mouse < 350)
             {
                 flag1=false;
                 flag2=true;
             }
             else if(x_mouse > 550 && x_mouse < 900 && y_mouse > 490 && y_mouse < 590)
             {
                 flag1=false;
                 flag10=true;

             }
             else if(x_mouse > 550 && x_mouse < 900 && y_mouse > 370 && y_mouse < 470)
             {
                 flag1=false;
                 flag11=true;
                 draw_table=true;
             }
             else if(x_mouse > 990 && x_mouse < 1140 && y_mouse > 645 && y_mouse < 695)
             {
                 flag1=false;
                 flag_aboutMe=true;
             }

              e->type = 0;
         }

    }


redraw=true;


     while(flag_aboutMe)
    {


        SDL_PollEvent(e);


        if(redraw)
        {
                texture(m_renderer,0,0,"settingBG2.png",1500,750);
                texture(m_renderer,20,660,"back.png",130,80);
                texture(m_renderer,100,70,"aboutMeText.png",1250,550);

                redraw=false;

                SDL_RenderPresent( m_renderer );
        }


        if(e->type==SDL_MOUSEBUTTONDOWN)
         {
             x_mouse=e->motion.x;
             y_mouse=e->motion.y;

             for(int i=0;i<8;i++)
            {
                aacircleRGBA(m_renderer,x_mouse,y_mouse,30*i/5,255,0,0,255);
            }
            redraw=true;

            SDL_RenderPresent(m_renderer);

            string chunk_sound = "resources\\mouse_button.ogg"; //Chunk sound Address
            Mix_Chunk *collision = Mix_LoadWAV(chunk_sound.c_str()); //Load sound for wall collision
            Mix_PlayChannel(-1,collision,0);


             if(x_mouse > 20 && x_mouse < 150 && y_mouse > 660 && y_mouse < 740 )
             {
                 flag_aboutMe=false;
                 flag1=true;

             }


         }

  e->type = 0;

    }

    redraw=true;


    while(flag2)
    {

        texture(m_renderer,0,0,"loadingBG.png",1500,750);
        boxRGBA(m_renderer,530,560,950,680,111,111,111,255);
        boxRGBA(m_renderer,0,700,1500,750,0,0,0,255);
        texture(m_renderer,540,570,"loadingtext.png",400,60);

        texture(m_renderer,520,100,"salah.png",670,460);
        texture(m_renderer,350,100,"lewandowski.png",500,460);
        texture(m_renderer,360,100,"ronaldo.png",750,460);




        SDL_RenderPresent( m_renderer );


        double m=0;

        string s="";

        double i=0;

        while(i<W)
        {
            aalineRGBA(m_renderer,i,700,i,750,0,255,0,255);

            m=double(i/W)*100;

            s=to_string((int)m);

            s+=" %";

            const char * text_percentage_of_loading =s.c_str();

            boxRGBA(m_renderer,540,630,939,670,0,0,0,255);

            textColor(m_renderer,720,623,text_percentage_of_loading,font_address_02 ,font_size,text_color_setting_loading,angle,NONE);

            SDL_RenderPresent( m_renderer );

            i+=.42;
        }

            flag2=false;
            flag3=true;

    }

    redraw=true;


    quit_enter_name=false;




    while(flag3)
    {


        SDL_PollEvent(e);



        if(redraw)
        {

                start_clock_player1_setting=clock();

                texture(m_renderer,0,0,"settingBG.png",1500,750);
                texture(m_renderer,1350,650,"next.png",130,80);
                texture(m_renderer,20,650,"back.png",130,80);
                texture(m_renderer,950,25,"settingtext1.png",535,270);


                boxRGBA(m_renderer,950,320,1485,415,255,255,0,255);
                boxRGBA(m_renderer,960,330,1475,405,255,255,255,255);



                redraw=false;

                SDL_RenderPresent( m_renderer );


        }


        if(clock()-start_clock_player1_setting>=200)
        {
            start_clock_player1_setting=clock();

            if(counter_play_playing_player1=='0')
            {
               // boxRGBA(m_renderer,x_player1+40,y_player1-320,x_player1+120+W_player1+200,y_player1-360+H_player1+400,0,255,0,255);
              counter_play_playing_player1='1';
            }
            else
            {
                //boxRGBA(m_renderer,x_player1+40,y_player1-320,x_player1+120+W_player1+200,y_player1-360+H_player1+400,0,255,0,255);
                counter_play_playing_player1='0';
            }

        }

                if(counter_setting_player1=='1')
                {
                    string player1="player1";
                    player1.push_back(counter_setting_player1);
                    player1.push_back(counter_play_playing_player1);
                    player1+=".png";
                    texture(m_renderer,0,0,"settingBG11.png",553,750);
                    texture(m_renderer,20,650,"back.png",130,80);
                    texture(m_renderer,x_player1+70,y_player1-300,player1,W_player1+120,H_player1+300);
                    texture(m_renderer,20,15,"player12_setting.png",170,200);
                    texture(m_renderer,20,225,"player13_setting.png",170,200);
                    texture(m_renderer,20,435,"player14_setting.png",170,200);
                    texture(m_renderer,x_player1+70,y_player1-300-130,"power1.png",W_player1+170,100);
                    SDL_RenderPresent( m_renderer );
                }
                else if(counter_setting_player1=='2')
                {
                    string player1="player1";
                    player1.push_back(counter_setting_player1);
                    player1.push_back(counter_play_playing_player1);
                    player1+=".png";
                    texture(m_renderer,0,0,"settingBG11.png",553,750);
                    texture(m_renderer,20,650,"back.png",130,80);
                    texture(m_renderer,x_player1+70,y_player1-300,player1,W_player1+120,H_player1+300);
                    texture(m_renderer,20,15,"player13_setting.png",170,200);
                    texture(m_renderer,20,225,"player14_setting.png",170,200);
                    texture(m_renderer,20,435,"player11_setting.png",170,200);
                    texture(m_renderer,x_player1+70,y_player1-300-130,"power2.png",W_player1+170,100);
                    SDL_RenderPresent( m_renderer );
                }
                else if(counter_setting_player1=='3')
                {
                    string player1="player1";
                    player1.push_back(counter_setting_player1);
                    player1.push_back(counter_play_playing_player1);
                    player1+=".png";
                    texture(m_renderer,0,0,"settingBG11.png",553,750);
                    texture(m_renderer,20,650,"back.png",130,80);
                    texture(m_renderer,x_player1+70,y_player1-300,player1,W_player1+120,H_player1+300);
                    texture(m_renderer,20,15,"player12_setting.png",170,200);
                    texture(m_renderer,20,225,"player14_setting.png",170,200);
                    texture(m_renderer,20,435,"player11_setting.png",170,200);
                    texture(m_renderer,x_player1+70,y_player1-300-130,"power3.png",W_player1+170,100);
                    SDL_RenderPresent( m_renderer );
                }
                else if(counter_setting_player1=='4')
                {
                    string player1="player1";
                    player1.push_back(counter_setting_player1);
                    player1.push_back(counter_play_playing_player1);
                    player1+=".png";
                    texture(m_renderer,0,0,"settingBG11.png",553,750);
                    texture(m_renderer,20,650,"back.png",130,80);
                    texture(m_renderer,x_player1+70,y_player1-300,player1,W_player1+120,H_player1+300);
                    texture(m_renderer,20,15,"player12_setting.png",170,200);
                    texture(m_renderer,20,225,"player13_setting.png",170,200);
                    texture(m_renderer,20,435,"player11_setting.png",170,200);
                    texture(m_renderer,x_player1+70,y_player1-300-130,"power4.png",W_player1+170,100);
                    SDL_RenderPresent( m_renderer );
                }


        if(e->type==SDL_MOUSEBUTTONDOWN)
         {
             x_mouse=e->motion.x;
             y_mouse=e->motion.y;

             for(int i=0;i<8;i++)
            {
                aacircleRGBA(m_renderer,x_mouse,y_mouse,30*i/5,255,0,0,255);
            }

            SDL_RenderPresent(m_renderer);

            string chunk_sound = "resources\\mouse_button.ogg"; //Chunk sound Address
            Mix_Chunk *collision = Mix_LoadWAV(chunk_sound.c_str()); //Load sound for wall collision
            Mix_PlayChannel(-1,collision,0);


                if(counter_setting_player1=='1')
                {
                    if(x_mouse > 20 && x_mouse < 190 && y_mouse > 15 && y_mouse < 215 )
                    {
                        counter_setting_player1='2';
                    }
                    else if(x_mouse > 20 && x_mouse < 190 && y_mouse > 225 && y_mouse < 425 )
                    {
                         counter_setting_player1='3';
                    }
                    else if(x_mouse > 20 && x_mouse < 190 && y_mouse > 435 && y_mouse < 635 )
                    {
                         counter_setting_player1='4';
                    }
                }
                else if(counter_setting_player1=='2')
                {
                    if(x_mouse > 20 && x_mouse < 190 && y_mouse > 15 && y_mouse < 215 )
                    {
                        counter_setting_player1='3';
                    }
                    else if(x_mouse > 20 && x_mouse < 190 && y_mouse > 225 && y_mouse < 425 )
                    {
                         counter_setting_player1='4';
                    }
                    else if(x_mouse > 20 && x_mouse < 190 && y_mouse > 435 && y_mouse < 635 )
                    {
                         counter_setting_player1='1';
                    }
                }
                else if(counter_setting_player1=='3')
                {
                    if(x_mouse > 20 && x_mouse < 190 && y_mouse > 15 && y_mouse < 215 )
                    {
                        counter_setting_player1='2';
                    }
                    else if(x_mouse > 20 && x_mouse < 190 && y_mouse > 225 && y_mouse < 425 )
                    {
                         counter_setting_player1='4';
                    }
                    else if(x_mouse > 20 && x_mouse < 190 && y_mouse > 435 && y_mouse < 635 )
                    {
                         counter_setting_player1='1';
                    }
                }
                else if(counter_setting_player1=='4')
                {
                    if(x_mouse > 20 && x_mouse < 190 && y_mouse > 15 && y_mouse < 215 )
                    {
                        counter_setting_player1='2';
                    }
                    else if(x_mouse > 20 && x_mouse < 190 && y_mouse > 225 && y_mouse < 425 )
                    {
                         counter_setting_player1='3';
                    }
                    else if(x_mouse > 20 && x_mouse < 190 && y_mouse > 435 && y_mouse < 635 )
                    {
                         counter_setting_player1='1';
                    }
                }



               if(x_mouse > 1350 && x_mouse < 1480 && y_mouse > 650 && y_mouse < 730 )
               {
                 flag3=false;
                 flag4=true;
               }
               else if(x_mouse >950 && x_mouse < 1485 && y_mouse > 320 && y_mouse < 415 )
               {

                        boxRGBA(m_renderer,950,320,1485,415,255,0,0,255);
                        boxRGBA(m_renderer,960,330,1475,405,255,255,255,255);

                        name_player1="";
                        caps_lock = false;
                        quit_enter_name = false ;
                        draw_table=true;
                        ch=0;
                        SDL_Event *event = new SDL_Event();
                        while (!quit_enter_name)
                        {
                            SDL_RenderPresent(m_renderer);
                            if(SDL_PollEvent(event))
                            {
                                if(event -> type == SDL_KEYUP)
                                {
                                    switch(event->key.keysym.sym)
                                    {
//                                        case SDLK_SPACE:
//                                        quit_enter_name = true;
//                                        break;
                                        case SDLK_RETURN:
                                        quit_enter_name = true;
                                        break;
                                        case SDLK_CAPSLOCK:
                                        ch=0;
                                        if(!caps_lock)
                                        caps_lock = true;
                                        else
                                        caps_lock = false;
                                        break;
                                        case SDLK_BACKSPACE:
                                        ch = 0;
                                        if(name_player1.length()!=0)
                                        {
                                        textColor(m_renderer,970,330, name_player1.c_str(),font_address_02 ,font_size_enter_name,text_color_setting_loading2,angle,NONE);

                                        name_player1 = name_player1.substr(0,name_player1.length()-1);
                                        }

                                        break;
                                        default :
                                        if(event->key.keysym.sym != SDLK_UP && event->key.keysym.sym != SDLK_DOWN && event->key.keysym.sym != SDLK_LEFT && event->key.keysym.sym != SDLK_RIGHT)
                                        ch = event->key.keysym.sym;
                                        break;
                                    }
                                    if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || ch==' ' && name_player1.length()<18 && !quit_enter_name)
                                    {
                                        if(caps_lock )
                                        name_player1+=ch + 'A' - 'a';
                                        else
                                        name_player1+=ch ;

                                        if(ch==' ')
                                            name_player1+=ch ;
                                    }
                                    if(name_player1 != "" && !quit_enter_name)
                                    textColor(m_renderer,970,330, name_player1.c_str(),font_address_02 ,font_size_enter_name,text_color_setting_loading,angle,NONE);
                                }
                            }
                        }

                        if(quit_enter_name &&  name_player1!="")
                        {
                            last_char_of_name_player1_help=name_player1.length()-1;
                            name_player1_help="";
                            for(int p=0;p<last_char_of_name_player1_help;p++)
                            {
                                name_player1_help+=name_player1[p];

                            }
                        }


              if(draw_table)
               {

               k=0;num=0;asami[100];table;
               ever_played_player1=false;


                    ifstream names("names.txt");
                    while (names.good())
                    {
                     names>>asami[k];

                     if( name_player1_help==asami[k])
                        {
                             directer_ever_played_player1=k;

                             ever_played_player1=true;

                        }


                     k++;
                     num++;
                    }
                    names.close();

                    if(ever_played_player1)
                    {



                    string tedad_bord;
                    ifstream nbord("num_of_wins.txt");
                    if (nbord.good())
                    {
                           for (int i=0;i<directer_ever_played_player1;i++)
                           {
                               nbord>>tedad_bord;
                           }
                           nbord>>tedad_bord;
                           nbord.close();
                    }
                    ifstream ngoalzade("num_of_goal_scores.txt");
                    string tedad_goal_zade;
                    if (ngoalzade.good())
                    {
                        for (int i=0;i<directer_ever_played_player1;i++)
                        {
                            ngoalzade>>tedad_goal_zade;
                        }
                        ngoalzade>>tedad_goal_zade;

                        ngoalzade.close();
                    }
                    ifstream ngoalkhorde("num_of_goal_concedes.txt");
                    string tedad_goal_khorde;
                    if (ngoalkhorde.good())
                    {
                        for (int i=0;i<directer_ever_played_player1;i++)
                        {
                            ngoalkhorde>>tedad_goal_khorde;
                        }
                        ngoalkhorde>>tedad_goal_khorde;
                        ngoalkhorde.close();
                    }
                    string tedad_bakht;
                    ifstream nbakht("num_of_defeats.txt");
                    if (nbakht.good())
                    {
                           for (int i=0;i<directer_ever_played_player1;i++)
                           {
                               nbakht>>tedad_bakht;
                           }
                           nbakht>>tedad_bakht;
                           nbakht.close();
                    }
                    string tedad_mosavi;
                    ifstream nmosavi("num_of_drawns.txt");
                    if (nmosavi.good())
                    {
                           for (int i=0;i<directer_ever_played_player1;i++)
                           {
                               nmosavi>>tedad_mosavi;
                           }
                           nmosavi>>tedad_mosavi;
                           nmosavi.close();
                    }
                    string tedad_bazi;
                    ifstream nbazi("num_of_performances.txt");
                    if (nbazi.good())
                    {
                           for (int i=0;i<directer_ever_played_player1;i++)
                           {
                               nbazi>>tedad_bazi;
                           }
                           nbazi>>tedad_bazi;
                           nbazi.close();
                    }
                    string tedad_tafazol_goal;
                    ifstream ntafazol("num_of_goal_difference.txt");
                    if (ntafazol.good())
                    {
                           for (int i=0;i<directer_ever_played_player1;i++)
                           {
                               ntafazol>>tedad_tafazol_goal;
                           }
                           ntafazol>>tedad_tafazol_goal;
                           ntafazol.close();
                    }
                    string emtiazha;
                    ifstream emtiaz("num_of_points.txt");
                    if (emtiaz.good())
                    {
                           for (int i=0;i<directer_ever_played_player1;i++)
                           {
                               emtiaz>>emtiazha;
                           }
                           emtiaz>>emtiazha;
                           emtiaz.close();
                    }

                    num=1;

                    boxRGBA(m_renderer,655,470,1498,610,90,90,90,255);
                    for(int f=1;f<=num;f++)
                    {
                        aalineRGBA(m_renderer,655,470+f*70,1498,540,255,0,0,255);

                        SDL_RenderPresent(m_renderer);
                    }
                    for(int f=1;f<=8;f++)
                    {
                        aalineRGBA(m_renderer,779+80*f,470,779+80*f,470+70*(num+1),255,0,0,255);
                        SDL_RenderPresent(m_renderer);
                    }
                    table="name";
                    textColor(m_renderer,675,480, table.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading,angle,NONE);
                    table="MP";
                    textColor(m_renderer,880,480, table.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading,angle,NONE);
                    table="W";
                    textColor(m_renderer,965,480, table.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading,angle,NONE);
                    table="P";
                    textColor(m_renderer,1050,480, table.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading,angle,NONE);
                    table="L";
                    textColor(m_renderer,1130,480, table.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading,angle,NONE);
                    table="GF";
                    textColor(m_renderer,1200,480, table.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading,angle,NONE);
                    table="GA";
                    textColor(m_renderer,1280,480, table.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading,angle,NONE);
                    table="GD";
                    textColor(m_renderer,1360,480, table.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading,angle,NONE);
                    table="PTs";
                    textColor(m_renderer,1435,480, table.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading,angle,NONE);

                    textColor(m_renderer,675,545, name_player1_help.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading2,angle,NONE);
                    textColor(m_renderer,885,545, tedad_bazi.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading2,angle,NONE);
                    textColor(m_renderer,965,545, tedad_bord.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading2,angle,NONE);
                    textColor(m_renderer,1045,545, tedad_mosavi.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading2,angle,NONE);
                    textColor(m_renderer,1125,545, tedad_bakht.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading2,angle,NONE);
                    textColor(m_renderer,1205,545, tedad_goal_zade.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading2,angle,NONE);
                    textColor(m_renderer,1285,545, tedad_goal_khorde.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading2,angle,NONE);
                    textColor(m_renderer,1365,545, tedad_tafazol_goal.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading2,angle,NONE);
                    textColor(m_renderer,1450,545, emtiazha.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading2,angle,NONE);

                    }
                    else
                    {

                        texture(m_renderer,700,460,"no_find_player.png",600,270);

                        SDL_RenderPresent(m_renderer);

                    }



                    draw_table=false;

               }



                        if( name_player1=="")
                        {
                             name_player1="UnKnown";
                        }
               }

                else if(x_mouse >20 && x_mouse < 150 && y_mouse > 650 && y_mouse < 730 )
               {
                 flag3=false;
                 flag1=true;
               }

         }

        if( name_player1=="")
        {
            name_player1_help="UnKnown";
        }

        e->type = 0;

    }


    redraw=true;


    quit_enter_name=false;

    while(flag4)
    {

        SDL_PollEvent(e);


        if(redraw)
        {
             start_clock_player2_setting=clock();
                texture(m_renderer,0,0,"settingBG.png",1500,750);
                texture(m_renderer,1350,660,"next.png",130,80);
                texture(m_renderer,20,660,"back.png",130,80);
                texture(m_renderer,15,15,"settingtext2.png",540,280);


                 boxRGBA(m_renderer,10,320,550,415,255,255,0,255);
                 boxRGBA(m_renderer,20,330,540,405,255,255,255,255);

                redraw=false;

                SDL_RenderPresent( m_renderer );
        }



        if(clock()-start_clock_player2_setting>=200)
        {
            start_clock_player2_setting=clock();

            if(counter_play_playing_player2=='0')
            {
               // boxRGBA(m_renderer,x_player1+40,y_player1-320,x_player1+120+W_player1+200,y_player1-360+H_player1+400,0,255,0,255);
              counter_play_playing_player2='1';
            }
            else
            {
                //boxRGBA(m_renderer,x_player1+40,y_player1-320,x_player1+120+W_player1+200,y_player1-360+H_player1+400,0,255,0,255);
                counter_play_playing_player2='0';
            }

        }

                if(counter_setting_player2=='1')
                {
                    string player2="player2";
                    player2.push_back(counter_setting_player2);
                    player2.push_back(counter_play_playing_player2);
                    player2+=".png";
                    texture(m_renderer,944,0,"settingBG12.png",556,750);
                    texture(m_renderer,1350,650,"next.png",130,80);
                    texture(m_renderer,1310-x_player1-100,y_player1-300,player2,W_player1+120,H_player1+300);
                    texture(m_renderer,1310,15,"player22_setting.png",170,200);
                    texture(m_renderer,1310,225,"player23_setting.png",170,200);
                    texture(m_renderer,1310,435,"player24_setting.png",170,200);
                    texture(m_renderer,1310-x_player1-150,y_player1-300-130,"power1.png",W_player1+170,100);
                    SDL_RenderPresent( m_renderer );
                }
                else if(counter_setting_player2=='2')
                {
                    string player2="player2";
                    player2.push_back(counter_setting_player2);
                    player2.push_back(counter_play_playing_player2);
                    player2+=".png";
                    texture(m_renderer,944,0,"settingBG12.png",556,750);
                    texture(m_renderer,1350,650,"next.png",130,80);
                    texture(m_renderer,1310-x_player1-100,y_player1-300,player2,W_player1+120,H_player1+300);
                    texture(m_renderer,1310,15,"player23_setting.png",170,200);
                    texture(m_renderer,1310,225,"player24_setting.png",170,200);
                    texture(m_renderer,1310,435,"player21_setting.png",170,200);
                    texture(m_renderer,1310-x_player1-150,y_player1-300-130,"power2.png",W_player1+170,100);
                    SDL_RenderPresent( m_renderer );
                }
                else if(counter_setting_player2=='3')
                {
                    string player2="player2";
                    player2.push_back(counter_setting_player2);
                    player2.push_back(counter_play_playing_player2);
                    player2+=".png";
                    texture(m_renderer,944,0,"settingBG12.png",556,750);
                    texture(m_renderer,1350,650,"next.png",130,80);
                    texture(m_renderer,1310-x_player1-100,y_player1-300,player2,W_player1+120,H_player1+300);
                    texture(m_renderer,1310,15,"player22_setting.png",170,200);
                    texture(m_renderer,1310,225,"player24_setting.png",170,200);
                    texture(m_renderer,1310,435,"player21_setting.png",170,200);
                    texture(m_renderer,1310-x_player1-150,y_player1-300-130,"power3.png",W_player1+170,100);
                    SDL_RenderPresent( m_renderer );
                }
                else if(counter_setting_player2=='4')
                {
                    string player2="player2";
                    player2.push_back(counter_setting_player2);
                    player2.push_back(counter_play_playing_player2);
                    player2+=".png";
                    texture(m_renderer,944,0,"settingBG12.png",556,750);
                    texture(m_renderer,1350,650,"next.png",130,80);
                    texture(m_renderer,1310-x_player1-100,y_player1-300,player2,W_player1+120,H_player1+300);
                    texture(m_renderer,1310,15,"player22_setting.png",170,200);
                    texture(m_renderer,1310,225,"player23_setting.png",170,200);
                    texture(m_renderer,1310,435,"player21_setting.png",170,200);
                    texture(m_renderer,1310-x_player1-150,y_player1-300-130,"power4.png",W_player1+170,100);
                    SDL_RenderPresent( m_renderer );
                }



                                           // textColor(m_renderer,970,340, name_player1.c_str(),font_address_02 ,font_size,text_color_setting_loading2,angle,NONE);


        if(e->type==SDL_MOUSEBUTTONDOWN)
         {
             x_mouse=e->motion.x;
             y_mouse=e->motion.y;

             for(int i=0;i<8;i++)
            {
                aacircleRGBA(m_renderer,x_mouse,y_mouse,30*i/5,255,0,0,255);
            }

            SDL_RenderPresent(m_renderer);

            string chunk_sound = "resources\\mouse_button.ogg"; //Chunk sound Address
            Mix_Chunk *collision = Mix_LoadWAV(chunk_sound.c_str()); //Load sound for wall collision
            Mix_PlayChannel(-1,collision,0);


             if(x_mouse > 1350 && x_mouse < 1480 && y_mouse > 650 && y_mouse < 730 )
             {
                 flag4=false;
                 flag5=true;
             }
             else if(x_mouse >10 && x_mouse < 550 && y_mouse > 320 && y_mouse < 415 )
               {

                         boxRGBA(m_renderer,10,320,550,415,255,0,0,255);
                         boxRGBA(m_renderer,20,330,540,405,255,255,255,255);


                        name_player2="";

                        caps_lock = false;
                        quit_enter_name = false ;
                        draw_table=true;
                        ch=0;
                        SDL_Event *event = new SDL_Event();
                        while (!quit_enter_name)
                        {
                            SDL_RenderPresent(m_renderer);
                            if(SDL_PollEvent(event))
                            {
                                if(event -> type == SDL_KEYUP)
                                {
                                    switch(event->key.keysym.sym)
                                    {
//                                        case SDLK_SPACE:
//                                        quit_enter_name = true;
//                                        break;
                                        case SDLK_RETURN:
                                        quit_enter_name = true;
                                        break;
                                        case SDLK_CAPSLOCK:
                                        ch=0;
                                        if(!caps_lock)
                                        caps_lock = true;
                                        else
                                        caps_lock = false;
                                        break;
                                        case SDLK_BACKSPACE:
                                        ch = 0;
                                        if(name_player2.length()!=0)
                                        {
                                        textColor(m_renderer,30,330, name_player2.c_str(),font_address_02 ,font_size_enter_name,text_color_setting_loading2,angle,NONE);
                    //                    textColor(m_renderer,720,623,text_percentage_of_loading,font_address_02 ,font_size,text_color_setting_loading,angle,NONE);
                    //                    textRGBA(m_renderer,x_position +20 , y_position +H-105 , name.c_str(), font+1 , 75 , 255 ,255 ,255 , A);
                                        name_player2 = name_player2.substr(0,name_player2.length()-1);
                                        }

                                        break;
                                        default :
                                        if(event->key.keysym.sym != SDLK_UP && event->key.keysym.sym != SDLK_DOWN && event->key.keysym.sym != SDLK_LEFT && event->key.keysym.sym != SDLK_RIGHT)
                                        ch = event->key.keysym.sym;
                                        break;
                                    }
                                    if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || ch==' ' && name_player2.length()<16 && !quit_enter_name)
                                    {
                                        if(caps_lock )
                                        name_player2+=ch + 'A' - 'a';
                                        else
                                        name_player2+=ch ;

                                        if(ch==' ')
                                            name_player2+=ch ;
                                    }
                                    if(name_player2 != "" && !quit_enter_name)
                                    textColor(m_renderer,30,330, name_player2.c_str(),font_address_02 ,font_size_enter_name,text_color_setting_loading,angle,NONE);
                                }
                            }
                        }

                        if(quit_enter_name && name_player2!="")
                        {
                            last_char_of_name_player2_help=name_player2.length()-1;
                            name_player2_help="";
                            for(int p=0;p<last_char_of_name_player2_help;p++)
                            {
                                name_player2_help+=name_player2[p];

                            }
                        }


              if(draw_table)
               {

               k=0;num=0;asami[100];table;
               ever_played_player2=false;


                    ifstream names("names.txt");
                    while (names.good())
                    {
                     names>>asami[k];

                     if( name_player2_help==asami[k])
                        {
                             directer_ever_played_player2=k;

                             ever_played_player2=true;


                        }


                     k++;
                     num++;
                    }
                    names.close();

                    if(ever_played_player2)
                    {



                    string tedad_bord;
                    ifstream nbord("num_of_wins.txt");
                    if (nbord.good())
                    {
                           for (int i=0;i<directer_ever_played_player2;i++)
                           {
                               nbord>>tedad_bord;
                           }
                           nbord>>tedad_bord;
                           nbord.close();
                    }
                    ifstream ngoalzade("num_of_goal_scores.txt");
                    string tedad_goal_zade;
                    if (ngoalzade.good())
                    {
                        for (int i=0;i<directer_ever_played_player2;i++)
                        {
                            ngoalzade>>tedad_goal_zade;
                        }
                        ngoalzade>>tedad_goal_zade;

                        ngoalzade.close();
                    }
                    ifstream ngoalkhorde("num_of_goal_concedes.txt");
                    string tedad_goal_khorde;
                    if (ngoalkhorde.good())
                    {
                        for (int i=0;i<directer_ever_played_player2;i++)
                        {
                            ngoalkhorde>>tedad_goal_khorde;
                        }
                        ngoalkhorde>>tedad_goal_khorde;
                        ngoalkhorde.close();
                    }
                    string tedad_bakht;
                    ifstream nbakht("num_of_defeats.txt");
                    if (nbakht.good())
                    {
                           for (int i=0;i<directer_ever_played_player2;i++)
                           {
                               nbakht>>tedad_bakht;
                           }
                           nbakht>>tedad_bakht;
                           nbakht.close();
                    }
                    string tedad_mosavi;
                    ifstream nmosavi("num_of_drawns.txt");
                    if (nmosavi.good())
                    {
                           for (int i=0;i<directer_ever_played_player2;i++)
                           {
                               nmosavi>>tedad_mosavi;
                           }
                           nmosavi>>tedad_mosavi;
                           nmosavi.close();
                    }
                    string tedad_bazi;
                    ifstream nbazi("num_of_performances.txt");
                    if (nbazi.good())
                    {
                           for (int i=0;i<directer_ever_played_player2;i++)
                           {
                               nbazi>>tedad_bazi;
                           }
                           nbazi>>tedad_bazi;
                           nbazi.close();
                    }
                    string tedad_tafazol_goal;
                    ifstream ntafazol("num_of_goal_difference.txt");
                    if (ntafazol.good())
                    {
                           for (int i=0;i<directer_ever_played_player2;i++)
                           {
                               ntafazol>>tedad_tafazol_goal;
                           }
                           ntafazol>>tedad_tafazol_goal;
                           ntafazol.close();
                    }
                    string emtiazha;
                    ifstream emtiaz("num_of_points.txt");
                    if (emtiaz.good())
                    {
                           for (int i=0;i<directer_ever_played_player2;i++)
                           {
                               emtiaz>>emtiazha;
                           }
                           emtiaz>>emtiazha;
                           emtiaz.close();
                    }


                    num=1;

                    boxRGBA(m_renderer,2,470,845,610,90,90,90,255);
                    for(int f=1;f<=num;f++)
                    {
                        aalineRGBA(m_renderer,2,470+f*70,845,540,255,0,0,255);

                        SDL_RenderPresent(m_renderer);
                    }
                    for(int f=1;f<=8;f++)
                    {
                        aalineRGBA(m_renderer,126+80*f,470,126+80*f,470+70*(num+1),255,0,0,255);
                        SDL_RenderPresent(m_renderer);
                    }
                    table="name";
                    textColor(m_renderer,22,480, table.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading,angle,NONE);
                    table="MP";
                    textColor(m_renderer,225,480, table.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading,angle,NONE);
                    table="W";
                    textColor(m_renderer,312,480, table.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading,angle,NONE);
                    table="P";
                    textColor(m_renderer,397,480, table.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading,angle,NONE);
                    table="L";
                    textColor(m_renderer,477,480, table.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading,angle,NONE);
                    table="GF";
                    textColor(m_renderer,550,480, table.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading,angle,NONE);
                    table="GA";
                    textColor(m_renderer,625,480, table.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading,angle,NONE);
                    table="GD";
                    textColor(m_renderer,702,480, table.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading,angle,NONE);
                    table="PTs";
                    textColor(m_renderer,777,480, table.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading,angle,NONE);

                    textColor(m_renderer,22,545, name_player2_help.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading2,angle,NONE);
                    textColor(m_renderer,232,545, tedad_bazi.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading2,angle,NONE);
                    textColor(m_renderer,318,545, tedad_bord.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading2,angle,NONE);
                    textColor(m_renderer,394,545, tedad_mosavi.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading2,angle,NONE);
                    textColor(m_renderer,478,545, tedad_bakht.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading2,angle,NONE);
                    textColor(m_renderer,558,545, tedad_goal_zade.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading2,angle,NONE);
                    textColor(m_renderer,638,545, tedad_goal_khorde.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading2,angle,NONE);
                    textColor(m_renderer,718,545, tedad_tafazol_goal.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading2,angle,NONE);
                    textColor(m_renderer,792,545, emtiazha.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading2,angle,NONE);




                    }
                    else
                    {

                        texture(m_renderer,200,460,"no_find_player.png",600,270);

                        SDL_RenderPresent(m_renderer);

                    }

                        draw_table=false;



               }


                        if( name_player2=="")
                        {
                             name_player2_help="UnKnown";
                        }
               }
            else if(x_mouse >20 && x_mouse < 150 && y_mouse > 650 && y_mouse < 730 )
             {
                 flag4=false;
                 flag3=true;
             }

                if(counter_setting_player2=='1')
                {
                    if(x_mouse > 1310 && x_mouse < 1480 && y_mouse > 15 && y_mouse < 215 )
                    {
                        counter_setting_player2='2';
                    }
                    else if(x_mouse > 1310 && x_mouse < 1480 && y_mouse > 225 && y_mouse < 425 )
                    {
                         counter_setting_player2='3';
                    }
                    else if(x_mouse > 1310 && x_mouse < 1480 && y_mouse > 435 && y_mouse < 635 )
                    {
                         counter_setting_player2='4';
                    }
                }
                else if(counter_setting_player2=='2')
                {
                    if(x_mouse > 1310 && x_mouse < 1480 && y_mouse > 15 && y_mouse < 215 )
                    {
                        counter_setting_player2='3';
                    }
                    else if(x_mouse > 1310 && x_mouse < 1480 && y_mouse > 225 && y_mouse < 425 )
                    {
                         counter_setting_player2='4';
                    }
                    else if(x_mouse > 1310 && x_mouse < 1480 && y_mouse > 435 && y_mouse < 635 )
                    {
                         counter_setting_player2='1';
                    }
                }
                else if(counter_setting_player2=='3')
                {
                    if(x_mouse > 1310 && x_mouse < 1480 && y_mouse > 15 && y_mouse < 215 )
                    {
                        counter_setting_player2='2';
                    }
                    else if(x_mouse > 1310 && x_mouse < 1480 && y_mouse > 225 && y_mouse < 425 )
                    {
                         counter_setting_player2='4';
                    }
                    else if(x_mouse > 1310 && x_mouse < 1480 && y_mouse > 435 && y_mouse < 635 )
                    {
                         counter_setting_player2='1';
                    }
                }
                else if(counter_setting_player2=='4')
                {
                    if(x_mouse > 1310 && x_mouse < 1480 && y_mouse > 15 && y_mouse < 215 )
                    {
                        counter_setting_player2='2';
                    }
                    else if(x_mouse > 1310 && x_mouse < 1480 && y_mouse > 225 && y_mouse < 425 )
                    {
                         counter_setting_player2='3';
                    }
                    else if(x_mouse > 1310 && x_mouse < 1480 && y_mouse > 435 && y_mouse < 635 )
                    {
                         counter_setting_player2='1';
                    }
                }

         }

        if( name_player2=="")
        {
            name_player2="UnKnown";
        }

  e->type = 0;

    }

    redraw=true;


    while(flag5)
    {


        SDL_PollEvent(e);


        if(redraw)
        {
                texture(m_renderer,0,0,"settingBG2.png",1500,750);
                texture(m_renderer,1350,660,"next.png",130,80);
                texture(m_renderer,20,660,"back.png",130,80);
                texture(m_renderer,900,10,"stadium_setting_text.png",530,163);


                texture(m_renderer,0,25,"stadium_setting1.png",800,220);
                texture(m_renderer,175,265,"stadium_setting2.png",800,220);
                texture(m_renderer,350,505,"stadium_setting3.png",800,220);

                redraw=false;

                SDL_RenderPresent( m_renderer );
        }


        if(e->type==SDL_MOUSEBUTTONDOWN)
         {
             x_mouse=e->motion.x;
             y_mouse=e->motion.y;

             for(int i=0;i<8;i++)
            {
                aacircleRGBA(m_renderer,x_mouse,y_mouse,30*i/5,255,0,0,255);
            }
            redraw=true;

            SDL_RenderPresent(m_renderer);

            string chunk_sound = "resources\\mouse_button.ogg"; //Chunk sound Address
            Mix_Chunk *collision = Mix_LoadWAV(chunk_sound.c_str()); //Load sound for wall collision
            Mix_PlayChannel(-1,collision,0);


             if(x_mouse > 1350 && x_mouse < 1480 && y_mouse > 650 && y_mouse < 730 )
             {
                 flag5=false;
                 flag6=true;

             }
            else if(x_mouse > 20 && x_mouse < 150 && y_mouse > 650 && y_mouse < 730 )
             {
                 flag5=false;
                 flag4=true;

             }
                 else if(x_mouse > 175 && x_mouse < 975 && y_mouse > 265 && y_mouse < 485 )
                {
                    counter_setting_stadium='2';
                }

                else if(x_mouse > 350 && x_mouse < 1150 && y_mouse > 505 && y_mouse < 775 )
                {
                    counter_setting_stadium='3';
                }

         }

  e->type = 0;

    }

    redraw=true;


    while(flag6)
    {


        SDL_PollEvent(e);


        if(redraw)
        {
                texture(m_renderer,0,0,"settingBG2.png",1500,750);
                texture(m_renderer,1350,660,"next.png",130,80);
                texture(m_renderer,20,660,"back.png",130,80);
                texture(m_renderer,100,50,"ball_setting_text.png",625,200);



                boxRGBA(m_renderer,200,275,400,475,70,70,0,255);
                boxRGBA(m_renderer,425,275,625,475,70,70,0,255);
                boxRGBA(m_renderer,200,500,400,700,70,70,0,255);
                boxRGBA(m_renderer,425,500,625,700,70,70,0,255);



                texture(m_renderer,205,280,"ball11.png",190,190);
                texture(m_renderer,430,280,"ball21.png",190,190);
                texture(m_renderer,205,505,"ball31.png",190,190);
                texture(m_renderer,430,505,"ball41.png",190,190);



                redraw=false;

                SDL_RenderPresent( m_renderer );
        }




        if(e->type==SDL_MOUSEBUTTONDOWN)
         {
             x_mouse=e->motion.x;
             y_mouse=e->motion.y;

             for(int i=0;i<8;i++)
            {
                aacircleRGBA(m_renderer,x_mouse,y_mouse,30*i/5,255,0,0,255);
            }

            redraw=true;
            SDL_RenderPresent(m_renderer);

            string chunk_sound = "resources\\mouse_button.ogg"; //Chunk sound Address
            Mix_Chunk *collision = Mix_LoadWAV(chunk_sound.c_str()); //Load sound for wall collision
            Mix_PlayChannel(-1,collision,0);


             if(x_mouse > 1350 && x_mouse < 1480 && y_mouse > 650 && y_mouse < 730 )
             {
                 flag6=false;
                 flag7=true;
             }

            else if(x_mouse > 20 && x_mouse < 150 && y_mouse > 650 && y_mouse < 730 )
             {
                 flag6=false;
                 flag5=true;
             }

                else if(x_mouse > 425 && x_mouse < 625 && y_mouse >275 && y_mouse < 475 )
                {
                    counter_setting_ball='2';
                }
                else if(x_mouse > 200 && x_mouse < 400 && y_mouse > 500 && y_mouse < 700 )
                {
                    counter_setting_ball='3';
                }

                else if(x_mouse > 425 && x_mouse < 625 && y_mouse > 500 && y_mouse < 700 )
                {
                    counter_setting_ball='4';
                }




         }

  e->type = 0;

    }

redraw=true;


    while(flag7)
    {


        SDL_PollEvent(e);


        if(redraw)
        {
                texture(m_renderer,0,0,"settingBG2.png",1500,750);
                texture(m_renderer,1350,660,"next.png",130,80);
                texture(m_renderer,20,660,"back.png",130,80);
                texture(m_renderer,100,50,"setTime_setting.png",625,200);




                boxRGBA(m_renderer,200,275,400,475,255,150,50,255);
                boxRGBA(m_renderer,425,275,625,475,255,150,50,255);
                boxRGBA(m_renderer,200,500,400,700,255,150,50,255);
                boxRGBA(m_renderer,425,500,625,700,255,150,50,255);



                texture(m_renderer,120,275,"setTimer1.png",360,200);
                texture(m_renderer,345,275,"setTimer2.png",360,200);
                texture(m_renderer,120,500,"setTimer3.png",360,200);
                texture(m_renderer,345,500,"setTimer4.png",360,200);



                redraw=false;

                SDL_RenderPresent( m_renderer );
        }




        if(e->type==SDL_MOUSEBUTTONDOWN)
         {
             x_mouse=e->motion.x;
             y_mouse=e->motion.y;

             for(int i=0;i<8;i++)
            {
                aacircleRGBA(m_renderer,x_mouse,y_mouse,30*i/5,255,0,0,255);
            }
            redraw=true;

            SDL_RenderPresent(m_renderer);

            string chunk_sound = "resources\\mouse_button.ogg"; //Chunk sound Address
            Mix_Chunk *collision = Mix_LoadWAV(chunk_sound.c_str()); //Load sound for wall collision
            Mix_PlayChannel(-1,collision,0);


             if(x_mouse > 1350 && x_mouse < 1480 && y_mouse > 650 && y_mouse < 730 )
             {
                 flag7=false;
                 flag_ads=true;
             }

            if(x_mouse > 20 && x_mouse < 150 && y_mouse > 650 && y_mouse < 730 )
             {
                 flag7=false;
                 flag6=true;
             }

                else if(x_mouse > 425 && x_mouse < 625 && y_mouse >275 && y_mouse < 475 )
                {
                    setTime=120; setTime0=120;
                }
                else if(x_mouse > 200 && x_mouse < 400 && y_mouse > 500 && y_mouse < 700 )
                {
                    setTime=150;setTime0=150;
                }

                else if(x_mouse > 425 && x_mouse < 625 && y_mouse > 500 && y_mouse < 700 )
                {
                    setTime=180;setTime0=180;
                }




         }

  e->type = 0;

    }

    redraw=true;

    while(flag_ads)
    {


        SDL_PollEvent(e);


        if(redraw)
        {
                texture(m_renderer,0,0,"settingBG2.png",1500,750);
                boxRGBA(m_renderer,30,20,1350,670,90,90,90,255);
                texture(m_renderer,50,40,"ads.png",500,80);
                texture(m_renderer,80,150,"brick1.png",400,400);
                texture(m_renderer,530,150,"brick2.png",400,400);
                texture(m_renderer,700,560,"brick3.png",500,95);

                texture(m_renderer,1350,660,"next.png",130,80);
                texture(m_renderer,20,660,"back.png",130,80);


                redraw=false;

                SDL_RenderPresent( m_renderer );
        }




        if(e->type==SDL_MOUSEBUTTONDOWN)
         {
             x_mouse=e->motion.x;
             y_mouse=e->motion.y;

             for(int i=0;i<8;i++)
            {
                aacircleRGBA(m_renderer,x_mouse,y_mouse,30*i/5,255,0,0,255);
            }

            SDL_RenderPresent(m_renderer);

            string chunk_sound = "resources\\mouse_button.ogg"; //Chunk sound Address
            Mix_Chunk *collision = Mix_LoadWAV(chunk_sound.c_str()); //Load sound for wall collision
            Mix_PlayChannel(-1,collision,0);


             if(x_mouse > 1350 && x_mouse < 1480 && y_mouse > 650 && y_mouse < 730 )
             {
                 flag_ads=false;
                 flag_ads2=true;

                 sound = "resources\\finished.mp3";
                 GameSound = Mix_LoadMUS(sound.c_str());
                 Mix_PlayMusic(GameSound,-1);
             }

            if(x_mouse > 20 && x_mouse < 150 && y_mouse > 650 && y_mouse < 730 )
             {
                 flag_ads=false;
                 flag7=true;
             }




         }

  e->type = 0;

    }

    redraw=true;

    while(flag_ads2)
    {



                        if(redraw)
                        {
                                texture(m_renderer,0,0,"settingBG2.png",1500,750);

                                redraw=false;

                                SDL_RenderPresent( m_renderer );
                        }

        char chp=49;

                    for(chp=49;chp<58;chp++)
                    {
                        string video;
                        //if(chp<10)
                        //video="ezgif-frame-00";
                        //else
                        video="finished\\ezgif-frame-00";
                        //string shp=to_sting(jj);
                        //char chp=shp.c_str();
                        video.push_back(chp);
                        video+=".png";

                        texture(m_renderer,200,50,video,1100,650);

                        SDL_RenderPresent(m_renderer);SDL_Delay(91);


                    }

                    for(chp=48;chp<58;chp++)
                    {
                        string video;
                        //if(chp<10)
                        //video="ezgif-frame-00";
                        //else
                        video="finished\\ezgif-frame-01";
                        //string shp=to_sting(jj);
                        //char chp=shp.c_str();
                        video.push_back(chp);
                        video+=".png";

                        texture(m_renderer,200,50,video,1100,650); SDL_RenderPresent(m_renderer);SDL_Delay(91);



                    }

                    for(chp=48;chp<58;chp++)
                    {
                        string video;
                        //if(chp<10)
                        //video="ezgif-frame-00";
                        //else
                        video="finished\\ezgif-frame-02";
                        //string shp=to_sting(jj);
                        //char chp=shp.c_str();
                        video.push_back(chp);
                        video+=".png";

                        texture(m_renderer,200,50,video,1100,650); SDL_RenderPresent(m_renderer);SDL_Delay(91);



                    }

                    for(chp=48;chp<58;chp++)
                    {
                        string video;
                        //if(chp<10)
                        //video="ezgif-frame-00";
                        //else
                        video="finished\\ezgif-frame-03";
                        //string shp=to_sting(jj);
                        //char chp=shp.c_str();
                        video.push_back(chp);
                        video+=".png";

                        texture(m_renderer,200,50,video,1100,650); SDL_RenderPresent(m_renderer);SDL_Delay(91);



                    }



                    for(chp=48;chp<58;chp++)
                    {
                        string video;
                        //if(chp<10)
                        //video="ezgif-frame-00";
                        //else
                        video="finished\\ezgif-frame-04";
                        //string shp=to_sting(jj);
                        //char chp=shp.c_str();
                        video.push_back(chp);
                        video+=".png";

                        texture(m_renderer,200,50,video,1100,650); SDL_RenderPresent(m_renderer);SDL_Delay(90);



                    }

                    for(chp=48;chp<56;chp++)
                    {
                        string video;
                        //if(chp<10)
                        //video="ezgif-frame-00";
                        //else
                        video="finished\\ezgif-frame-05";
                        //string shp=to_sting(jj);
                        //char chp=shp.c_str();
                        video.push_back(chp);
                        video+=".png";

                        texture(m_renderer,200,50,video,1100,650);SDL_RenderPresent(m_renderer);SDL_Delay(90);



                    }

                    flag_ads2=false;
                    flag8=true;


    }


    redraw=true;

    if(flag8)
    {
                 sound = "resources\\7.mp3";
                 GameSound = Mix_LoadMUS(sound.c_str());
                 Mix_PlayMusic(GameSound,-1);
    }


    while(flag8)
    {


        SDL_PollEvent(e);


        if(redraw)
        {
                texture(m_renderer,0,0,"settingBG2.png",1500,750);


                boxRGBA(m_renderer,530,560,950,680,111,111,111,255);
                boxRGBA(m_renderer,0,700,1500,750,0,0,0,255);

                texture(m_renderer,540,570,"loadingtext.png",400,60);

                texture(m_renderer,250,100,"benzema.png",500,460);
                texture(m_renderer,360,80,"messi.png",750,480);
                texture(m_renderer,570,80,"rois.png",670,480);

        SDL_RenderPresent( m_renderer );

          double m=0;

        string s="";

        double i=0;

        while(i<W)
        {
            aalineRGBA(m_renderer,i,700,i,750,0,255,0,255);

            m=double(i/W)*100;

            s=to_string((int)m);

            s+=" %";

            const char * text_percentage_of_loading2 =s.c_str();



            boxRGBA(m_renderer,540,630,939,670,0,0,0,255);

            if(help)
            {
                textColor(m_renderer,720,623,text_percentage_of_loading2,font_address_02 ,font_size,text_color_setting_loading,angle,NONE);


            }



            SDL_RenderPresent( m_renderer );

            i+=.42;


        }


   help=false;

            texture(m_renderer,0,0,"settingBG2.png",1500,750);

             boxRGBA(m_renderer,520,550,960,700,111,111,111,255);

            texture(m_renderer,530,560,"kickoff_text.png",420,130);

                redraw=false;

                SDL_RenderPresent( m_renderer );
        }




        if(e->type==SDL_MOUSEBUTTONDOWN)
         {
             x_mouse=e->motion.x;
             y_mouse=e->motion.y;

             for(int i=0;i<8;i++)
            {
                aacircleRGBA(m_renderer,x_mouse,y_mouse,30*i/5,255,0,0,255);
            }

            SDL_RenderPresent(m_renderer);

            string chunk_sound = "resources\\mouse_button.ogg"; //Chunk sound Address
            Mix_Chunk *collision = Mix_LoadWAV(chunk_sound.c_str()); //Load sound for wall collision
            Mix_PlayChannel(-1,collision,0);


             if(x_mouse > 530 && x_mouse < 950  && y_mouse > 560 && y_mouse < 690 )
             {
                 flag8=false;
                 flag_setting_compile_game=true;

                 sound = "resources\\stadium.mp3";
                 GameSound = Mix_LoadMUS(sound.c_str());
                 Mix_PlayMusic(GameSound,-1);

             }

         }

  e->type = 0;

    }

    redraw=true;

    string player1="player1";
    player1.push_back(counter_setting_player1);
    player1.push_back(counter_play_playing_player1);
    player1+=".png";

    string player2="player2";
    player2.push_back(counter_setting_player2);
    player2.push_back(counter_play_playing_player2);
    player2+=".png";

    string stadium="stadium";
    stadium.push_back(counter_setting_stadium);
    stadium+=".png";

    string ball="ball";
    ball.push_back(counter_setting_ball);
    ball.push_back(counter_play_ball);
    ball+=".png";
    start_clock_ball=clock();


start_clocking_full_time_game=clock();

    while(flag_setting_compile_game)
    {


        if(y_player1>480)
        {
            y_player1=480;
        }
        else if(y_player1<200)
        {
            dy_player1=-dy_player1;
            y_player1=200;
        }
        if(x_player1<50)
        {
            x_player1=50;
        }
        else if(x_player1>1350)
        {
            x_player1=1350;

        }


        if(y_player2>480)
        {
            y_player2=480;
        }
        else if(y_player2<200)
        {
            dy_player2=-dy_player2;
            y_player2=200;
        }
        if(x_player2<50)
        {
            x_player2=50;
        }
        else if(x_player2>1350)
        {
            x_player2=1350;

        }


        const Uint8 *keyboard_state_array = SDL_GetKeyboardState(NULL);

        SDL_PollEvent(e);
        SDL_PumpEvents();
        keyboard_state_array = SDL_GetKeyboardState(NULL);



            if (first_collision_ball)
            {
                y_ball+=40;
            }


            if( come_out_from_for)
            {
                if(first_collision_ball)
                {

                        if(y_ball>641 || y_ball<180)
                        {




                            first_collision_ball=false;
                            flag_first_collision_by_player=true;

                                if(firstWWW_collision_ball<5)
                                {
                                    firstWWW_collision_ball=rand();
                                        if(firstWWW_collision_ball%2==0)
                                        {
                                            dx_ball=-dx0_ball;
                                        }
                                }
                                else if(firstWWW_collision_ball==6)
                                {
                                    dx_ball=dx0_ball;
                                }
                                else if(firstWWW_collision_ball==7)
                                {
                                    dx_ball=-dx0_ball;
                                }


                        }

                }

                else
                {
                    if(y_ball<641 || y_ball>191)
                    {
                        if(flag_first_collision_by_player)
                        {
                           dy_ball+=1.57;

                        }
                        else if(!(dy_ball>more_control_dy_ball))
                            dy_ball+=dy_helpBall;



                    }

                    if(dy_ball+dy_helpBall>more_control_dy_ball)
                    {
                        more_control_dy_ball-=0.1;
                    }

                    y_ball+=dy_ball;
                    x_ball+=dx_ball;

                        if(y_ball>641 || y_ball<181)
                        {


                            if(y_ball>641)
                            {
                                y_ball=641;
                            }
                            else
                            y_ball=181;


                            if(abs(dy_ball)>2)
                            dy_ball=-dy_ball;
                            else
                            {
                                dy_ball*=2;
                                dy_ball=-dy_ball;
                            }



                        }


                }

                    if(x_ball<1 ||x_ball>1439 )
                        dx_ball=-dx_ball;

            }

                        if(!(flag_visible_ball))
                        {
                            if(y_ball_goal>=641)
                            {
                                if(x_ball_goal<750)
                                {
                                    dx_ball_goal=50;
                                    dy_ball_goal=-40;

                                }
                                else if(x_ball_goal>750)
                                {
                                    dx_ball_goal=-50;
                                    dy_ball_goal=-40;

                                }
                            }


                        }


                        y_ball_goal+=dy_ball_goal;
                        x_ball_goal+=dx_ball_goal;

                        if(y_ball_goal<=80)
                        {
                            if(x_ball_goal>700)
                            {
                                if(counter_goal_plyer2==0)
                                {
                                    counter_numGoal_player2='1';
                                    counter_goal_plyer2++;
                                }
                                else if(counter_goal_plyer2==1)
                                {
                                    counter_numGoal_player2='2';
                                    counter_goal_plyer2++;
                                }
                                else if(counter_goal_plyer2==2)
                                {
                                    counter_numGoal_player2='3';
                                    counter_goal_plyer2++;
                                }
                                else if(counter_goal_plyer2==3)
                                {
                                    counter_numGoal_player2='4';
                                    counter_goal_plyer2++;
                                }
                                else if(counter_goal_plyer2==4)
                                {
                                    counter_numGoal_player2='5';
                                    counter_goal_plyer2++;
                                }
                            }
                            else
                            {
                                if(counter_goal_plyer1==0)
                                {
                                    counter_numGoal_player1='1';
                                    counter_goal_plyer1++;
                                }
                                else if(counter_goal_plyer1==1)
                                {
                                    counter_numGoal_player1='2';
                                    counter_goal_plyer1++;
                                }
                                else if(counter_goal_plyer1==2)
                                {
                                    counter_numGoal_player1='3';
                                    counter_goal_plyer1++;
                                }
                                else if(counter_goal_plyer1==3)
                                {
                                    counter_numGoal_player1='4';
                                    counter_goal_plyer1++;
                                }
                                else if(counter_goal_plyer1==4)
                                {
                                    counter_numGoal_player1='5';
                                    counter_goal_plyer1++;
                                }

                            }
                            flag_visible_ball=true;
                            x_ball=x0_ball;
                            y_ball=y0_ball;
                            dx_ball=dx0_ball;
                            dy_ball=dy0_ball;
                            first_collision_ball=true;
                            y_ball_goal=500;
                            x_ball_goal=750;
                            dx_ball_goal=0;
                            dy_ball_goal=0;
                            x_player1=200;
                            x_player2=1200;
                            flag_help2_power_headfireball_player1=false;
                            flag_help3_power_headfireball_player1=false;
                            count_dx_player2=0;
                            flag_help4_power_headfireball_player1=false;
                            flag_help2_power_headfireball_player2=false;
                            flag_help3_power_headfireball_player2=false;
                            count_dx_player1=200;
                            flag_help4_power_headfireball_player2=false;

                            flag_help2_power_kickfireball_player1=false;
                            flag_help3_power_kickfireball_player1=false;
                            count_dx_player2=0;
                            flag_help4_power_kickfireball_player1=false;

                            flag_help2_power_kickfireball_player2=false;
                            flag_help3_power_kickfireball_player2=false;
                            count_dx_player1=200;
                            flag_help4_power_kickfireball_player2=false;


                            y_player1=480;
                            y_player2=480;


                            counter_play_playing_player1='0';
                            counter_play_playing_player2='0';



                            flag_power_invisibleball_player1=false,flag_help_power_invisibleball_kick_player1=false,flag_help2_power_invisibleball_kick_player1=false;
                            flag_help_power_invisibleball_head_player1=false,flag_help2_power_invisibleball_head_player1=false,flag_help3_power_invisibleball_head_player1=false,flag_help4_power_invisibleball_head_player1=false;


                            flag_power_invisibleball_player2=false,flag_help_power_invisibleball_kick_player2=false,flag_help2_power_invisibleball_kick_player2=false;
                            flag_help_power_invisibleball_head_player2=false,flag_help2_power_invisibleball_head_player2=false,flag_help3_power_invisibleball_head_player2=false,flag_help4_power_invisibleball_head_player2=false;

                            flag_power_punch_player1=false,flag_help_power_punch_player1=false,flag_help2_power_punch_player1=false;
                            start_clock_help_punch=0,start_clock_help2_punch=0;

                            w_punch=0;


                            flag_power_punch_player2=false,flag_help_power_punch_player2=false,flag_help2_power_punch_player2=false;
                            start_clock_help_punch2=0,start_clock_help2_punch2=0;


                            w_punch=0;

                            texture(m_renderer,385,0,"black.png",730,180);
                            texture(m_renderer,490,10,"yellow.png",182,160);
                            texture(m_renderer,828,10,"yellow.png",184,160);



                        }



                        if(counter_goal_plyer1==5 || counter_goal_plyer2==5 || (counter_goal_plyer1==4&&counter_goal_plyer2==4))
                        {

                            flag_setting_compile_game=false;
                            flag9=true;
                            save_result=true;

                            string sound = "resources\\9.mp3"; //Background sound Address

                            Mix_Music *GameSound = Mix_LoadMUS(sound.c_str()); //Load background sound

                            Mix_PlayMusic(GameSound,-1); //Play the sound.  -1 means play it till the end

                             x_timer=678;

                             y1_fans=110;
                y2_fans=170;y3_fans=230;y4_fans=290;


                        }

    string player1="player1";
    player1.push_back(counter_setting_player1);
    player1.push_back(counter_play_playing_player1);
    player1+=".png";

    string player2="player2";
    player2.push_back(counter_setting_player2);
    player2.push_back(counter_play_playing_player2);
    player2+=".png";

    string numGoal_player1="1";
    numGoal_player1.push_back(counter_numGoal_player1);
    numGoal_player1+=".png";

    string numGoal_player2="2";
    numGoal_player2.push_back(counter_numGoal_player2);
    numGoal_player2+=".png";

        if(counter_play_playing_player1=='0')
        {

        headplayer1.x=x_player1+32;
        headplayer1.y=y_player1+3;
        headplayer1.w=56;
        headplayer1.h=51;

        body1player1.x=x_player1+20;
        body1player1.y=y_player1 +46;
        body1player1.w=67;
        body1player1.h=54;

        body2player1.x=x_player1+24;
        body2player1.y=y_player1 + 100;
        body2player1.w=66;
        body2player1.h=70;

        footplayer1.x=x_player1+7;
        footplayer1.y=y_player1 + 168;
        footplayer1.w=45;
        footplayer1.h=51;


       ball_rect.x=x_ball;
        ball_rect.y=y_ball;
       ball_rect.w=60;
        ball_rect.h=60;



        if ( SDL_HasIntersection (& ball_rect , & headplayer1 ))
        {
                       if( clock()-control_hitsurface_player1>=500)
                       {
                           control_hitsurface_player1=clock();

                                        if(dx_ball<0 )
                                        {
                                            if( x_ball>headplayer1.x+(2.2*headplayer1.w/10))
                                            {
                                                dx_ball=-dx_ball;
                                                if(dy_ball>0)
                                                dy_ball=-dy_ball;
                                            }
                                            else
                                            {
                                                if(dy_ball>0)
                                                dy_ball=-dy_ball;
                                            }

                                        }

                                        else if(dx_ball>0)
                                        {

                                           if( x_ball<headplayer1.x+(2.2*headplayer1.w/10))
                                            {
                                                dx_ball=-dx_ball;
                                                if(dy_ball>0)
                                                dy_ball=-dy_ball;
                                            }
                                            else
                                            {
                                                if(dy_ball>0)
                                                dy_ball=-dy_ball;
                                            }
                                        }

                                        if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                        {
                                            dx_ball*=1.2;

                                        }
                                            clock_player_hit=clock();


                                        dy_ball=-15.5;


                                       first_collision_ball=false;flag_first_collision_by_player=false;


                                       if(flag_help3_power_headfireball_player2)
                                        {
                                            flag_help4_power_headfireball_player2=true;
                                            start_clock_help4_headfireball2=clock();
                                        }

                                        if(flag_help3_power_kickfireball_player2)
                                        {
                                            flag_help4_power_kickfireball_player2=true;
                                            start_clock_help4_kickfireball2=clock();
                                        }

                       }


        }
        else if ( SDL_HasIntersection (& ball_rect , & body1player1 ))
        {
            if(!(flag_help3_power_headfireball_player2) && !(flag_help3_power_kickfireball_player2))
              {
                        if( clock()-control_hitsurface_player1>=500)
                       {
                           control_hitsurface_player1=clock();

                                        dx_ball=-dx_ball;

                                        if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                        {
                                            dx_ball*=1.2;

                                        }
                                        clock_player_hit=clock();
                                        first_collision_ball=false;flag_first_collision_by_player=false;


                       }
              }




        }
        else if ( SDL_HasIntersection (& ball_rect , & body2player1 ))
        {
            if(!(flag_help3_power_headfireball_player2)&& !(flag_help3_power_kickfireball_player2))
              {
                        if( clock()-control_hitsurface_player1>=500)
                       {
                           control_hitsurface_player1=clock();


                                        dx_ball=-dx_ball;


                                        if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                        {
                                            dx_ball*=1.4;

                                        }

                                        clock_player_hit=clock();
                                        dy_ball=-1*abs(dx_ball*0.55); // tan 29 degree




                                        first_collision_ball=false;flag_first_collision_by_player=false;

                       }
              }


        }
        else if ( SDL_HasIntersection (& ball_rect , & footplayer1 ))
        {
            if(!(flag_help3_power_headfireball_player2)&& !(flag_help3_power_kickfireball_player2))
              {
                        if( clock()-control_hitsurface_player1>=500)
                       {
                           control_hitsurface_player1=clock();

                                        dx_ball=-dx_ball;


                                        if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                        {
                                            dx_ball*=1.4;

                                        }

                                        clock_player_hit=clock();
                                        dy_ball=-1*abs(dx_ball*0.55); // tan 29 degree

                                        if(y_ball>footplayer1.y+(7*(footplayer1.h/10)))
                                            dy_ball=abs(dx_ball*1);   // tan negeative 45 degree




                                        first_collision_ball=false;flag_first_collision_by_player=false;

                       }
              }

        }
        }

        else if(counter_play_playing_player1=='1')
        {

        headplayer1.x=x_player1+30;
        headplayer1.y=y_player1+4;
        headplayer1.w=55;
        headplayer1.h=42;

        body1player1.x=x_player1+7;
        body1player1.y=y_player1 + 44;
        body1player1.w=77;
        body1player1.h=60;


        body2player1.x=x_player1+11;
        body2player1.y=y_player1 + 105;
        body2player1.w=56;
        body2player1.h=72;


        footplayer1.x=x_player1+30;
        footplayer1.y=y_player1 + 177;
        footplayer1.w=30;
        footplayer1.h=42;



       ball_rect.x=x_ball;
        ball_rect.y=y_ball;
       ball_rect.w=60;
        ball_rect.h=60;




        if ( SDL_HasIntersection (& ball_rect , & headplayer1 ))
        {
                        if( clock()-control_hitsurface_player1>=500)
                       {
                           control_hitsurface_player1=clock();

                                        if(dx_ball<0 )
                                        {
                                            if( x_ball>headplayer1.x+(2.2*headplayer1.w/10))
                                            {
                                                dx_ball=-dx_ball;
                                                if(dy_ball>0)
                                                dy_ball=-dy_ball;
                                            }
                                            else
                                            {
                                                if(dy_ball>0)
                                                dy_ball=-dy_ball;
                                            }

                                        }

                                        else if(dx_ball>0)
                                        {

                                           if( x_ball<headplayer1.x+(2.2*headplayer1.w/10))
                                            {
                                                dx_ball=-dx_ball;
                                                if(dy_ball>0)
                                                dy_ball=-dy_ball;
                                            }
                                            else
                                            {
                                                if(dy_ball>0)
                                                dy_ball=-dy_ball;
                                            }
                                        }


                                        if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                        {
                                            dx_ball*=1.2;

                                        }
                                        dy_ball=-15.5;



                                        clock_player_hit=clock();

                                       first_collision_ball=false;flag_first_collision_by_player=false;


                                       if(flag_help3_power_headfireball_player2)
                                        {
                                            flag_help4_power_headfireball_player2=true;
                                            start_clock_help4_headfireball2=clock();
                                        }

                                        if(flag_help3_power_kickfireball_player2)
                                        {
                                            flag_help4_power_kickfireball_player2=true;
                                            start_clock_help4_kickfireball2=clock();
                                        }


                       }
        }
        else if ( SDL_HasIntersection (& ball_rect , & body1player1 ))
        {
            if(!(flag_help3_power_headfireball_player2)&& !(flag_help3_power_kickfireball_player2))
              {
                        if( clock()-control_hitsurface_player1>=500)
                       {
                           control_hitsurface_player1=clock();

                                        dx_ball=-dx_ball;

                                        if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                        {
                                            dx_ball*=1.2;
                                            clock_player_hit=clock();
                                        }

                                       first_collision_ball=false;flag_first_collision_by_player=false;


                       }
              }
        }
        else if ( SDL_HasIntersection (& ball_rect , & body2player1 ))
        {

               if(!(flag_help3_power_headfireball_player2)&& !(flag_help3_power_kickfireball_player2))
              {
                           if( clock()-control_hitsurface_player1>=500)
                       {
                           control_hitsurface_player1=clock();

                                        dx_ball=-dx_ball;

                                        if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                        {
                                            dx_ball*=1.4;

                                        }
                                        clock_player_hit=clock();

                                        dy_ball=-1*abs(dx_ball*0.55); // tan 29 degree


                                       first_collision_ball=false;flag_first_collision_by_player=false;


                       }
              }
        }
        else if ( SDL_HasIntersection (& ball_rect , & footplayer1 ))
        {
              if(!(flag_help3_power_headfireball_player2)&& !(flag_help3_power_kickfireball_player2))
              {

                            if( clock()-control_hitsurface_player1>=500)
                       {
                           control_hitsurface_player1=clock();

                                        dx_ball=-dx_ball;

                                        if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                        {
                                            dx_ball*=1.4;

                                        }
                                        clock_player_hit=clock();

                                        dy_ball=-1*abs(dx_ball*0.55); // tan 29 degree

                                        if(y_ball>footplayer1.y+(7*(footplayer1.h/10)))
                                            dy_ball=abs(dx_ball*1);   // tan negeative 45 degree


                                        first_collision_ball=false;flag_first_collision_by_player=false;



                       }
              }

        }
        }


        else if(counter_play_playing_player1=='2')
        {

        headplayer1.x=x_player1+40;
        headplayer1.y=y_player1+3;
        headplayer1.w=47;
        headplayer1.h=48;

        body1player1.x=x_player1+12;
        body1player1.y=y_player1 + 50;
        body1player1.w=80;
        body1player1.h=43;

        body2player1.x=x_player1+26;
        body2player1.y=y_player1 + 93;
        body2player1.w=60;
        body2player1.h=80;

        footplayer1.x=x_player1+64;
        footplayer1.y=y_player1 + 174;
        footplayer1.w=40;
        footplayer1.h=54;



       ball_rect.x=x_ball;
        ball_rect.y=y_ball;
       ball_rect.w=60;
        ball_rect.h=80;



        if ( SDL_HasIntersection (& ball_rect , & headplayer1 ))
        {


                       if( clock()-control_hitsurface_player1>=500)
                       {
                           control_hitsurface_player1=clock();

                                        if(dx_ball<0 )
                                        {
                                            if( x_ball>headplayer1.x+(2.2*headplayer1.w/10))
                                            {
                                                dx_ball=-dx_ball;
                                                if(dy_ball>0)
                                                dy_ball=-dy_ball;
                                            }
                                            else
                                            {
                                                if(dy_ball>0)
                                                dy_ball=-dy_ball;
                                            }

                                        }

                                        else if(dx_ball>0)
                                        {

                                           if( x_ball<headplayer1.x+(2.2*headplayer1.w/10))
                                            {
                                                dx_ball=-dx_ball;
                                                if(dy_ball>0)
                                                dy_ball=-dy_ball;
                                            }
                                            else
                                            {
                                                if(dy_ball>0)
                                                dy_ball=-dy_ball;
                                            }
                                        }

                                        if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                        {
                                            dx_ball*=1.2;

                                        }

                                        dy_ball=-15.5;



                                        clock_player_hit=clock();
                                        //dy_ball=-1.5*abs(dx_ball*0.55);


                                        first_collision_ball=false;flag_first_collision_by_player=false;

                                        if(flag_help3_power_headfireball_player2)
                                        {
                                            flag_help4_power_headfireball_player2=true;
                                            start_clock_help4_headfireball2=clock();
                                        }

                                        if(flag_help3_power_kickfireball_player2)
                                        {
                                            flag_help4_power_kickfireball_player2=true;
                                            start_clock_help4_kickfireball2=clock();
                                        }


                       }



        }
        else if ( SDL_HasIntersection (& ball_rect , & body1player1 ))
        {
            if(!(flag_help3_power_headfireball_player2)&& !(flag_help3_power_kickfireball_player2))
              {

                    if( clock()-control_hitsurface_player1>=500)
                       {
                           control_hitsurface_player1=clock();

                                        dx_ball=-dx_ball;

                                        if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                        {
                                            dx_ball*=1.2;

                                        }

                                        clock_player_hit=clock();

                                        first_collision_ball=false;flag_first_collision_by_player=false;
                       }
              }


        }
        else if ( SDL_HasIntersection (& ball_rect , & body2player1 ))
        {
            if(!(flag_help3_power_headfireball_player2)&& !(flag_help3_power_kickfireball_player2))
              {

                        if( clock()-control_hitsurface_player1>=500)
                       {
                           control_hitsurface_player1=clock();

                                        dx_ball=-dx_ball;

                                        if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                        {
                                            dx_ball*=2.1;

                                        }

                                        clock_player_hit=clock();

                                        dy_ball=-21; // tan 34 degree



                                        first_collision_ball=false;flag_first_collision_by_player=false;
                       }
              }
        }
        else if ( SDL_HasIntersection (& ball_rect , & footplayer1 ))
        {
            if(!(flag_help3_power_headfireball_player2)&& !(flag_help3_power_kickfireball_player2))
              {

                        if( clock()-control_hitsurface_player1>=500)
                       {
                           control_hitsurface_player1=clock();

                                        dx_ball=-dx_ball;

                                        if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                        {
                                            dx_ball*=2.1;
                                            clock_player_hit=clock();
                                        }
                                        else if(abs(dx_ball)==1.4*abs(dx0_ball))
                                        {
                                            dx_ball*=1.4;
                                            clock_player_hit=clock();

                                        }
                                        clock_player_hit=clock();

                                        dy_ball=-21; // tan 34 degree

                                        if(y_ball>footplayer1.y+(7*(footplayer1.h/10)))
                                            dy_ball=abs(dx_ball*1);   // tan negeative 45 degree


                                        first_collision_ball=false;flag_first_collision_by_player=false;


                       }
              }
        }
        }

        if(counter_play_playing_player2=='0')
        {

        headplayer2.x=x_player2+9;
        headplayer2.y=y_player2+3;
        headplayer2.w=68;
        headplayer2.h=61;


        body1player2.x=x_player2+13;
        body1player2.y=y_player2 + 63;
        body1player2.w=81;
        body1player2.h=61;

        body2player2.x=x_player2+31;
        body2player2.y=y_player2 + 125;
        body2player2.w=56;
        body2player2.h=54;

        footplayer2.x=x_player2+42;
        footplayer2.y=y_player2 + 179;
        footplayer2.w=31;
        footplayer2.h=40;



       ball_rect.x=x_ball;
        ball_rect.y=y_ball;
       ball_rect.w=60;
        ball_rect.h=60;


        if ( SDL_HasIntersection (& ball_rect , & headplayer2))
        {
                        if( clock()-control_hitsurface_player2>=500)
                       {
                           control_hitsurface_player2=clock();

                                        if(dx_ball<0 )
                                        {
                                            if( x_ball>headplayer2.x+(5*headplayer2.w/10))
                                            {
                                                dx_ball=-dx_ball;
                                                if(dy_ball>0)
                                                dy_ball=-dy_ball;
                                            }
                                            else
                                            {
                                                if(dy_ball>0)
                                                dy_ball=-dy_ball;
                                            }

                                        }

                                        else if(dx_ball>0)
                                        {

                                           if( x_ball<headplayer2.x+(2.2*headplayer2.w/10))
                                            {
                                                dx_ball=-dx_ball;
                                                if(dy_ball>0)
                                                dy_ball=-dy_ball;
                                            }
                                            else
                                            {
                                                if(dy_ball>0)
                                                dy_ball=-dy_ball;
                                            }
                                        }


                                        if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                        {
                                            dx_ball*=1.2;
                                            clock_player_hit=clock();
                                        }

                                        clock_player_hit=clock();

                                        dy_ball=-15.5;



                                        //dy_ball=-1.5*abs(dx_ball*0.55);



                                first_collision_ball=false;flag_first_collision_by_player=false;


                                if(flag_help3_power_headfireball_player1)
                                {
                                    flag_help4_power_headfireball_player1=true;
                                    start_clock_help4_headfireball=clock();
                                }

                                if(flag_help3_power_kickfireball_player1)
                                {
                                    flag_help4_power_kickfireball_player1=true;
                                    start_clock_help4_kickfireball=clock();
                                }
                       }
        }
        else if ( SDL_HasIntersection (& ball_rect , & body1player2 ))
        {
              if(!(flag_help3_power_headfireball_player1)&& !(flag_help3_power_kickfireball_player1))
              {


                        if( clock()-control_hitsurface_player2>=500)
                       {
                           control_hitsurface_player2=clock();

                                        dx_ball=-dx_ball;

                                        if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                        {
                                            dx_ball*=1.2;
                                            clock_player_hit=clock();
                                        }

                                        clock_player_hit=clock();


                                        first_collision_ball=false;flag_first_collision_by_player=false;
                       }
              }

        }
        else if ( SDL_HasIntersection (& ball_rect , & body2player2 ))
        {
            if(!(flag_help3_power_headfireball_player1)&& !(flag_help3_power_kickfireball_player1))
              {
                        if( clock()-control_hitsurface_player2>=500)
                       {
                           control_hitsurface_player2=clock();

                                        dx_ball=-dx_ball;

                                        if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                        {
                                            dx_ball*=1.4;
                                            clock_player_hit=clock();
                                        }

                                        clock_player_hit=clock();

                                        dy_ball=-1*abs(dx_ball*0.55); // tan 29 degree

                                        first_collision_ball=false;flag_first_collision_by_player=false;


                       }
              }
        }
        else if ( SDL_HasIntersection (& ball_rect , & footplayer2 ))
        {
            if(!(flag_help3_power_headfireball_player1)&& !(flag_help3_power_kickfireball_player1))
              {
                        if( clock()-control_hitsurface_player2>=500)
                       {
                           control_hitsurface_player2=clock();

                                        dx_ball=-dx_ball;

                                        if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                        {
                                            dx_ball*=1.4;
                                            clock_player_hit=clock();
                                        }

                                        clock_player_hit=clock();
                                        dy_ball=-1*abs(dx_ball*0.55); // tan 29 degree

                                        if(y_ball>footplayer1.y+(7*(footplayer1.h/10)))
                                            dy_ball=abs(dx_ball*1);   // tan negeative 45 degree


                                        first_collision_ball=false;flag_first_collision_by_player=false;

                       }
              }

        }
        }

        else if(counter_play_playing_player2=='1')
        {
        headplayer2.x=x_player2+8;
        headplayer2.y=y_player2+3;
        headplayer2.w=70;
        headplayer2.h=65;


        body1player2.x=x_player2+12;
        body1player2.y=y_player2 + 64;
        body1player2.w=69;
        body1player2.h=81;


        body2player2.x=x_player2+2;
        body2player2.y=y_player2 + 145;
        body2player2.w=75;
        body2player2.h=36;

        footplayer2.x=x_player2+50;
        footplayer2.y=y_player2 + 182;
        footplayer2.w=45;
        footplayer2.h=38;


       ball_rect.x=x_ball;
        ball_rect.y=y_ball;
       ball_rect.w=60;
        ball_rect.h=60;



        if ( SDL_HasIntersection (& ball_rect , & headplayer2))
        {
                        if( clock()-control_hitsurface_player2>=500)
                       {
                           control_hitsurface_player2=clock();

                                        if(dx_ball<0 )
                                        {
                                            if( x_ball>headplayer2.x+(5*headplayer2.w/10))
                                            {
                                                dx_ball=-dx_ball;
                                                if(dy_ball>0)
                                                dy_ball=-dy_ball;
                                            }
                                            else
                                            {
                                                if(dy_ball>0)
                                                dy_ball=-dy_ball;
                                            }

                                        }

                                        else if(dx_ball>0)
                                        {

                                           if( x_ball<headplayer2.x+(2.2*headplayer2.w/10))
                                            {
                                                dx_ball=-dx_ball;
                                                if(dy_ball>0)
                                                dy_ball=-dy_ball;
                                            }
                                            else
                                            {
                                                if(dy_ball>0)
                                                dy_ball=-dy_ball;
                                            }
                                        }

                                        if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                        {
                                            dx_ball*=1.2;
                                            clock_player_hit=clock();
                                        }

                                        dy_ball=-15.5;

                                        clock_player_hit=clock();

                                        //dy_ball=-1.5*abs(dx_ball*0.55);


                                        if(flag_help3_power_headfireball_player1)
                                        {
                                            flag_help4_power_headfireball_player1=true;
                                            start_clock_help4_headfireball=clock();
                                        }

                                        if(flag_help3_power_kickfireball_player1)
                                        {
                                            flag_help4_power_kickfireball_player1=true;
                                            start_clock_help4_kickfireball=clock();
                                        }


                                     first_collision_ball=false;flag_first_collision_by_player=false;
                       }

        }
        else if ( SDL_HasIntersection (& ball_rect , & body1player2 ))
        {
            if(!(flag_help3_power_headfireball_player1)&& !(flag_help3_power_kickfireball_player1))
              {
                        if( clock()-control_hitsurface_player2>=500)
                       {
                           control_hitsurface_player2=clock();

                                        dx_ball=-dx_ball;

                                        if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                        {
                                            dx_ball*=1.2;
                                            clock_player_hit=clock();
                                        }

                                       first_collision_ball=false;flag_first_collision_by_player=false;

                       }
              }
        }
        else if ( SDL_HasIntersection (& ball_rect , & body2player2 ))
        {
            if(!(flag_help3_power_headfireball_player1)&& !(flag_help3_power_kickfireball_player1))
              {
                        if( clock()-control_hitsurface_player2>=500)
                       {
                           control_hitsurface_player2=clock();

                                        dx_ball=-dx_ball;

                                        if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                        {
                                            dx_ball*=1.4;
                                            clock_player_hit=clock();
                                        }
                                        clock_player_hit=clock();

                                        dy_ball=-1*abs(dx_ball*0.55); // tan 29 degree

                                        first_collision_ball=false;flag_first_collision_by_player=false;
                       }
              }
        }
        else if ( SDL_HasIntersection (& ball_rect , & footplayer2 ))
        {

                 if(!(flag_help3_power_headfireball_player1)&& !(flag_help3_power_kickfireball_player1))
              {
                         if( clock()-control_hitsurface_player2>=500)
                       {
                           control_hitsurface_player2=clock();

                                        dx_ball=-dx_ball;

                                        if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                        {
                                            dx_ball*=1.4;
                                            clock_player_hit=clock();
                                        }
                                        clock_player_hit=clock();

                                        dy_ball=-1*abs(dx_ball*0.55); // tan 29 degree

                                        if(y_ball>footplayer1.y+(7*(footplayer1.h/10)))
                                            dy_ball=abs(dx_ball*1);   // tan negeative 45 degree


                                        first_collision_ball=false;flag_first_collision_by_player=false;

                       }
              }
        }
        }

        if(counter_play_playing_player2=='2')
        {


        headplayer2.x=x_player2+42;
        headplayer2.y=y_player2+3;
        headplayer2.w=58;
        headplayer2.h=50;

        body1player2.x=x_player2+30;
        body1player2.y=y_player2 + 51;
        body1player2.w=92;
        body1player2.h=55;


        body2player2.x=x_player2+55;
        body2player2.y=y_player2 + 107;
        body2player2.w=55;
        body2player2.h=67;

        footplayer2.x=x_player2+30;
        footplayer2.y=y_player2 + 174;
        footplayer2.w=35;
        footplayer2.h=35;



       ball_rect.x=x_ball;
        ball_rect.y=y_ball;
       ball_rect.w=60;
        ball_rect.h=60;


        if ( SDL_HasIntersection (& ball_rect , & headplayer2))
        {
                    if( clock()-control_hitsurface_player2>=500)
                       {
                           control_hitsurface_player2=clock();

                                        if(dx_ball<0 )
                                        {
                                            if( x_ball>headplayer2.x+(7.8*headplayer2.w/10))
                                            {
                                                dx_ball=-dx_ball;
                                                if(dy_ball>0)
                                                dy_ball=-dy_ball;
                                            }
                                            else
                                            {
                                                if(dy_ball>0)
                                                dy_ball=-dy_ball;
                                            }

                                        }

                                        else if(dx_ball>0)
                                        {

                                           if( x_ball<headplayer2.x+(2.2*headplayer2.w/10))
                                            {
                                                dx_ball=-dx_ball;
                                                if(dy_ball>0)
                                                dy_ball=-dy_ball;
                                            }
                                            else
                                            {
                                                if(dy_ball>0)
                                                dy_ball=-dy_ball;
                                            }
                                        }

                                        if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                        {
                                            dx_ball*=1.2;
                                            clock_player_hit=clock();
                                        }
                                        clock_player_hit=clock();


                                        dy_ball=-15.5;

                                       // dy_ball=-1.5*abs(dx_ball*0.55);


                                       if(flag_help3_power_headfireball_player1)
                                        {
                                            flag_help4_power_headfireball_player1=true;
                                            start_clock_help4_headfireball=clock();
                                        }


                                        if(flag_help3_power_kickfireball_player1)
                                        {
                                            flag_help4_power_kickfireball_player1=true;
                                            start_clock_help4_kickfireball=clock();
                                        }


                                        first_collision_ball=false;flag_first_collision_by_player=false;
                       }
        }
        else if ( SDL_HasIntersection (& ball_rect , & body1player2 ))
        {
            if(!(flag_help3_power_headfireball_player1)&& !(flag_help3_power_kickfireball_player1))
              {
                        if( clock()-control_hitsurface_player2>=500)
                       {
                           control_hitsurface_player2=clock();

                                        dx_ball=-dx_ball;

                                        if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                        {
                                            dx_ball*=1.2;
                                            clock_player_hit=clock();
                                        }

                                        clock_player_hit=clock();

                                       first_collision_ball=false;flag_first_collision_by_player=false;

                       }
              }
        }
        else if ( SDL_HasIntersection (& ball_rect , & body2player2 ))
        {
            if(!(flag_help3_power_headfireball_player1)&& !(flag_help3_power_kickfireball_player1))
              {
                    if( clock()-control_hitsurface_player2>=500)
                       {
                           control_hitsurface_player2=clock();

                                        dx_ball=-dx_ball;

                                        if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                        {
                                            dx_ball*=2.1;
                                            clock_player_hit=clock();
                                        }

                                        clock_player_hit=clock();

                                        dy_ball=-21; // tan 34 degree


                                        first_collision_ball=false;flag_first_collision_by_player=false;
                       }
              }
        }
        else if ( SDL_HasIntersection (& ball_rect , & footplayer2 ))
        {
            if(!(flag_help3_power_headfireball_player1)&& !(flag_help3_power_kickfireball_player1))
              {
                    if( clock()-control_hitsurface_player2>=500)
                       {
                           control_hitsurface_player2=clock();

                                        dx_ball=-dx_ball;

                                        if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                        {
                                            dx_ball*=2.1;
                                            clock_player_hit=clock();
                                        }
                                        else if(abs(dx_ball)==1.4*abs(dx0_ball))
                                        {
                                            dx_ball*=1.4;
                                            clock_player_hit=clock();

                                        }

                                        clock_player_hit=clock();

                                        dy_ball=-21; // tan 34 degree

                                        if(y_ball>footplayer1.y+(7*(footplayer1.h/10)))
                                            dy_ball=abs(dx_ball*1);   // tan negeative 45 degree

                                        first_collision_ball=false;flag_first_collision_by_player=false;
                       }
              }

        }
        }

        rect_top_goal_first.x=105;
        rect_top_goal_first.y=310;
        rect_top_goal_first.w=73;
        rect_top_goal_first.h=40;


        rect_top_goal_second.x=1320;
        rect_top_goal_second.y=310;
        rect_top_goal_second.w=73;
        rect_top_goal_second.h=40;


        ball_rect.x=x_ball;
        ball_rect.y=y_ball;
        ball_rect.w=60;
        ball_rect.h=60;


         if ( SDL_HasIntersection (& ball_rect , & rect_top_goal_first))
        {

                                        dx_ball=-dx_ball;
                                        dy_ball=-dy_ball;

                                        hasintersection=true;first_collision_ball=false;

                                        string chunk_sound = "resources\\oh.ogg"; //Chunk sound Address
            Mix_Chunk *collision = Mix_LoadWAV(chunk_sound.c_str()); //Load sound for wall collision
            Mix_PlayChannel(-1,collision,0);


        }
        else if ( SDL_HasIntersection (& ball_rect , & rect_top_goal_second ))
        {
                        dx_ball=-dx_ball;
                                        dy_ball=-dy_ball;

                                        hasintersection=true;first_collision_ball=false;

                                        string chunk_sound = "resources\\oh.ogg"; //Chunk sound Address
            Mix_Chunk *collision = Mix_LoadWAV(chunk_sound.c_str()); //Load sound for wall collision
            Mix_PlayChannel(-1,collision,0);

        }

        rect_beside_box1.x=0;
        rect_beside_box1.y=310;
        rect_beside_box1.w=110;
        rect_beside_box1.h=40;


        rect_beside_box2.x=1390;
        rect_beside_box2.y=310;
        rect_beside_box2.w=110;
        rect_beside_box2.h=40;


        ball_rect.x=x_ball;
        ball_rect.y=y_ball;
        ball_rect.w=60;
        ball_rect.h=60;


         if ( SDL_HasIntersection (& ball_rect , & rect_beside_box1))
        {

                                        dx_ball=-dx_ball;
                                        dy_ball=-abs(dy_ball);

                                        hasintersection=true;first_collision_ball=false;

        }
        else if ( SDL_HasIntersection (& ball_rect , & rect_beside_box2 ))
        {
                        dx_ball=-dx_ball;
                                        dy_ball=-abs(dy_ball);

                                        hasintersection=true;first_collision_ball=false;
        }

        rect_detect_goal_player1.x=50;
        rect_detect_goal_player1.y=350;
        rect_detect_goal_player1.w=90;
        rect_detect_goal_player1.h=350;


        rect_detect_goal_player2.x=1360;
        rect_detect_goal_player2.y=350;
        rect_detect_goal_player2.w=90;
        rect_detect_goal_player2.h=350;


        ball_rect.x=x_ball;
        ball_rect.y=y_ball;
        ball_rect.w=60;
        ball_rect.h=60;


         if ( SDL_HasIntersection (& ball_rect , & rect_detect_goal_player1))
        {
            string chunk_sound = "resources\\goal.ogg"; //Chunk sound Address
            Mix_Chunk *collision = Mix_LoadWAV(chunk_sound.c_str()); //Load sound for wall collision
            Mix_PlayChannel(-1,collision,0);

                                        flag_visible_ball=false;
                                        dx_ball_goal=0;
                                        dy_ball_goal=25;
                                        x_ball_goal=x_ball;
                                        y_ball_goal=y_ball;
                                        dx_ball=0;
                                        dy_ball=0;
                                        x_ball=750;
                                        y_ball=500;
                                        firstWWW_collision_ball=6;

                                        counter_power_handling_player1+=120;
                                        if(counter_power_handling_player1>395)
                                        {
                                            counter_power_handling_player1=395;
                                        }

                                        hasintersection=true;first_collision_ball=false;
                                        start_clock_fans=clock();

        }
        else if ( SDL_HasIntersection (& ball_rect , & rect_detect_goal_player2 ))
        {
            string chunk_sound = "resources\\goal.ogg"; //Chunk sound Address
            Mix_Chunk *collision = Mix_LoadWAV(chunk_sound.c_str()); //Load sound for wall collision
            Mix_PlayChannel(-1,collision,0);


                                        flag_visible_ball=false;
                                        dx_ball_goal=0;
                                        dy_ball_goal=25;
                                        x_ball_goal=x_ball;
                                        y_ball_goal=y_ball;
                                        dx_ball=0;
                                        dy_ball=0;
                                        x_ball=750;
                                        y_ball=500;
                                        firstWWW_collision_ball=7;

                                        counter_power_handling_player2+=120;
                                        if(counter_power_handling_player2>395)
                                        {
                                            counter_power_handling_player2=395;
                                        }

                                        hasintersection=true;first_collision_ball=false;
                                        start_clock_fans=clock();
        }



            texture(m_renderer,0,180,stadium,1500,570);


            if(draw_score_board)
            {
                texture(m_renderer,0,0,"scoreboard.png",1500,180);

                textColor(m_renderer,1220,10, name_player2_help.c_str(),font_address_02 ,font_size_enter_name-10,text_color_setting_loading,angle,NONE);
                textColor(m_renderer,20,10, name_player1_help.c_str(),font_address_02 ,font_size_enter_name-10,text_color_setting_loading,angle,NONE);

                draw_score_board=false;
            }



            boxRGBA(m_renderer,660,30,840,150,255,255,0,255);

                if(counter_numGoal_player1=='1')
                texture(m_renderer,520,15,numGoal_player1,100,150);
                else
                texture(m_renderer,530,15,numGoal_player1,100,150);


                if(counter_numGoal_player2=='1')
                texture(m_renderer,860,15,numGoal_player2,100,150);
                else
                texture(m_renderer,870,15,numGoal_player2,100,150);



                boxRGBA(m_renderer,25,100,420,140,255,255,255,255);
                boxRGBA(m_renderer,1085,100,1480,140,255,255,255,255);

            if(clock()- start_clock_fans<=5000)
            {

                if(y1_fans>140)
                {
                    y1_fans-=10;
                    y2_fans-=10;
                    y3_fans-=10;
                    y4_fans-=10;
                }
                else
                {
                    y1_fans+=10;
                    y2_fans+=10;
                    y3_fans+=10;
                    y4_fans+=10;
                }
            }
            else
            {
                y1_fans=110;
                y2_fans=170;y3_fans=230;y4_fans=290;
            }
            texture(m_renderer,0,y1_fans+35,"fans21.png",750,200);
            texture(m_renderer,750,y1_fans+35,"fans21.png",750,200);
            texture(m_renderer,0,y2_fans+35,"fans22.png",750,200);
            texture(m_renderer,750,y2_fans+35,"fans22.png",750,200);
            texture(m_renderer,0,y3_fans+35,"fans21.png",750,200);
            texture(m_renderer,750,y3_fans+35,"fans21.png",750,200);
            texture(m_renderer,0,y4_fans+35,"fans22.png",750,200);
            texture(m_renderer,750,y4_fans+35,"fans22.png",750,200);

                boxRGBA(m_renderer,25,100,25+counter_power_handling_player1,140,0,255,0,255);

                if(counter_power_handling_player1<395)
                {
                    counter_power_handling_player1+=3;
                    if(counter_power_handling_player1>395)
                        counter_power_handling_player1=395;
                }




                boxRGBA(m_renderer,1480-counter_power_handling_player2,100,1480,140,0,255,0,255);
                if(counter_power_handling_player2<395)
                {
                     counter_power_handling_player2+=3;
                     if(counter_power_handling_player2>395)
                        counter_power_handling_player2=395;
                }



                if(flag_help4_power_headfireball_player1)
                {
                    if(clock()-start_clock_help4_headfireball>=3000)
                    {
                        flag_help4_power_headfireball_player1=false;flag_help3_power_headfireball_player1=false;
                    }

                    texture(m_renderer,x_player2-120,y_player2-55,"freeze.png",W_player2+250,H_player2+250);
                    if(clock()-start_clock_help4_headfireball>=0 && clock()-start_clock_help4_headfireball<=500)
                    texture(m_renderer,x_player2-50,y_player2-100,"star1.png",150,80);
                    else if(clock()-start_clock_help4_headfireball>500 && clock()-start_clock_help4_headfireball<=1000)texture(m_renderer,x_player2-50,y_player2-100,"star2.png",150,80);
                    else if(clock()-start_clock_help4_headfireball>1000 && clock()-start_clock_help4_headfireball<=1500)texture(m_renderer,x_player2-50,y_player2-100,"star1.png",150,80);
                    else if(clock()-start_clock_help4_headfireball>1500 && clock()-start_clock_help4_headfireball<=2000)texture(m_renderer,x_player2-50,y_player2-100,"star2.png",150,80);
                    else if(clock()-start_clock_help4_headfireball>2000 && clock()-start_clock_help4_headfireball<=2500) texture(m_renderer,x_player2-50,y_player2-100,"star1.png",150,80);
                    else if(clock()-start_clock_help4_headfireball>2500 && clock()-start_clock_help4_headfireball<=3000) texture(m_renderer,x_player2-50,y_player2-100,"star2.png",150,80);

                }


                if(flag_help4_power_headfireball_player2)
                {
                    if(clock()-start_clock_help4_headfireball2>=3000)
                    {
                        flag_help4_power_headfireball_player2=false;flag_help3_power_headfireball_player2=false;
                    }

                    texture(m_renderer,x_player1-120,y_player1-55,"freeze.png",W_player1+250,H_player1+250);
                    if(clock()-start_clock_help4_headfireball2>=0 && clock()-start_clock_help4_headfireball2<=500)
                    texture(m_renderer,x_player1-50,y_player1-100,"star1.png",150,80);
                    else if(clock()-start_clock_help4_headfireball2>500 && clock()-start_clock_help4_headfireball2<=1000)texture(m_renderer,x_player1-50,y_player1-100,"star2.png",150,80);
                    else if(clock()-start_clock_help4_headfireball2>1000 && clock()-start_clock_help4_headfireball2<=1500)texture(m_renderer,x_player1-50,y_player1-100,"star1.png",150,80);
                    else if(clock()-start_clock_help4_headfireball2>1500 && clock()-start_clock_help4_headfireball2<=2000)texture(m_renderer,x_player1-50,y_player1-100,"star2.png",150,80);
                    else if(clock()-start_clock_help4_headfireball2>2000 && clock()-start_clock_help4_headfireball2<=2500) texture(m_renderer,x_player1-50,y_player1-100,"star1.png",150,80);
                    else if(clock()-start_clock_help4_headfireball2>2500 && clock()-start_clock_help4_headfireball2<=3000) texture(m_renderer,x_player1-50,y_player1-100,"star2.png",150,80);

                }


                if(flag_help4_power_kickfireball_player1)
                {
                    if(clock()-start_clock_help4_kickfireball>=3000)
                    {
                        flag_help4_power_kickfireball_player1=false;flag_help3_power_kickfireball_player1=false;
                    }

                    texture(m_renderer,x_player2-120,y_player2-55,"freeze.png",W_player2+250,H_player2+250);
                    if(clock()-start_clock_help4_kickfireball>=0 && clock()-start_clock_help4_kickfireball<=500)
                    texture(m_renderer,x_player2-50,y_player2-100,"star1.png",150,80);
                    else if(clock()-start_clock_help4_kickfireball>500 && clock()-start_clock_help4_kickfireball<=1000)texture(m_renderer,x_player2-50,y_player2-100,"star2.png",150,80);
                    else if(clock()-start_clock_help4_kickfireball>1000 && clock()-start_clock_help4_kickfireball<=1500)texture(m_renderer,x_player2-50,y_player2-100,"star1.png",150,80);
                    else if(clock()-start_clock_help4_kickfireball>1500 && clock()-start_clock_help4_kickfireball<=2000)texture(m_renderer,x_player2-50,y_player2-100,"star2.png",150,80);
                    else if(clock()-start_clock_help4_kickfireball>2000 && clock()-start_clock_help4_kickfireball<=2500) texture(m_renderer,x_player2-50,y_player2-100,"star1.png",150,80);
                    else if(clock()-start_clock_help4_kickfireball>2500 && clock()-start_clock_help4_kickfireball<=3000) texture(m_renderer,x_player2-50,y_player2-100,"star2.png",150,80);

                }

                if(flag_help4_power_kickfireball_player2)
                {
                    if(clock()-start_clock_help4_kickfireball2>=3000)
                    {
                        flag_help4_power_kickfireball_player2=false;flag_help3_power_kickfireball_player2=false;
                    }

                    texture(m_renderer,x_player1-120,y_player1-55,"freeze.png",W_player1+250,H_player1+250);
                    if(clock()-start_clock_help4_kickfireball2>=0 && clock()-start_clock_help4_kickfireball2<=500)
                    texture(m_renderer,x_player1-50,y_player1-100,"star1.png",150,80);
                    else if(clock()-start_clock_help4_kickfireball2>500 && clock()-start_clock_help4_kickfireball2<=1000)texture(m_renderer,x_player1-50,y_player1-100,"star2.png",150,80);
                    else if(clock()-start_clock_help4_kickfireball2>1000 && clock()-start_clock_help4_kickfireball2<=1500)texture(m_renderer,x_player1-50,y_player1-100,"star1.png",150,80);
                    else if(clock()-start_clock_help4_kickfireball2>1500 && clock()-start_clock_help4_kickfireball2<=2000)texture(m_renderer,x_player1-50,y_player1-100,"star2.png",150,80);
                    else if(clock()-start_clock_help4_kickfireball2>2000 && clock()-start_clock_help4_kickfireball2<=2500) texture(m_renderer,x_player1-50,y_player1-100,"star1.png",150,80);
                    else if(clock()-start_clock_help4_kickfireball2>2500 && clock()-start_clock_help4_kickfireball2<=3000) texture(m_renderer,x_player1-50,y_player1-100,"star2.png",150,80);

                }

            if(flag_visible_ball  && !(invisibleball_power))
            {


        if(clock()-start_clock_ball>=0 && clock()-start_clock_ball>200)
        {
            counter_play_ball='2';
        }
        if(clock()-start_clock_ball>=200 && clock()-start_clock_ball>400)
        {
            counter_play_ball='3';
        }
        if(clock()-start_clock_ball>=400 && clock()-start_clock_ball>600)
        {
            counter_play_ball='4';
        }
        if(clock()-start_clock_ball>=600 && clock()-start_clock_ball>800)
        {
            counter_play_ball='1';
            start_clock_ball=clock();
        }

    string ball="ball";
    ball.push_back(counter_setting_ball);
    ball.push_back(counter_play_ball);
    ball+=".png";

                texture(m_renderer,x_ball,y_ball,ball,60,60);
                //boxRGBA(m_renderer,ball_rect.x,ball_rect.y,ball_rect.x+ball_rect.w,ball_rect.y+ball_rect.h,0,255,0,150);

            }
            else if(!(flag_visible_ball))
            {
                texture(m_renderer,500,170,"goal_goal.png",500,230);
                if(x_ball_goal<750)
                texture(m_renderer,x_ball_goal-40,y_ball_goal,"golden_goal.png",100,100);
                else
                texture(m_renderer,x_ball_goal,y_ball_goal,"golden_goal2.png",100,100);

                //boxRGBA(m_renderer,x_ball_goal-40,y_ball_goal,x_ball_goal+100-40,y_ball_goal+100,0,255,0,150);

            }

            if(flag_help_power_punch_player1)
            {
                if(clock()-start_clock_help_punch>=3000)
                    {
                        flag_help_power_punch_player1=false;
                    }

                    texture(m_renderer,x_player2-120,y_player2-55,"freeze.png",W_player2+250,H_player2+250);

                    if(clock()-start_clock_help_punch>=0 && clock()-start_clock_help_punch<=500)
                    texture(m_renderer,x_player2-50,y_player2-100,"star1.png",150,80);
                    else if(clock()-start_clock_help_punch>500 && clock()-start_clock_help_punch<=1000)texture(m_renderer,x_player2-50,y_player2-100,"star2.png",150,80);
                    else if(clock()-start_clock_help_punch>1000 && clock()-start_clock_help_punch<=1500)texture(m_renderer,x_player2-50,y_player2-100,"star1.png",150,80);
                    else if(clock()-start_clock_help_punch>1500 && clock()-start_clock_help_punch<=2000)texture(m_renderer,x_player2-50,y_player2-100,"star2.png",150,80);
                    else if(clock()-start_clock_help_punch>2000 && clock()-start_clock_help_punch<=2500) texture(m_renderer,x_player2-50,y_player2-100,"star1.png",150,80);
                    else if(clock()-start_clock_help_punch>2500 && clock()-start_clock_help_punch<=3000) texture(m_renderer,x_player2-50,y_player2-100,"star2.png",150,80);



            }


            if(flag_help_power_punch_player2)
            {
                if(clock()-start_clock_help_punch2>=3000)
                    {
                        flag_help_power_punch_player2=false;
                    }

                    texture(m_renderer,x_player1-120,y_player1-55,"freeze.png",W_player1+250,H_player1+250);
                    if(clock()-start_clock_help_punch2>=0 && clock()-start_clock_help_punch2<=500)
                    texture(m_renderer,x_player1-50,y_player1-100,"star1.png",150,80);
                    else if(clock()-start_clock_help_punch2>500 && clock()-start_clock_help_punch2<=1000)texture(m_renderer,x_player1-50,y_player1-100,"star2.png",150,80);
                    else if(clock()-start_clock_help_punch2>1000 && clock()-start_clock_help_punch2<=1500)texture(m_renderer,x_player1-50,y_player1-100,"star1.png",150,80);
                    else if(clock()-start_clock_help_punch2>1500 && clock()-start_clock_help_punch2<=2000)texture(m_renderer,x_player1-50,y_player1-100,"star2.png",150,80);
                    else if(clock()-start_clock_help_punch2>2000 && clock()-start_clock_help_punch2<=2500) texture(m_renderer,x_player1-50,y_player1-100,"star1.png",150,80);
                    else if(clock()-start_clock_help_punch2>2500 && clock()-start_clock_help_punch2<=3000) texture(m_renderer,x_player1-50,y_player1-100,"star2.png",150,80);

            }


            if(flag_power_tripleclone_player1)
            {
                texture(m_renderer,x_player1+200,y_player1,player1,W_player1,H_player1);
                texture(m_renderer,x_player1+400,y_player1,player1,W_player1,H_player1);
            }
            if(flag_power_tripleclone_player2)
            {
                texture(m_renderer,x_player2-200,y_player2,player2,W_player2,H_player2);
                texture(m_renderer,x_player2-400,y_player2,player2,W_player2,H_player2);
            }



            texture(m_renderer,x_player1,y_player1,player1,W_player1,H_player1);
            texture(m_renderer,x_player2,y_player2,player2,W_player2,H_player2);

            texture(m_renderer,x_firstgoal,y_firstgoal-40,"firstgoal.png",W_firstgoal,H_firstgoal+40);
            texture(m_renderer,x_secondgoal,y_secondgoal-40,"secondgoal.png",W_secondgoal,H_secondgoal+40);


            if(flag_help2_power_punch_player1)
            {

                    if(clock()-start_clock_help2_punch>=700)
                    {
                        flag_help2_power_punch_player1=false;
                    }
                texture(m_renderer,body1player1.x+body1player1.w-20,body1player1.y-10,"punch1.png",100,body1player1.h+15);
            }

            if(flag_help2_power_punch_player2)
            {

                    if(clock()-start_clock_help2_punch2>=700)
                    {
                        flag_help2_power_punch_player2=false;
                    }
                texture(m_renderer,body1player2.x-100,body1player1.y+10,"punch2.png",100,body1player1.h+15);
            }

            texture(m_renderer,-90,310,"beside_box.png",200,270);
            texture(m_renderer,1390,310,"beside_box2.png",200,270);


                if(start_clocking_full_time_game_tostring!=(clock() - start_clocking_full_time_game)/1000)
                {

                start_clocking_full_time_game_tostring=setTime-(clock() - start_clocking_full_time_game)/1000;

                if(start_clocking_full_time_game_tostring<20)
                {
                    if(start_clocking_full_time_game_tostring%2==0)
                    text_color_timer={255,0,0};
                    else
                     text_color_timer={255,255,255};
                }
                if(start_clocking_full_time_game_tostring<100)
                {
                    if(x_timer==678)
                    {
                        x_timer+=25;


                    }

                }
                if(start_clocking_full_time_game_tostring<10)
                {
                    if(x_timer==703)
                    {
                        x_timer+=22;


                    }

                }

                if(start_clocking_full_time_game_tostring==0)
                {
                    flag_setting_compile_game=false;
                    save_result=true;
                    flag9=true;
                     string sound = "resources\\9.mp3"; //Background sound Address

                Mix_Music *GameSound = Mix_LoadMUS(sound.c_str()); //Load background sound

                Mix_PlayMusic(GameSound,-1); //Play the sound.  -1 means play it till the end

                 x_timer=678;

                 y1_fans=110;
                y2_fans=170;y3_fans=230;y4_fans=290;

                }

              start_clocking_full_time_game_tostring_type=to_string( (int)start_clocking_full_time_game_tostring);

                start_clocking_full_time_game_tochar=start_clocking_full_time_game_tostring_type.c_str();

               textColor(m_renderer,x_timer,y_timer,start_clocking_full_time_game_tochar,font_address_01 ,font_size_timer,text_color_timer,angle,NONE);



                }

                SDL_RenderPresent( m_renderer );

        if(e->type==SDL_KEYDOWN)

         {



             if ( keyboard_state_array[SDL_SCANCODE_A] && keyboard_state_array[SDL_SCANCODE_L] )
             {
                     if(!(flag_help4_power_headfireball_player2)&& !(flag_help4_power_kickfireball_player2) && !(flag_help_power_punch_player2))
                     x_player1-=dx_player1;
                     if(x_player1+W_player1-10>=x_player2)
                     {
                         x_player1+=dx_player1;
                     }
                     if(!(flag_help4_power_headfireball_player1) && !(flag_help4_power_kickfireball_player1)  && !(flag_help_power_punch_player1))
                     x_player2-=dx_player2;
                     if(x_player2<=x_player1+W_player1-10)
                     {
                         x_player2+=dx_player2;
                     }



                if(counter_play_playing_player1=='0')
                 {
                     counter_play_playing_player1='1' ;
                 }
                 else
                 {
                     counter_play_playing_player1='0' ;
                 }


                if(counter_play_playing_player2=='0')
                 {
                     counter_play_playing_player2='1' ;
                 }
                 else
                 {
                     counter_play_playing_player2='0' ;
                 }



                if( min_W_player1!=W_player1)

                {
                        W_player1-=40;

                         start_clocking_kick_player1=false;
                }

                if( min_W_player2!=W_player2)

                {
                        W_player2-=40;

                         start_clocking_kick_player2=false;
                }




             }



             if ( keyboard_state_array[SDL_SCANCODE_S] && keyboard_state_array[SDL_SCANCODE_L] )
             {
                     if(!(flag_help4_power_headfireball_player2)&& !(flag_help4_power_kickfireball_player2) && !(flag_help_power_punch_player2))
                     x_player1+=dx_player1;
                     if(x_player1+W_player1-10>=x_player2)
                     {
                         x_player1-=dx_player1;
                     }
                     if(!(flag_help4_power_headfireball_player1)&& !(flag_help4_power_kickfireball_player1) && !(flag_help_power_punch_player1))
                     x_player2-=dx_player2;
                     if(x_player2<=x_player1+W_player1-10)
                     {
                         x_player2+=dx_player2;
                     }



                if(counter_play_playing_player1=='0')
                 {
                     counter_play_playing_player1='1' ;
                 }
                 else
                 {
                     counter_play_playing_player1='0' ;
                 }


                if(counter_play_playing_player2=='0')
                 {
                     counter_play_playing_player2='1' ;
                 }
                 else
                 {
                     counter_play_playing_player2='0' ;
                 }

                if( min_W_player1!=W_player1)

                {
                        W_player1-=40;

                         start_clocking_kick_player1=false;
                }

                if( min_W_player2!=W_player2)

                {
                        W_player2-=40;

                         start_clocking_kick_player2=false;
                }




             }



             if ( keyboard_state_array[SDL_SCANCODE_A] && keyboard_state_array[SDL_SCANCODE_K] )
             {

                    if(!(flag_help4_power_headfireball_player2)&& !(flag_help4_power_kickfireball_player2) && !(flag_help_power_punch_player2))
                    x_player1-=dx_player1;
                    if(x_player1+W_player1-10>=x_player2)
                     {
                         x_player1+=dx_player1;
                     }
                    if(!(flag_help4_power_headfireball_player1)&& !(flag_help4_power_kickfireball_player1) && !(flag_help_power_punch_player1))
                    x_player2+=dx_player2;
                    if(x_player2<=x_player1+W_player1-10)
                     {
                         x_player2-=dx_player2;
                     }


                if(counter_play_playing_player1=='0')
                 {
                     counter_play_playing_player1='1' ;
                 }
                 else
                 {
                     counter_play_playing_player1='0' ;
                 }


                if(counter_play_playing_player2=='0')
                 {
                     counter_play_playing_player2='1' ;
                 }
                 else
                 {
                     counter_play_playing_player2='0' ;
                 }


                  if( min_W_player1!=W_player1)

                {
                        W_player1-=40;

                         start_clocking_kick_player1=false;
                }

                if( min_W_player2!=W_player2)

                {
                        W_player2-=40;

                         start_clocking_kick_player2=false;
                }

             }



             if ( keyboard_state_array[SDL_SCANCODE_S] && keyboard_state_array[SDL_SCANCODE_K] )
             {
                    if(!(flag_help4_power_headfireball_player2)&& !(flag_help4_power_kickfireball_player2) && !(flag_help_power_punch_player2))
                     x_player1+=dx_player1;
                     if(x_player1+W_player1-10>=x_player2)
                     {
                         x_player1-=dx_player1;
                     }
                     if(!(flag_help4_power_headfireball_player1)&& !(flag_help4_power_kickfireball_player1) && !(flag_help_power_punch_player1))
                     x_player2+=dx_player2;
                     if(x_player2<=x_player1+W_player1-10)
                     {
                         x_player2-=dx_player2;
                     }



                if(counter_play_playing_player1=='0')
                 {
                     counter_play_playing_player1='1' ;
                 }
                 else
                 {
                     counter_play_playing_player1='0' ;
                 }


                if(counter_play_playing_player2=='0')
                 {
                     counter_play_playing_player2='1' ;
                 }
                 else
                 {
                     counter_play_playing_player2='0' ;
                 }




                if( min_W_player1!=W_player1)

                {
                        W_player1-=40;

                         start_clocking_kick_player1=false;
                }

                if( min_W_player2!=W_player2)

                {
                        W_player2-=40;

                         start_clocking_kick_player2=false;
                }


             }


             if ( keyboard_state_array[SDL_SCANCODE_S] && !(keyboard_state_array[SDL_SCANCODE_L])&&!(keyboard_state_array[SDL_SCANCODE_K]))
             {
                    if(!(flag_help4_power_headfireball_player2)&& !(flag_help4_power_kickfireball_player2) && !(flag_help_power_punch_player2))
                    x_player1+=dx_player1;
                    if(x_player1+W_player1-10>=x_player2)
                     {
                         x_player1-=dx_player1;
                     }



                if(counter_play_playing_player1=='0')
                 {
                     counter_play_playing_player1='1' ;
                 }
                 else
                 {
                     counter_play_playing_player1='0' ;
                 }



                if( min_W_player1!=W_player1)

                {
                        W_player1-=40;

                         start_clocking_kick_player1=false;
                }

                if( min_W_player2!=W_player2)

                {
                        W_player2-=40;

                         start_clocking_kick_player2=false;
                }



             }


             if ( keyboard_state_array[SDL_SCANCODE_A]  && !(keyboard_state_array[SDL_SCANCODE_L]) &&!(keyboard_state_array[SDL_SCANCODE_K]))
             {
                 if(!(flag_help4_power_headfireball_player2)&& !(flag_help4_power_kickfireball_player2) && !(flag_help_power_punch_player2))
                 x_player1-=dx_player1;
                 if(x_player1+W_player1-10>=x_player2)
                     {
                         x_player1+=dx_player1;
                     }



                if(counter_play_playing_player1=='0')
                 {
                     counter_play_playing_player1='1' ;
                 }
                 else
                 {
                     counter_play_playing_player1='0' ;
                 }


                if( min_W_player1!=W_player1)

                {
                        W_player1-=40;

                         start_clocking_kick_player1=false;
                }

                if( min_W_player2!=W_player2)

                {
                        W_player2-=40;

                         start_clocking_kick_player2=false;
                }


             }


             if ( keyboard_state_array[SDL_SCANCODE_L]  && !(keyboard_state_array[SDL_SCANCODE_A])&&!(keyboard_state_array[SDL_SCANCODE_S]))
             {
                 if(!(flag_help4_power_headfireball_player1)&& !(flag_help4_power_kickfireball_player1) && !(flag_help_power_punch_player1))
                x_player2-=dx_player2;
                if(x_player2<=x_player1+W_player1-10)
                     {
                         x_player2+=dx_player2;
                     }



                if(counter_play_playing_player2=='0')
                 {
                     counter_play_playing_player2='1' ;
                 }
                 else
                 {
                     counter_play_playing_player2='0' ;
                 }
             }


             if ( keyboard_state_array[SDL_SCANCODE_K]  && !(keyboard_state_array[SDL_SCANCODE_A])&&!(keyboard_state_array[SDL_SCANCODE_S]))
             {
                 if(!(flag_help4_power_headfireball_player1)&& !(flag_help4_power_kickfireball_player1) && !(flag_help_power_punch_player1))
                x_player2+=dx_player2;
                if(x_player2<=x_player1+W_player1-10)
                     {
                         x_player2-=dx_player2;
                     }



                if(counter_play_playing_player2=='0')
                 {
                     counter_play_playing_player2='1' ;
                 }
                 else
                 {
                     counter_play_playing_player2='0' ;
                 }


                if( min_W_player1!=W_player1)

                {
                        W_player1-=40;

                         start_clocking_kick_player1=false;
                }

                if( min_W_player2!=W_player2)

                {
                        W_player2-=40;

                         start_clocking_kick_player2=false;
                }
             }






             if ( keyboard_state_array[SDL_SCANCODE_E] && !(keyboard_state_array[SDL_SCANCODE_W]) )
             {
                     if(counter_power_handling_player1==395)
                     {


                                 if(counter_setting_player1=='1')
                                 {
                                    if(x_ball>x_player1+(W_player1/2))
                                    {
                                       flag_power_headfireball_player1=true;
                                    }
                                 }
                                 else if(counter_setting_player1=='2')
                                 {
                                     rand_power=rand()%2;

                                     if(rand_power==0)
                                    flag_power_invisibleball_player1=true;
                                    else
                                    flag_power_tripleclone_player1=true;

                                    start_clock_tripleclone_player1=clock();
                                 }
                                 else if(counter_setting_player1=='3')
                                 {


                                     rand_power=rand()%2;



                                     if(rand_power==0)
                                       flag_power_kickfireball_player1=true;
                                    else
                                      flag_power_punch_player1=true;

                                 }
                                  else if(counter_setting_player1=='4')
                                 {


                                     rand_power=rand()%5;

                                     //cout<<"rand_power      "<<rand_power<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;

                                     if(rand_power==0)
                                       flag_power_kickfireball_player1=true;
                                    else if(rand_power==1)
                                      flag_power_invisibleball_player1=true;
                                    else if(rand_power==2)
                                      flag_power_headfireball_player1=true;
                                    else if(rand_power==3)
                                        flag_power_punch_player1=true;
                                    else if(rand_power==4)
                                        flag_power_tripleclone_player1=true;

                                 }
                     }



             }

             if ( keyboard_state_array[SDL_SCANCODE_I]   && !(keyboard_state_array[SDL_SCANCODE_O]))
             {

                 if(counter_power_handling_player2==395)
                     {

                         //first_collision_ball=false;flag_first_collision_by_player=false;


                                 if(counter_setting_player2=='1')
                                 {
                                    if(x_ball+30<x_player2)
                                    {
                                        flag_power_headfireball_player2=true;
                                    }
                                 }
                                 else if(counter_setting_player2=='2')
                                 {
                                      rand_power=rand()%2;

                                     if(rand_power==0)
                                    flag_power_invisibleball_player2=true;
                                     else
                                    flag_power_tripleclone_player2=true;

                                    start_clock_tripleclone_player2=clock();
                                 }
                                 else if(counter_setting_player2=='3')
                                 {

                                     rand_power=rand()%2;

                                     if(rand_power==0)
                                       flag_power_kickfireball_player2=true;
                                    else
                                    flag_power_punch_player2=true;




                                 }
                                 else if(counter_setting_player2=='4')
                                 {


                                     rand_power=rand()%5;

                                     //cout<<"rand_power      "<<rand_power<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;

                                     if(rand_power==0)
                                       flag_power_kickfireball_player2=true;
                                    else if(rand_power==1)
                                      flag_power_invisibleball_player2=true;
                                    else if(rand_power==2)
                                      flag_power_headfireball_player2=true;
                                    else if(rand_power==3)
                                        flag_power_punch_player2=true;
                                    else if(rand_power==4)
                                        flag_power_tripleclone_player2=true;

                                 }



                     }


             }

             if ( keyboard_state_array[SDL_SCANCODE_Q]  )
             {

                 pause_player1=true;

                start_clocking_pause_player1=clock()+3000;

                string sound = "resources\\9.mp3"; //Background sound Address

                Mix_Music *GameSound = Mix_LoadMUS(sound.c_str()); //Load background sound

                Mix_PlayMusic(GameSound,-1); //Play the sound.  -1 means play it till the end

                y1_fans=110;
                y2_fans=170;y3_fans=230;y4_fans=290;

                    while(pause_player1)
                    {




                        SDL_PollEvent(e);


                        if(redraw)
                        {
                                texture(m_renderer,0,0,"load_stadium.png",1500,750);

                                texture(m_renderer,350,130,"resume.png",300,130);
                                texture(m_renderer,850,130,"restart.png",300,130);
                                texture(m_renderer,350,340,"menu.png",300,130);
                                texture(m_renderer,850,340,"exit.png",300,130);

                                texture(m_renderer,560,550,"volume1.png",80,80);
                                texture(m_renderer,660,550,"volume2.png",80,80);
                                texture(m_renderer,760,550,"volume3.png",80,80);
                                texture(m_renderer,860,550,"volume4.png",80,80);


                                redraw=false;

                                SDL_RenderPresent( m_renderer );
                        }


                        if(e->type==SDL_MOUSEBUTTONDOWN)
                         {
                             x_mouse=e->motion.x;
                             y_mouse=e->motion.y;



                            string chunk_sound = "resources\\mouse_button.ogg"; //Chunk sound Address
                            Mix_Chunk *collision = Mix_LoadWAV(chunk_sound.c_str()); //Load sound for wall collision
                            Mix_PlayChannel(-1,collision,0);




                                if(x_mouse >350 && x_mouse < 650 && y_mouse > 130 && y_mouse < 260 )
                               {

                                 pause_player1=false;

                                 draw_score_board=true;

                                 setTime+=((clock()-start_clocking_pause_player1)/1000);

                                 sound = "resources\\stadium.mp3";
                                 GameSound = Mix_LoadMUS(sound.c_str());
                                 Mix_PlayMusic(GameSound,-1);

                               }
                                else if(x_mouse > 560 && x_mouse < 640 && y_mouse >550 && y_mouse < 630 )
                                {
                                      Mix_VolumeMusic(500);

                                }
                                 else if(x_mouse > 660 && x_mouse < 740 && y_mouse >550 && y_mouse < 630 )
                                {
                                        Mix_VolumeMusic(200);

                                }
                                 else if(x_mouse > 760 && x_mouse < 840 && y_mouse >550 && y_mouse < 630 )
                                {
                                        Mix_VolumeMusic(50);

                                }
                                 else if(x_mouse > 860 && x_mouse < 940 && y_mouse >550 && y_mouse < 630 )
                                {
                                        Mix_VolumeMusic(0);

                                }




                               if(x_mouse >850 && x_mouse < 1150 && y_mouse > 340 && y_mouse < 470 )
                               {

                                    pause_player1=false;

                                    flag_setting_compile_game=false;

                                    flag12=true;

                                    save_result=true;

                                    counter_goal_plyer1=0;
                                    counter_goal_plyer2=5;

                                    counter_power_handling_player2=0;counter_power_handling_player1=0;


                            x_timer=678;
                                    flag_visible_ball=true;
                            x_ball=x0_ball;
                            y_ball=y0_ball;
                            dx_ball=dx0_ball;
                            dy_ball=dy0_ball;
                            first_collision_ball=true;
                            y_ball_goal=500;
                            x_ball_goal=750;
                            dx_ball_goal=0;
                            dy_ball_goal=0;
                            x_player1=200;
                            x_player2=1200;
                            flag_help2_power_headfireball_player1=false;
                            flag_help3_power_headfireball_player1=false;
                            count_dx_player2=0;
                            flag_help4_power_headfireball_player1=false;
                            flag_help2_power_headfireball_player2=false;
                            flag_help3_power_headfireball_player2=false;
                            count_dx_player1=200;
                            flag_help4_power_headfireball_player2=false;

                            flag_help2_power_kickfireball_player1=false;
                            flag_help3_power_kickfireball_player1=false;
                            count_dx_player2=0;
                            flag_help4_power_kickfireball_player1=false;

                            flag_help2_power_kickfireball_player2=false;
                            flag_help3_power_kickfireball_player2=false;
                            count_dx_player1=200;
                            flag_help4_power_kickfireball_player2=false;


                            y_player1=480;
                            y_player2=480;


                            counter_play_playing_player1='0';
                            counter_play_playing_player2='0';



                            flag_power_invisibleball_player1=false,flag_help_power_invisibleball_kick_player1=false,flag_help2_power_invisibleball_kick_player1=false;
                            flag_help_power_invisibleball_head_player1=false,flag_help2_power_invisibleball_head_player1=false,flag_help3_power_invisibleball_head_player1=false,flag_help4_power_invisibleball_head_player1=false;


                            flag_power_invisibleball_player2=false,flag_help_power_invisibleball_kick_player2=false,flag_help2_power_invisibleball_kick_player2=false;
                            flag_help_power_invisibleball_head_player2=false,flag_help2_power_invisibleball_head_player2=false,flag_help3_power_invisibleball_head_player2=false,flag_help4_power_invisibleball_head_player2=false;

                            flag_power_punch_player1=false,flag_help_power_punch_player1=false,flag_help2_power_punch_player1=false;
                            start_clock_help_punch=0,start_clock_help2_punch=0;

                            w_punch=0;


                            flag_power_punch_player2=false,flag_help_power_punch_player2=false,flag_help2_power_punch_player2=false;
                            start_clock_help_punch2=0,start_clock_help2_punch2=0;


                            w_punch=0;

                            texture(m_renderer,385,0,"black.png",730,180);
                            texture(m_renderer,490,10,"yellow.png",182,160);
                            texture(m_renderer,828,10,"yellow.png",184,160);

                            draw_score_board=true;

                            counter_numGoal_player1='0';

                            counter_numGoal_player2='0';



                            setTime=setTime0;


                               }



                               else if(x_mouse >850 && x_mouse < 1150 && y_mouse > 130 && y_mouse < 260 )
                               {

                                    pause_player1=false;

                                    flag_setting_compile_game=false;

                                    flag8=true;




                                    string sound = "resources\\stadium.mp3"; //Background sound Address

                                    Mix_Music *GameSound = Mix_LoadMUS(sound.c_str()); //Load background sound

                                    Mix_PlayMusic(GameSound,-1); //Play the sound.  -1 means play it till the end


                            counter_power_handling_player2=0;counter_power_handling_player1=0;
                            flag_visible_ball=true;
                            x_ball=x0_ball;
                            y_ball=y0_ball;
                            dx_ball=dx0_ball;
                            dy_ball=dy0_ball;
                            first_collision_ball=true;
                            y_ball_goal=500;
                            x_ball_goal=750;
                            dx_ball_goal=0;
                            dy_ball_goal=0;
                            x_player1=200;
                            x_player2=1200;
                            flag_help2_power_headfireball_player1=false;
                            flag_help3_power_headfireball_player1=false;
                            count_dx_player2=0;
                            flag_help4_power_headfireball_player1=false;
                            flag_help2_power_headfireball_player2=false;
                            flag_help3_power_headfireball_player2=false;
                            count_dx_player1=200;
                            flag_help4_power_headfireball_player2=false;

                            flag_help2_power_kickfireball_player1=false;
                            flag_help3_power_kickfireball_player1=false;
                            count_dx_player2=0;
                            flag_help4_power_kickfireball_player1=false;

                            flag_help2_power_kickfireball_player2=false;
                            flag_help3_power_kickfireball_player2=false;
                            count_dx_player1=200;
                            flag_help4_power_kickfireball_player2=false;


                            y_player1=480;
                            y_player2=480;


                            counter_play_playing_player1='0';
                            counter_play_playing_player2='0';



                            flag_power_invisibleball_player1=false,flag_help_power_invisibleball_kick_player1=false,flag_help2_power_invisibleball_kick_player1=false;
                            flag_help_power_invisibleball_head_player1=false,flag_help2_power_invisibleball_head_player1=false,flag_help3_power_invisibleball_head_player1=false,flag_help4_power_invisibleball_head_player1=false;


                            flag_power_invisibleball_player2=false,flag_help_power_invisibleball_kick_player2=false,flag_help2_power_invisibleball_kick_player2=false;
                            flag_help_power_invisibleball_head_player2=false,flag_help2_power_invisibleball_head_player2=false,flag_help3_power_invisibleball_head_player2=false,flag_help4_power_invisibleball_head_player2=false;

                            flag_power_punch_player1=false,flag_help_power_punch_player1=false,flag_help2_power_punch_player1=false;
                            start_clock_help_punch=0,start_clock_help2_punch=0;

                            w_punch=0;


                            flag_power_punch_player2=false,flag_help_power_punch_player2=false,flag_help2_power_punch_player2=false;
                            start_clock_help_punch2=0,start_clock_help2_punch2=0;


                            w_punch=0;

                            texture(m_renderer,385,0,"black.png",730,180);
                            texture(m_renderer,490,10,"yellow.png",182,160);
                            texture(m_renderer,828,10,"yellow.png",184,160);

                            draw_score_board=true;

                            counter_numGoal_player1='0';
                            counter_goal_plyer1=0;
                            counter_numGoal_player2='0';
                            counter_goal_plyer2=0;


                            setTime=setTime0;

                             x_timer=678;


                               }


                               else if(x_mouse >350 && x_mouse < 650 && y_mouse > 340 && y_mouse < 470 )
                               {

                                    pause_player1=false;

                                    flag_setting_compile_game=false;

                                    flag1=true;




                                    string sound = "resources\\0.mp3"; //Background sound Address

                                    Mix_Music *GameSound = Mix_LoadMUS(sound.c_str()); //Load background sound

                                    Mix_PlayMusic(GameSound,-1); //Play the sound.  -1 means play it till the end



                                    counter_power_handling_player2=0;counter_power_handling_player1=0;
                                    flag_visible_ball=true;
                            x_ball=x0_ball;
                            y_ball=y0_ball;
                            dx_ball=dx0_ball;
                            dy_ball=dy0_ball;
                            first_collision_ball=true;
                            y_ball_goal=500;
                            x_ball_goal=750;
                            dx_ball_goal=0;
                            dy_ball_goal=0;
                            x_player1=200;
                            x_player2=1200;
                            flag_help2_power_headfireball_player1=false;
                            flag_help3_power_headfireball_player1=false;
                            count_dx_player2=0;
                            flag_help4_power_headfireball_player1=false;
                            flag_help2_power_headfireball_player2=false;
                            flag_help3_power_headfireball_player2=false;
                            count_dx_player1=200;
                            flag_help4_power_headfireball_player2=false;

                            flag_help2_power_kickfireball_player1=false;
                            flag_help3_power_kickfireball_player1=false;
                            count_dx_player2=0;
                            flag_help4_power_kickfireball_player1=false;

                            flag_help2_power_kickfireball_player2=false;
                            flag_help3_power_kickfireball_player2=false;
                            count_dx_player1=200;
                            flag_help4_power_kickfireball_player2=false;


                            y_player1=480;
                            y_player2=480;


                            counter_play_playing_player1='0';
                            counter_play_playing_player2='0';



                            flag_power_invisibleball_player1=false,flag_help_power_invisibleball_kick_player1=false,flag_help2_power_invisibleball_kick_player1=false;
                            flag_help_power_invisibleball_head_player1=false,flag_help2_power_invisibleball_head_player1=false,flag_help3_power_invisibleball_head_player1=false,flag_help4_power_invisibleball_head_player1=false;


                            flag_power_invisibleball_player2=false,flag_help_power_invisibleball_kick_player2=false,flag_help2_power_invisibleball_kick_player2=false;
                            flag_help_power_invisibleball_head_player2=false,flag_help2_power_invisibleball_head_player2=false,flag_help3_power_invisibleball_head_player2=false,flag_help4_power_invisibleball_head_player2=false;

                            flag_power_punch_player1=false,flag_help_power_punch_player1=false,flag_help2_power_punch_player1=false;
                            start_clock_help_punch=0,start_clock_help2_punch=0;

                            w_punch=0;


                            flag_power_punch_player2=false,flag_help_power_punch_player2=false,flag_help2_power_punch_player2=false;
                            start_clock_help_punch2=0,start_clock_help2_punch2=0;


                            w_punch=0;

                            texture(m_renderer,385,0,"black.png",730,180);
                            texture(m_renderer,490,10,"yellow.png",182,160);
                            texture(m_renderer,828,10,"yellow.png",184,160);

                            draw_score_board=true;

                            counter_numGoal_player1='0';
                            counter_goal_plyer1=0;
                            counter_numGoal_player2='0';
                            counter_goal_plyer2=0;


                            setTime=setTime0;

                             x_timer=678;


                               }
                         }

                    }

             }



             if ( keyboard_state_array[SDL_SCANCODE_P]  )
             {

                 pause_player2=true;

                start_clocking_pause_player2=clock()+3000;

                string sound = "resources\\9.mp3"; //Background sound Address

                Mix_Music *GameSound = Mix_LoadMUS(sound.c_str()); //Load background sound

                Mix_PlayMusic(GameSound,-1); //Play the sound.  -1 means play it till the end

                y1_fans=110;
                y2_fans=170;y3_fans=230;y4_fans=290;

                    while(pause_player2)
                    {




                        SDL_PollEvent(e);


                        if(redraw)
                        {
                                texture(m_renderer,0,0,"load_stadium.png",1500,750);

                                texture(m_renderer,350,130,"resume.png",300,130);
                                texture(m_renderer,850,130,"restart.png",300,130);
                                texture(m_renderer,350,340,"menu.png",300,130);
                                texture(m_renderer,850,340,"exit.png",300,130);

                                texture(m_renderer,560,550,"volume1.png",80,80);
                                texture(m_renderer,660,550,"volume2.png",80,80);
                                texture(m_renderer,760,550,"volume3.png",80,80);
                                texture(m_renderer,860,550,"volume4.png",80,80);


                                redraw=false;

                                SDL_RenderPresent( m_renderer );
                        }


                        if(e->type==SDL_MOUSEBUTTONDOWN)
                         {
                             x_mouse=e->motion.x;
                             y_mouse=e->motion.y;



                            string chunk_sound = "resources\\mouse_button.ogg"; //Chunk sound Address
                            Mix_Chunk *collision = Mix_LoadWAV(chunk_sound.c_str()); //Load sound for wall collision
                            Mix_PlayChannel(-1,collision,0);




                                if(x_mouse >350 && x_mouse < 650 && y_mouse > 130 && y_mouse < 260 )
                               {

                                 pause_player2=false;

                                 draw_score_board=true;

                                 setTime+=((clock()-start_clocking_pause_player2)/1000);

                                 string sound = "resources\\stadium.mp3"; //Background sound Address

                                    Mix_Music *GameSound = Mix_LoadMUS(sound.c_str()); //Load background sound

                                    Mix_PlayMusic(GameSound,-1); //Play the sound.  -1 means play it till the end


                               }

                               else if(x_mouse > 560 && x_mouse < 640 && y_mouse >550 && y_mouse < 630 )
                                {
                                      Mix_VolumeMusic(500);

                                }
                                 else if(x_mouse > 660 && x_mouse < 740 && y_mouse >550 && y_mouse < 630 )
                                {
                                        Mix_VolumeMusic(200);

                                }
                                 else if(x_mouse > 760 && x_mouse < 840 && y_mouse >550 && y_mouse < 630 )
                                {
                                        Mix_VolumeMusic(50);

                                }
                                 else if(x_mouse > 860 && x_mouse < 940 && y_mouse >550 && y_mouse < 630 )
                                {
                                        Mix_VolumeMusic(0);

                                }




                               if(x_mouse >850 && x_mouse < 1150 && y_mouse > 340 && y_mouse < 470 )
                               {

                                    pause_player2=false;

                                    flag_setting_compile_game=false;

                                    flag13=true;

                                    save_result=true;

                                    counter_goal_plyer1=5;
                                    counter_goal_plyer2=0;
                                     x_timer=678;



                                     counter_power_handling_player2=0;counter_power_handling_player1=0;

                                    flag_visible_ball=true;
                            x_ball=x0_ball;
                            y_ball=y0_ball;
                            dx_ball=dx0_ball;
                            dy_ball=dy0_ball;
                            first_collision_ball=true;
                            y_ball_goal=500;
                            x_ball_goal=750;
                            dx_ball_goal=0;
                            dy_ball_goal=0;
                            x_player1=200;
                            x_player2=1200;
                            flag_help2_power_headfireball_player1=false;
                            flag_help3_power_headfireball_player1=false;
                            count_dx_player2=0;
                            flag_help4_power_headfireball_player1=false;
                            flag_help2_power_headfireball_player2=false;
                            flag_help3_power_headfireball_player2=false;
                            count_dx_player1=200;
                            flag_help4_power_headfireball_player2=false;

                            flag_help2_power_kickfireball_player1=false;
                            flag_help3_power_kickfireball_player1=false;
                            count_dx_player2=0;
                            flag_help4_power_kickfireball_player1=false;

                            flag_help2_power_kickfireball_player2=false;
                            flag_help3_power_kickfireball_player2=false;
                            count_dx_player1=200;
                            flag_help4_power_kickfireball_player2=false;


                            y_player1=480;
                            y_player2=480;


                            counter_play_playing_player1='0';
                            counter_play_playing_player2='0';



                            flag_power_invisibleball_player1=false,flag_help_power_invisibleball_kick_player1=false,flag_help2_power_invisibleball_kick_player1=false;
                            flag_help_power_invisibleball_head_player1=false,flag_help2_power_invisibleball_head_player1=false,flag_help3_power_invisibleball_head_player1=false,flag_help4_power_invisibleball_head_player1=false;


                            flag_power_invisibleball_player2=false,flag_help_power_invisibleball_kick_player2=false,flag_help2_power_invisibleball_kick_player2=false;
                            flag_help_power_invisibleball_head_player2=false,flag_help2_power_invisibleball_head_player2=false,flag_help3_power_invisibleball_head_player2=false,flag_help4_power_invisibleball_head_player2=false;

                            flag_power_punch_player1=false,flag_help_power_punch_player1=false,flag_help2_power_punch_player1=false;
                            start_clock_help_punch=0,start_clock_help2_punch=0;

                            w_punch=0;


                            flag_power_punch_player2=false,flag_help_power_punch_player2=false,flag_help2_power_punch_player2=false;
                            start_clock_help_punch2=0,start_clock_help2_punch2=0;


                            w_punch=0;

                            texture(m_renderer,385,0,"black.png",730,180);
                            texture(m_renderer,490,10,"yellow.png",182,160);
                            texture(m_renderer,828,10,"yellow.png",184,160);

                            draw_score_board=true;

                            counter_numGoal_player1='0';

                            counter_numGoal_player2='0';



                            setTime=setTime0;


                               }

                               else if(x_mouse >850 && x_mouse < 1150 && y_mouse > 130 && y_mouse < 260 )
                               {

                                    pause_player2=false;

                                    flag_setting_compile_game=false;

                                    flag8=true;




                                    string sound = "resources\\stadium.mp3"; //Background sound Address

                                    Mix_Music *GameSound = Mix_LoadMUS(sound.c_str()); //Load background sound

                                    Mix_PlayMusic(GameSound,-1); //Play the sound.  -1 means play it till the end


                                    counter_power_handling_player2=0;counter_power_handling_player1=0;

                            flag_visible_ball=true;
                            x_ball=x0_ball;
                            y_ball=y0_ball;
                            dx_ball=dx0_ball;
                            dy_ball=dy0_ball;
                            first_collision_ball=true;
                            y_ball_goal=500;
                            x_ball_goal=750;
                            dx_ball_goal=0;
                            dy_ball_goal=0;
                            x_player1=200;
                            x_player2=1200;
                            flag_help2_power_headfireball_player1=false;
                            flag_help3_power_headfireball_player1=false;
                            count_dx_player2=0;
                            flag_help4_power_headfireball_player1=false;
                            flag_help2_power_headfireball_player2=false;
                            flag_help3_power_headfireball_player2=false;
                            count_dx_player1=200;
                            flag_help4_power_headfireball_player2=false;

                            flag_help2_power_kickfireball_player1=false;
                            flag_help3_power_kickfireball_player1=false;
                            count_dx_player2=0;
                            flag_help4_power_kickfireball_player1=false;

                            flag_help2_power_kickfireball_player2=false;
                            flag_help3_power_kickfireball_player2=false;
                            count_dx_player1=200;
                            flag_help4_power_kickfireball_player2=false;


                            y_player1=480;
                            y_player2=480;


                            counter_play_playing_player1='0';
                            counter_play_playing_player2='0';



                            flag_power_invisibleball_player1=false,flag_help_power_invisibleball_kick_player1=false,flag_help2_power_invisibleball_kick_player1=false;
                            flag_help_power_invisibleball_head_player1=false,flag_help2_power_invisibleball_head_player1=false,flag_help3_power_invisibleball_head_player1=false,flag_help4_power_invisibleball_head_player1=false;


                            flag_power_invisibleball_player2=false,flag_help_power_invisibleball_kick_player2=false,flag_help2_power_invisibleball_kick_player2=false;
                            flag_help_power_invisibleball_head_player2=false,flag_help2_power_invisibleball_head_player2=false,flag_help3_power_invisibleball_head_player2=false,flag_help4_power_invisibleball_head_player2=false;

                            flag_power_punch_player1=false,flag_help_power_punch_player1=false,flag_help2_power_punch_player1=false;
                            start_clock_help_punch=0,start_clock_help2_punch=0;

                            w_punch=0;


                            flag_power_punch_player2=false,flag_help_power_punch_player2=false,flag_help2_power_punch_player2=false;
                            start_clock_help_punch2=0,start_clock_help2_punch2=0;


                            w_punch=0;

                            texture(m_renderer,385,0,"black.png",730,180);
                            texture(m_renderer,490,10,"yellow.png",182,160);
                            texture(m_renderer,828,10,"yellow.png",184,160);

                            draw_score_board=true;

                            counter_numGoal_player1='0';
                            counter_goal_plyer1=0;
                            counter_numGoal_player2='0';
                            counter_goal_plyer2=0;


                            setTime=setTime0;
                             x_timer=678;


                               }


                               else if(x_mouse >350 && x_mouse < 650 && y_mouse > 340 && y_mouse < 470 )
                               {

                                    pause_player2=false;

                                    flag_setting_compile_game=false;

                                    flag1=true;




                                    string sound = "resources\\0.mp3"; //Background sound Address

                                    Mix_Music *GameSound = Mix_LoadMUS(sound.c_str()); //Load background sound

                                    Mix_PlayMusic(GameSound,-1); //Play the sound.  -1 means play it till the end


                                    counter_power_handling_player2=0;counter_power_handling_player1=0;

                                    flag_visible_ball=true;
                            x_ball=x0_ball;
                            y_ball=y0_ball;
                            dx_ball=dx0_ball;
                            dy_ball=dy0_ball;
                            first_collision_ball=true;
                            y_ball_goal=500;
                            x_ball_goal=750;
                            dx_ball_goal=0;
                            dy_ball_goal=0;
                            x_player1=200;
                            x_player2=1200;
                            flag_help2_power_headfireball_player1=false;
                            flag_help3_power_headfireball_player1=false;
                            count_dx_player2=0;
                            flag_help4_power_headfireball_player1=false;
                            flag_help2_power_headfireball_player2=false;
                            flag_help3_power_headfireball_player2=false;
                            count_dx_player1=200;
                            flag_help4_power_headfireball_player2=false;

                            flag_help2_power_kickfireball_player1=false;
                            flag_help3_power_kickfireball_player1=false;
                            count_dx_player2=0;
                            flag_help4_power_kickfireball_player1=false;

                            flag_help2_power_kickfireball_player2=false;
                            flag_help3_power_kickfireball_player2=false;
                            count_dx_player1=200;
                            flag_help4_power_kickfireball_player2=false;


                            y_player1=480;
                            y_player2=480;


                            counter_play_playing_player1='0';
                            counter_play_playing_player2='0';



                            flag_power_invisibleball_player1=false,flag_help_power_invisibleball_kick_player1=false,flag_help2_power_invisibleball_kick_player1=false;
                            flag_help_power_invisibleball_head_player1=false,flag_help2_power_invisibleball_head_player1=false,flag_help3_power_invisibleball_head_player1=false,flag_help4_power_invisibleball_head_player1=false;


                            flag_power_invisibleball_player2=false,flag_help_power_invisibleball_kick_player2=false,flag_help2_power_invisibleball_kick_player2=false;
                            flag_help_power_invisibleball_head_player2=false,flag_help2_power_invisibleball_head_player2=false,flag_help3_power_invisibleball_head_player2=false,flag_help4_power_invisibleball_head_player2=false;

                            flag_power_punch_player1=false,flag_help_power_punch_player1=false,flag_help2_power_punch_player1=false;
                            start_clock_help_punch=0,start_clock_help2_punch=0;

                            w_punch=0;


                            flag_power_punch_player2=false,flag_help_power_punch_player2=false,flag_help2_power_punch_player2=false;
                            start_clock_help_punch2=0,start_clock_help2_punch2=0;


                            w_punch=0;

                            texture(m_renderer,385,0,"black.png",730,180);
                            texture(m_renderer,490,10,"yellow.png",182,160);
                            texture(m_renderer,828,10,"yellow.png",184,160);

                            draw_score_board=true;

                            counter_numGoal_player1='0';
                            counter_goal_plyer1=0;
                            counter_numGoal_player2='0';
                            counter_goal_plyer2=0;


                            setTime=setTime0;
                             x_timer=678;


                               }
                         }

                    }

             }



            if ( keyboard_state_array[SDL_SCANCODE_D]  )
             {

                 start_kick_player1=clock();


                 counter_play_playing_player1='2';


                if( min_W_player1==W_player1)

                {
                        W_player1+=40;
                }



                if(!(flag_help4_power_headfireball_player2)&& !(flag_help4_power_kickfireball_player2) && !(flag_help_power_punch_player2))
                 start_clocking_kick_player1=true;
             }






             if ( keyboard_state_array[SDL_SCANCODE_J]  )
             {



                 start_kick_player2=clock();


                 counter_play_playing_player2='2';


                if( min_W_player2==W_player2)

                {
                        W_player2+=40;
                }


                if(!(flag_help4_power_headfireball_player1)&& !(flag_help4_power_kickfireball_player1) && !(flag_help_power_punch_player1))
                 start_clocking_kick_player2=true;


             }




             if(keyboard_state_array[SDL_SCANCODE_W] )
             {
                 if(!(flag_help4_power_headfireball_player2)&& !(flag_help4_power_kickfireball_player2) && !(flag_help_power_punch_player2))
                 start_clocking_jump_player1=true;

                  string chunk_sound = "resources\\jumpbreath.ogg"; //Chunk sound Address
            Mix_Chunk *collision = Mix_LoadWAV(chunk_sound.c_str()); //Load sound for wall collision
            Mix_PlayChannel(-1,collision,0);



                if( min_W_player1!=W_player1)

                {
                        W_player1-=40;

                         start_clocking_kick_player1=false;
                }

                if( min_W_player2!=W_player2)

                {
                        W_player2-=40;

                         start_clocking_kick_player2=false;
                }


             }


             if(keyboard_state_array[SDL_SCANCODE_O] )
             {

             if(!(flag_help4_power_headfireball_player1)&& !(flag_help4_power_kickfireball_player1) && !(flag_help_power_punch_player1))
                 start_clocking_jump_player2=true;

                 string chunk_sound = "resources\\jumpbreath.ogg"; //Chunk sound Address
            Mix_Chunk *collision = Mix_LoadWAV(chunk_sound.c_str()); //Load sound for wall collision
            Mix_PlayChannel(-1,collision,0);


                if( min_W_player1!=W_player1)

                {
                        W_player1-=40;

                         start_clocking_kick_player1=false;
                }

                if( min_W_player2!=W_player2)

                {
                        W_player2-=40;

                         start_clocking_kick_player2=false;
                }
             }



                 redraw=true;

         }




  e->type = 0;


            if(flag_power_tripleclone_player2)
            {
                counter_power_handling_player2=0;


                                if(clock()-start_clock_tripleclone_player2>=8000)
                                {
                                    flag_power_tripleclone_player2=false;
                                }







                        if(counter_play_playing_player2=='0')
                        {


                        headplayer22.x=x_player2+9-400;
                        headplayer22.y=y_player2+3;
                        headplayer22.w=68;
                        headplayer22.h=61;

                        body1player22.x=x_player2+13-400;
                        body1player22.y=y_player2 + 63;
                        body1player22.w=81;
                        body1player22.h=61;

                        body2player22.x=x_player2+31-400;
                        body2player22.y=y_player2 + 125;
                        body2player22.w=56;
                        body2player22.h=54;

                        footplayer22.x=x_player2+42-400;
                        footplayer22.y=y_player2 + 179;
                        footplayer22.w=31;
                        footplayer22.h=40;



                       ball_rect.x=x_ball;
                        ball_rect.y=y_ball;
                       ball_rect.w=60;
                        ball_rect.h=60;


                        if ( SDL_HasIntersection (& ball_rect , & headplayer22))
                        {
                                        if( clock()-control_hitsurface_player2>=500)
                                       {
                                           control_hitsurface_player2=clock();

                                                        if(dx_ball<0 )
                                                        {
                                                            if( x_ball>headplayer2.x+(5*headplayer2.w/10))
                                                            {
                                                                dx_ball=-dx_ball;
                                                                if(dy_ball>0)
                                                                dy_ball=-dy_ball;
                                                            }
                                                            else
                                                            {
                                                                if(dy_ball>0)
                                                                dy_ball=-dy_ball;
                                                            }

                                                        }

                                                        else if(dx_ball>0)
                                                        {

                                                           if( x_ball<headplayer2.x+(2.2*headplayer2.w/10))
                                                            {
                                                                dx_ball=-dx_ball;
                                                                if(dy_ball>0)
                                                                dy_ball=-dy_ball;
                                                            }
                                                            else
                                                            {
                                                                if(dy_ball>0)
                                                                dy_ball=-dy_ball;
                                                            }
                                                        }


                                                        if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                                        {
                                                            dx_ball*=1.2;
                                                            clock_player_hit=clock();
                                                        }

                                                        clock_player_hit=clock();

                                                        dy_ball=-15.5;



                                                        //dy_ball=-1.5*abs(dx_ball*0.55);



                                                first_collision_ball=false;flag_first_collision_by_player=false;


                                                if(flag_help3_power_headfireball_player1)
                                                {
                                                    flag_help4_power_headfireball_player1=true;
                                                    start_clock_help4_headfireball=clock();
                                                }

                                                if(flag_help3_power_kickfireball_player1)
                                                {
                                                    flag_help4_power_kickfireball_player1=true;
                                                    start_clock_help4_kickfireball=clock();
                                                }
                                       }
                        }
                        else if ( SDL_HasIntersection (& ball_rect , & body1player22 ))
                        {
                              if(!(flag_help3_power_headfireball_player1)&& !(flag_help3_power_kickfireball_player1))
                              {


                                        if( clock()-control_hitsurface_player2>=500)
                                       {
                                           control_hitsurface_player2=clock();

                                                        dx_ball=-dx_ball;

                                                        if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                                        {
                                                            dx_ball*=1.2;
                                                            clock_player_hit=clock();
                                                        }

                                                        clock_player_hit=clock();


                                                        first_collision_ball=false;flag_first_collision_by_player=false;
                                       }
                              }

                        }
                        else if ( SDL_HasIntersection (& ball_rect , & body2player22 ))
                        {
                            if(!(flag_help3_power_headfireball_player1)&& !(flag_help3_power_kickfireball_player1))
                              {
                                        if( clock()-control_hitsurface_player2>=500)
                                       {
                                           control_hitsurface_player2=clock();

                                                        dx_ball=-dx_ball;

                                                        if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                                        {
                                                            dx_ball*=1.4;
                                                            clock_player_hit=clock();
                                                        }

                                                        clock_player_hit=clock();

                                                        dy_ball=-1*abs(dx_ball*0.55); // tan 29 degree

                                                        first_collision_ball=false;flag_first_collision_by_player=false;


                                       }
                              }
                        }
                        else if ( SDL_HasIntersection (& ball_rect , & footplayer22 ))
                        {
                            if(!(flag_help3_power_headfireball_player1)&& !(flag_help3_power_kickfireball_player1))
                              {
                                        if( clock()-control_hitsurface_player2>=500)
                                       {
                                           control_hitsurface_player2=clock();

                                                        dx_ball=-dx_ball;

                                                        if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                                        {
                                                            dx_ball*=1.4;
                                                            clock_player_hit=clock();
                                                        }

                                                        clock_player_hit=clock();
                                                        dy_ball=-1*abs(dx_ball*0.55); // tan 29 degree

                                                        if(y_ball>footplayer1.y+(7*(footplayer1.h/10)))
                                                            dy_ball=abs(dx_ball*1);   // tan negeative 45 degree


                                                        first_collision_ball=false;flag_first_collision_by_player=false;

                                       }
                              }

                        }
                        }




                        else if(counter_play_playing_player2=='1')
                        {

                        headplayer22.x=x_player2+8-400;
                        headplayer22.y=y_player2+3-400;
                        headplayer22.w=70;
                        headplayer22.h=65;

                        body1player22.x=x_player2+12-400;
                        body1player22.y=y_player2 + 64;
                        body1player22.w=69;
                        body1player22.h=81;

                        body2player22.x=x_player2+2-400;
                        body2player22.y=y_player2 + 145;
                        body2player22.w=75;
                        body2player22.h=36;

                        footplayer22.x=x_player2+50-400;
                        footplayer22.y=y_player2 + 182;
                        footplayer22.w=45;
                        footplayer22.h=38;


                       ball_rect.x=x_ball;
                        ball_rect.y=y_ball;
                       ball_rect.w=60;
                        ball_rect.h=60;



                        if ( SDL_HasIntersection (& ball_rect , & headplayer22))
                        {
                                        if( clock()-control_hitsurface_player2>=500)
                                       {
                                           control_hitsurface_player2=clock();

                                                        if(dx_ball<0 )
                                                        {
                                                            if( x_ball>headplayer2.x+(5*headplayer2.w/10))
                                                            {
                                                                dx_ball=-dx_ball;
                                                                if(dy_ball>0)
                                                                dy_ball=-dy_ball;
                                                            }
                                                            else
                                                            {
                                                                if(dy_ball>0)
                                                                dy_ball=-dy_ball;
                                                            }

                                                        }

                                                        else if(dx_ball>0)
                                                        {

                                                           if( x_ball<headplayer2.x+(2.2*headplayer2.w/10))
                                                            {
                                                                dx_ball=-dx_ball;
                                                                if(dy_ball>0)
                                                                dy_ball=-dy_ball;
                                                            }
                                                            else
                                                            {
                                                                if(dy_ball>0)
                                                                dy_ball=-dy_ball;
                                                            }
                                                        }

                                                        if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                                        {
                                                            dx_ball*=1.2;
                                                            clock_player_hit=clock();
                                                        }

                                                        dy_ball=-15.5;

                                                        clock_player_hit=clock();

                                                        //dy_ball=-1.5*abs(dx_ball*0.55);


                                                        if(flag_help3_power_headfireball_player1)
                                                        {
                                                            flag_help4_power_headfireball_player1=true;
                                                            start_clock_help4_headfireball=clock();
                                                        }

                                                        if(flag_help3_power_kickfireball_player1)
                                                        {
                                                            flag_help4_power_kickfireball_player1=true;
                                                            start_clock_help4_kickfireball=clock();
                                                        }


                                                     first_collision_ball=false;flag_first_collision_by_player=false;
                                       }

                        }
                        else if ( SDL_HasIntersection (& ball_rect , & body1player22 ))
                        {
                            if(!(flag_help3_power_headfireball_player1)&& !(flag_help3_power_kickfireball_player1))
                              {
                                        if( clock()-control_hitsurface_player2>=500)
                                       {
                                           control_hitsurface_player2=clock();

                                                        dx_ball=-dx_ball;

                                                        if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                                        {
                                                            dx_ball*=1.2;
                                                            clock_player_hit=clock();
                                                        }

                                                       first_collision_ball=false;flag_first_collision_by_player=false;

                                       }
                              }
                        }
                        else if ( SDL_HasIntersection (& ball_rect , & body2player22 ))
                        {
                            if(!(flag_help3_power_headfireball_player1)&& !(flag_help3_power_kickfireball_player1))
                              {
                                        if( clock()-control_hitsurface_player2>=500)
                                       {
                                           control_hitsurface_player2=clock();

                                                        dx_ball=-dx_ball;

                                                        if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                                        {
                                                            dx_ball*=1.4;
                                                            clock_player_hit=clock();
                                                        }
                                                        clock_player_hit=clock();

                                                        dy_ball=-1*abs(dx_ball*0.55); // tan 29 degree

                                                        first_collision_ball=false;flag_first_collision_by_player=false;
                                       }
                              }
                        }
                        else if ( SDL_HasIntersection (& ball_rect , & footplayer22 ))
                        {

                                 if(!(flag_help3_power_headfireball_player1)&& !(flag_help3_power_kickfireball_player1))
                              {
                                         if( clock()-control_hitsurface_player2>=500)
                                       {
                                           control_hitsurface_player2=clock();

                                                        dx_ball=-dx_ball;

                                                        if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                                        {
                                                            dx_ball*=1.4;
                                                            clock_player_hit=clock();
                                                        }
                                                        clock_player_hit=clock();

                                                        dy_ball=-1*abs(dx_ball*0.55); // tan 29 degree

                                                        if(y_ball>footplayer1.y+(7*(footplayer1.h/10)))
                                                            dy_ball=abs(dx_ball*1);   // tan negeative 45 degree


                                                        first_collision_ball=false;flag_first_collision_by_player=false;

                                       }
                              }
                        }
                        }







                        if(counter_play_playing_player2=='2')
                        {


                        headplayer22.x=x_player2+42-400;
                        headplayer22.y=y_player2+3;
                        headplayer22.w=58;
                        headplayer22.h=50;

                        body1player22.x=x_player2+30-400;
                        body1player22.y=y_player2 + 51;
                        body1player22.w=92;
                        body1player22.h=55;

                        body2player22.x=x_player2+55-400;
                        body2player22.y=y_player2 + 107;
                        body2player22.w=55;
                        body2player22.h=67;

                        footplayer22.x=x_player2+30-400;
                        footplayer22.y=y_player2 + 174;
                        footplayer22.w=35;
                        footplayer22.h=35;

                       ball_rect.x=x_ball;
                        ball_rect.y=y_ball;
                       ball_rect.w=60;
                        ball_rect.h=60;


                        if ( SDL_HasIntersection (& ball_rect , & headplayer22))
                        {
                                    if( clock()-control_hitsurface_player2>=500)
                                       {
                                           control_hitsurface_player2=clock();

                                                        if(dx_ball<0 )
                                                        {
                                                            if( x_ball>headplayer2.x+(7.8*headplayer2.w/10))
                                                            {
                                                                dx_ball=-dx_ball;
                                                                if(dy_ball>0)
                                                                dy_ball=-dy_ball;
                                                            }
                                                            else
                                                            {
                                                                if(dy_ball>0)
                                                                dy_ball=-dy_ball;
                                                            }

                                                        }

                                                        else if(dx_ball>0)
                                                        {

                                                           if( x_ball<headplayer2.x+(2.2*headplayer2.w/10))
                                                            {
                                                                dx_ball=-dx_ball;
                                                                if(dy_ball>0)
                                                                dy_ball=-dy_ball;
                                                            }
                                                            else
                                                            {
                                                                if(dy_ball>0)
                                                                dy_ball=-dy_ball;
                                                            }
                                                        }

                                                        if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                                        {
                                                            dx_ball*=1.2;
                                                            clock_player_hit=clock();
                                                        }
                                                        clock_player_hit=clock();


                                                        dy_ball=-15.5;

                                                       // dy_ball=-1.5*abs(dx_ball*0.55);


                                                       if(flag_help3_power_headfireball_player1)
                                                        {
                                                            flag_help4_power_headfireball_player1=true;
                                                            start_clock_help4_headfireball=clock();
                                                        }


                                                        if(flag_help3_power_kickfireball_player1)
                                                        {
                                                            flag_help4_power_kickfireball_player1=true;
                                                            start_clock_help4_kickfireball=clock();
                                                        }


                                                        first_collision_ball=false;flag_first_collision_by_player=false;
                                       }
                        }
                        else if ( SDL_HasIntersection (& ball_rect , & body1player22 ))
                        {
                            if(!(flag_help3_power_headfireball_player1)&& !(flag_help3_power_kickfireball_player1))
                              {
                                        if( clock()-control_hitsurface_player2>=500)
                                       {
                                           control_hitsurface_player2=clock();

                                                        dx_ball=-dx_ball;

                                                        if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                                        {
                                                            dx_ball*=1.2;
                                                            clock_player_hit=clock();
                                                        }

                                                        clock_player_hit=clock();

                                                       first_collision_ball=false;flag_first_collision_by_player=false;

                                       }
                              }
                        }
                        else if ( SDL_HasIntersection (& ball_rect , & body2player22 ))
                        {
                            if(!(flag_help3_power_headfireball_player1)&& !(flag_help3_power_kickfireball_player1))
                              {
                                    if( clock()-control_hitsurface_player2>=500)
                                       {
                                           control_hitsurface_player2=clock();

                                                        dx_ball=-dx_ball;

                                                        if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                                        {
                                                            dx_ball*=2.1;
                                                            clock_player_hit=clock();
                                                        }

                                                        clock_player_hit=clock();

                                                        dy_ball=-21; // tan 34 degree


                                                        first_collision_ball=false;flag_first_collision_by_player=false;
                                       }
                              }
                        }
                        else if ( SDL_HasIntersection (& ball_rect , & footplayer22 ))
                        {
                            if(!(flag_help3_power_headfireball_player1)&& !(flag_help3_power_kickfireball_player1))
                              {
                                    if( clock()-control_hitsurface_player2>=500)
                                       {
                                           control_hitsurface_player2=clock();

                                                        dx_ball=-dx_ball;

                                                        if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                                        {
                                                            dx_ball*=2.1;
                                                            clock_player_hit=clock();
                                                        }
                                                        else if(abs(dx_ball)==1.4*abs(dx0_ball))
                                                        {
                                                            dx_ball*=1.4;
                                                            clock_player_hit=clock();

                                                        }

                                                        clock_player_hit=clock();

                                                        dy_ball=-21; // tan 34 degree

                                                        if(y_ball>footplayer1.y+(7*(footplayer1.h/10)))
                                                            dy_ball=abs(dx_ball*1);   // tan negeative 45 degree

                                                        first_collision_ball=false;flag_first_collision_by_player=false;
                                       }
                              }

                        }
                        }

                        if(counter_play_playing_player2=='0')
                        {

                        headplayer23.x=x_player2+9-200;
                        headplayer23.y=y_player2+3;
                        headplayer23.w=68;
                        headplayer23.h=61;


                        body1player23.x=x_player2+13-200;
                        body1player23.y=y_player2 + 63;
                        body1player23.w=81;
                        body1player23.h=61;

                        body2player23.x=x_player2+31-200;
                        body2player23.y=y_player2 + 125;
                        body2player23.w=56;
                        body2player23.h=54;

                        footplayer23.x=x_player2+42-200;
                        footplayer23.y=y_player2 + 179;
                        footplayer23.w=31;
                        footplayer23.h=40;



                       ball_rect.x=x_ball;
                        ball_rect.y=y_ball;
                       ball_rect.w=60;
                        ball_rect.h=60;


                        if ( SDL_HasIntersection (& ball_rect , & headplayer23))
                        {
                                        if( clock()-control_hitsurface_player2>=500)
                                       {
                                           control_hitsurface_player2=clock();

                                                        if(dx_ball<0 )
                                                        {
                                                            if( x_ball>headplayer2.x+(5*headplayer2.w/10))
                                                            {
                                                                dx_ball=-dx_ball;
                                                                if(dy_ball>0)
                                                                dy_ball=-dy_ball;
                                                            }
                                                            else
                                                            {
                                                                if(dy_ball>0)
                                                                dy_ball=-dy_ball;
                                                            }

                                                        }

                                                        else if(dx_ball>0)
                                                        {

                                                           if( x_ball<headplayer2.x+(2.2*headplayer2.w/10))
                                                            {
                                                                dx_ball=-dx_ball;
                                                                if(dy_ball>0)
                                                                dy_ball=-dy_ball;
                                                            }
                                                            else
                                                            {
                                                                if(dy_ball>0)
                                                                dy_ball=-dy_ball;
                                                            }
                                                        }


                                                        if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                                        {
                                                            dx_ball*=1.2;
                                                            clock_player_hit=clock();
                                                        }

                                                        clock_player_hit=clock();

                                                        dy_ball=-15.5;



                                                        //dy_ball=-1.5*abs(dx_ball*0.55);



                                                first_collision_ball=false;flag_first_collision_by_player=false;


                                                if(flag_help3_power_headfireball_player1)
                                                {
                                                    flag_help4_power_headfireball_player1=true;
                                                    start_clock_help4_headfireball=clock();
                                                }

                                                if(flag_help3_power_kickfireball_player1)
                                                {
                                                    flag_help4_power_kickfireball_player1=true;
                                                    start_clock_help4_kickfireball=clock();
                                                }
                                       }
                        }
                        else if ( SDL_HasIntersection (& ball_rect , & body1player23 ))
                        {
                              if(!(flag_help3_power_headfireball_player1)&& !(flag_help3_power_kickfireball_player1))
                              {


                                        if( clock()-control_hitsurface_player2>=500)
                                       {
                                           control_hitsurface_player2=clock();

                                                        dx_ball=-dx_ball;

                                                        if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                                        {
                                                            dx_ball*=1.2;
                                                            clock_player_hit=clock();
                                                        }

                                                        clock_player_hit=clock();


                                                        first_collision_ball=false;flag_first_collision_by_player=false;
                                       }
                              }

                        }
                        else if ( SDL_HasIntersection (& ball_rect , & body2player23 ))
                        {
                            if(!(flag_help3_power_headfireball_player1)&& !(flag_help3_power_kickfireball_player1))
                              {
                                        if( clock()-control_hitsurface_player2>=500)
                                       {
                                           control_hitsurface_player2=clock();

                                                        dx_ball=-dx_ball;

                                                        if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                                        {
                                                            dx_ball*=1.4;
                                                            clock_player_hit=clock();
                                                        }

                                                        clock_player_hit=clock();

                                                        dy_ball=-1*abs(dx_ball*0.55); // tan 29 degree

                                                        first_collision_ball=false;flag_first_collision_by_player=false;


                                       }
                              }
                        }
                        else if ( SDL_HasIntersection (& ball_rect , & footplayer23 ))
                        {
                            if(!(flag_help3_power_headfireball_player1)&& !(flag_help3_power_kickfireball_player1))
                              {
                                        if( clock()-control_hitsurface_player2>=500)
                                       {
                                           control_hitsurface_player2=clock();

                                                        dx_ball=-dx_ball;

                                                        if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                                        {
                                                            dx_ball*=1.4;
                                                            clock_player_hit=clock();
                                                        }

                                                        clock_player_hit=clock();
                                                        dy_ball=-1*abs(dx_ball*0.55); // tan 29 degree

                                                        if(y_ball>footplayer1.y+(7*(footplayer1.h/10)))
                                                            dy_ball=abs(dx_ball*1);   // tan negeative 45 degree


                                                        first_collision_ball=false;flag_first_collision_by_player=false;

                                       }
                              }

                        }
                        }




                        else if(counter_play_playing_player2=='1')
                        {

                        headplayer23.x=x_player2+8-200;
                        headplayer23.y=y_player2+3;
                        headplayer23.w=70;
                        headplayer23.h=65;

                        body1player23.x=x_player2+12-200;
                        body1player23.y=y_player2 + 64;
                        body1player23.w=69;
                        body1player23.h=81;

                        body2player23.x=x_player2+2-200;
                        body2player23.y=y_player2 + 145;
                        body2player23.w=75;
                        body2player23.h=36;


                        footplayer23.x=x_player2+50-200;
                        footplayer23.y=y_player2 + 182;
                        footplayer23.w=45;
                        footplayer23.h=38;


                       ball_rect.x=x_ball;
                        ball_rect.y=y_ball;
                       ball_rect.w=60;
                        ball_rect.h=60;


                        if ( SDL_HasIntersection (& ball_rect , & headplayer23))
                        {
                                        if( clock()-control_hitsurface_player2>=500)
                                       {
                                           control_hitsurface_player2=clock();

                                                        if(dx_ball<0 )
                                                        {
                                                            if( x_ball>headplayer2.x+(5*headplayer2.w/10))
                                                            {
                                                                dx_ball=-dx_ball;
                                                                if(dy_ball>0)
                                                                dy_ball=-dy_ball;
                                                            }
                                                            else
                                                            {
                                                                if(dy_ball>0)
                                                                dy_ball=-dy_ball;
                                                            }

                                                        }

                                                        else if(dx_ball>0)
                                                        {

                                                           if( x_ball<headplayer2.x+(2.2*headplayer2.w/10))
                                                            {
                                                                dx_ball=-dx_ball;
                                                                if(dy_ball>0)
                                                                dy_ball=-dy_ball;
                                                            }
                                                            else
                                                            {
                                                                if(dy_ball>0)
                                                                dy_ball=-dy_ball;
                                                            }
                                                        }

                                                        if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                                        {
                                                            dx_ball*=1.2;
                                                            clock_player_hit=clock();
                                                        }

                                                        dy_ball=-15.5;

                                                        clock_player_hit=clock();

                                                        //dy_ball=-1.5*abs(dx_ball*0.55);


                                                        if(flag_help3_power_headfireball_player1)
                                                        {
                                                            flag_help4_power_headfireball_player1=true;
                                                            start_clock_help4_headfireball=clock();
                                                        }

                                                        if(flag_help3_power_kickfireball_player1)
                                                        {
                                                            flag_help4_power_kickfireball_player1=true;
                                                            start_clock_help4_kickfireball=clock();
                                                        }


                                                     first_collision_ball=false;flag_first_collision_by_player=false;
                                       }

                        }
                        else if ( SDL_HasIntersection (& ball_rect , & body1player23 ))
                        {
                            if(!(flag_help3_power_headfireball_player1)&& !(flag_help3_power_kickfireball_player1))
                              {
                                        if( clock()-control_hitsurface_player2>=500)
                                       {
                                           control_hitsurface_player2=clock();

                                                        dx_ball=-dx_ball;

                                                        if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                                        {
                                                            dx_ball*=1.2;
                                                            clock_player_hit=clock();
                                                        }

                                                       first_collision_ball=false;flag_first_collision_by_player=false;

                                       }
                              }
                        }
                        else if ( SDL_HasIntersection (& ball_rect , & body2player23 ))
                        {
                            if(!(flag_help3_power_headfireball_player1)&& !(flag_help3_power_kickfireball_player1))
                              {
                                        if( clock()-control_hitsurface_player2>=500)
                                       {
                                           control_hitsurface_player2=clock();

                                                        dx_ball=-dx_ball;

                                                        if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                                        {
                                                            dx_ball*=1.4;
                                                            clock_player_hit=clock();
                                                        }
                                                        clock_player_hit=clock();

                                                        dy_ball=-1*abs(dx_ball*0.55); // tan 29 degree

                                                        first_collision_ball=false;flag_first_collision_by_player=false;
                                       }
                              }
                        }
                        else if ( SDL_HasIntersection (& ball_rect , & footplayer23 ))
                        {

                                 if(!(flag_help3_power_headfireball_player1)&& !(flag_help3_power_kickfireball_player1))
                              {
                                         if( clock()-control_hitsurface_player2>=500)
                                       {
                                           control_hitsurface_player2=clock();

                                                        dx_ball=-dx_ball;

                                                        if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                                        {
                                                            dx_ball*=1.4;
                                                            clock_player_hit=clock();
                                                        }
                                                        clock_player_hit=clock();

                                                        dy_ball=-1*abs(dx_ball*0.55); // tan 29 degree

                                                        if(y_ball>footplayer1.y+(7*(footplayer1.h/10)))
                                                            dy_ball=abs(dx_ball*1);   // tan negeative 45 degree


                                                        first_collision_ball=false;flag_first_collision_by_player=false;

                                       }
                              }
                        }
                        }







                        if(counter_play_playing_player2=='2')
                        {

                        headplayer23.x=x_player2+42-200;
                        headplayer23.y=y_player2+3;
                        headplayer23.w=58;
                        headplayer23.h=50;

                        body1player23.x=x_player2+30-200;
                        body1player23.y=y_player2 + 51;
                        body1player23.w=92;
                        body1player23.h=55;

                        body2player23.x=x_player2+55-200;
                        body2player23.y=y_player2 + 107;
                        body2player23.w=55;
                        body2player23.h=67;

                        footplayer23.x=x_player2+30-200;
                        footplayer23.y=y_player2 + 174;
                        footplayer23.w=35;
                        footplayer23.h=35;



                       ball_rect.x=x_ball;
                        ball_rect.y=y_ball;
                       ball_rect.w=60;
                        ball_rect.h=60;


                        if ( SDL_HasIntersection (& ball_rect , & headplayer2))
                        {
                                    if( clock()-control_hitsurface_player2>=500)
                                       {
                                           control_hitsurface_player2=clock();

                                                        if(dx_ball<0 )
                                                        {
                                                            if( x_ball>headplayer2.x+(7.8*headplayer2.w/10))
                                                            {
                                                                dx_ball=-dx_ball;
                                                                if(dy_ball>0)
                                                                dy_ball=-dy_ball;
                                                            }
                                                            else
                                                            {
                                                                if(dy_ball>0)
                                                                dy_ball=-dy_ball;
                                                            }

                                                        }

                                                        else if(dx_ball>0)
                                                        {

                                                           if( x_ball<headplayer2.x+(2.2*headplayer2.w/10))
                                                            {
                                                                dx_ball=-dx_ball;
                                                                if(dy_ball>0)
                                                                dy_ball=-dy_ball;
                                                            }
                                                            else
                                                            {
                                                                if(dy_ball>0)
                                                                dy_ball=-dy_ball;
                                                            }
                                                        }

                                                        if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                                        {
                                                            dx_ball*=1.2;
                                                            clock_player_hit=clock();
                                                        }
                                                        clock_player_hit=clock();


                                                        dy_ball=-15.5;

                                                       // dy_ball=-1.5*abs(dx_ball*0.55);


                                                       if(flag_help3_power_headfireball_player1)
                                                        {
                                                            flag_help4_power_headfireball_player1=true;
                                                            start_clock_help4_headfireball=clock();
                                                        }


                                                        if(flag_help3_power_kickfireball_player1)
                                                        {
                                                            flag_help4_power_kickfireball_player1=true;
                                                            start_clock_help4_kickfireball=clock();
                                                        }


                                                        first_collision_ball=false;flag_first_collision_by_player=false;
                                       }
                        }
                        else if ( SDL_HasIntersection (& ball_rect , & body1player23 ))
                        {
                            if(!(flag_help3_power_headfireball_player1)&& !(flag_help3_power_kickfireball_player1))
                              {
                                        if( clock()-control_hitsurface_player2>=500)
                                       {
                                           control_hitsurface_player2=clock();

                                                        dx_ball=-dx_ball;

                                                        if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                                        {
                                                            dx_ball*=1.2;
                                                            clock_player_hit=clock();
                                                        }

                                                        clock_player_hit=clock();

                                                       first_collision_ball=false;flag_first_collision_by_player=false;

                                       }
                              }
                        }
                        else if ( SDL_HasIntersection (& ball_rect , & body2player23 ))
                        {
                            if(!(flag_help3_power_headfireball_player1)&& !(flag_help3_power_kickfireball_player1))
                              {
                                    if( clock()-control_hitsurface_player2>=500)
                                       {
                                           control_hitsurface_player2=clock();

                                                        dx_ball=-dx_ball;

                                                        if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                                        {
                                                            dx_ball*=2.1;
                                                            clock_player_hit=clock();
                                                        }

                                                        clock_player_hit=clock();

                                                        dy_ball=-21; // tan 34 degree


                                                        first_collision_ball=false;flag_first_collision_by_player=false;
                                       }
                              }
                        }
                        else if ( SDL_HasIntersection (& ball_rect , & footplayer23 ))
                        {
                            if(!(flag_help3_power_headfireball_player1)&& !(flag_help3_power_kickfireball_player1))
                              {
                                    if( clock()-control_hitsurface_player2>=500)
                                       {
                                           control_hitsurface_player2=clock();

                                                        dx_ball=-dx_ball;

                                                        if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                                        {
                                                            dx_ball*=2.1;
                                                            clock_player_hit=clock();
                                                        }
                                                        else if(abs(dx_ball)==1.4*abs(dx0_ball))
                                                        {
                                                            dx_ball*=1.4;
                                                            clock_player_hit=clock();

                                                        }

                                                        clock_player_hit=clock();

                                                        dy_ball=-21; // tan 34 degree

                                                        if(y_ball>footplayer1.y+(7*(footplayer1.h/10)))
                                                            dy_ball=abs(dx_ball*1);   // tan negeative 45 degree

                                                        first_collision_ball=false;flag_first_collision_by_player=false;
                                       }
                              }

                        }
                        }





            }


            if(flag_power_tripleclone_player1)
            {
                counter_power_handling_player1=0;


                if(clock()-start_clock_tripleclone_player1>=8000)
                {
                    flag_power_tripleclone_player1=false;
                }



                            if(counter_play_playing_player1=='0')
                            {

                            headplayer12.x=200+x_player1+32;
                            headplayer12.y=y_player1+3;
                            headplayer12.w=56;
                            headplayer12.h=51;

                            body1player12.x=200+x_player1+20;
                            body1player12.y=y_player1 +46;
                            body1player12.w=67;
                            body1player12.h=54;

                            body2player12.x=200+x_player1+24;
                            body2player12.y=y_player1 + 100;
                            body2player12.w=66;
                            body2player12.h=70;


                            footplayer12.x=200+x_player1+7;
                            footplayer12.y=y_player1 + 168;
                            footplayer12.w=45;
                            footplayer12.h=51;


                           ball_rect.x=x_ball;
                            ball_rect.y=y_ball;
                           ball_rect.w=60;
                            ball_rect.h=60;



                            if ( SDL_HasIntersection (& ball_rect , & headplayer12 ))
                            {
                                           if( clock()-control_hitsurface_player1>=500)
                                           {
                                               control_hitsurface_player1=clock();

                                                            if(dx_ball<0 )
                                                            {
                                                                if( x_ball>headplayer1.x+(2.2*headplayer1.w/10))
                                                                {
                                                                    dx_ball=-dx_ball;
                                                                    if(dy_ball>0)
                                                                    dy_ball=-dy_ball;
                                                                }
                                                                else
                                                                {
                                                                    if(dy_ball>0)
                                                                    dy_ball=-dy_ball;
                                                                }

                                                            }

                                                            else if(dx_ball>0)
                                                            {

                                                               if( x_ball<headplayer1.x+(2.2*headplayer1.w/10))
                                                                {
                                                                    dx_ball=-dx_ball;
                                                                    if(dy_ball>0)
                                                                    dy_ball=-dy_ball;
                                                                }
                                                                else
                                                                {
                                                                    if(dy_ball>0)
                                                                    dy_ball=-dy_ball;
                                                                }
                                                            }

                                                            if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                                            {
                                                                dx_ball*=1.2;

                                                            }
                                                                clock_player_hit=clock();


                                                            dy_ball=-15.5;


                                                           first_collision_ball=false;flag_first_collision_by_player=false;


                                                           if(flag_help3_power_headfireball_player2)
                                                            {
                                                                flag_help4_power_headfireball_player2=true;
                                                                start_clock_help4_headfireball2=clock();
                                                            }

                                                            if(flag_help3_power_kickfireball_player2)
                                                            {
                                                                flag_help4_power_kickfireball_player2=true;
                                                                start_clock_help4_kickfireball2=clock();
                                                            }


                                           }


                            }
                            else if ( SDL_HasIntersection (& ball_rect , & body1player12 ))
                            {
                                if(!(flag_help3_power_headfireball_player2) && !(flag_help3_power_kickfireball_player2))
                                  {
                                            if( clock()-control_hitsurface_player1>=500)
                                           {
                                               control_hitsurface_player1=clock();

                                                            dx_ball=-dx_ball;

                                                            if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                                            {
                                                                dx_ball*=1.2;

                                                            }
                                                            clock_player_hit=clock();
                                                            first_collision_ball=false;flag_first_collision_by_player=false;


                                           }
                                  }




                            }
                            else if ( SDL_HasIntersection (& ball_rect , & body2player12 ))
                            {
                                if(!(flag_help3_power_headfireball_player2)&& !(flag_help3_power_kickfireball_player2))
                                  {
                                            if( clock()-control_hitsurface_player1>=500)
                                           {
                                               control_hitsurface_player1=clock();


                                                            dx_ball=-dx_ball;


                                                            if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                                            {
                                                                dx_ball*=1.4;

                                                            }

                                                            clock_player_hit=clock();
                                                            dy_ball=-1*abs(dx_ball*0.55); // tan 29 degree




                                                            first_collision_ball=false;flag_first_collision_by_player=false;


                                           }
                                  }


                            }
                            else if ( SDL_HasIntersection (& ball_rect , & footplayer12 ))
                            {
                                if(!(flag_help3_power_headfireball_player2)&& !(flag_help3_power_kickfireball_player2))
                                  {
                                            if( clock()-control_hitsurface_player1>=500)
                                           {
                                               control_hitsurface_player1=clock();

                                                            dx_ball=-dx_ball;


                                                            if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                                            {
                                                                dx_ball*=1.4;

                                                            }

                                                            clock_player_hit=clock();
                                                            dy_ball=-1*abs(dx_ball*0.55); // tan 29 degree

                                                            if(y_ball>footplayer1.y+(7*(footplayer1.h/10)))
                                                                dy_ball=abs(dx_ball*1);   // tan negeative 45 degree




                                                            first_collision_ball=false;flag_first_collision_by_player=false;

                    //
                                           }
                                  }

                            }
                            }

                            else if(counter_play_playing_player1=='1')
                            {

                            headplayer12.x=200+x_player1+30;
                            headplayer12.y=y_player1+4;
                            headplayer12.w=55;
                            headplayer12.h=42;

                            body1player12.x=200+x_player1+7;
                            body1player12.y=y_player1 + 44;
                            body1player12.w=77;
                            body1player12.h=60;

                            body2player12.x=200+x_player1+11;
                            body2player12.y=y_player1 + 105;
                            body2player12.w=56;
                            body2player12.h=72;


                            footplayer12.x=200+x_player1+30;
                            footplayer12.y=y_player1 + 177;
                            footplayer12.w=30;
                            footplayer12.h=42;



                           ball_rect.x=x_ball;
                            ball_rect.y=y_ball;
                           ball_rect.w=60;
                            ball_rect.h=60;




                            if ( SDL_HasIntersection (& ball_rect , & headplayer12 ))
                            {
                                            if( clock()-control_hitsurface_player1>=500)
                                           {
                                               control_hitsurface_player1=clock();

                                                            if(dx_ball<0 )
                                                            {
                                                                if( x_ball>headplayer1.x+(2.2*headplayer1.w/10))
                                                                {
                                                                    dx_ball=-dx_ball;
                                                                    if(dy_ball>0)
                                                                    dy_ball=-dy_ball;
                                                                }
                                                                else
                                                                {
                                                                    if(dy_ball>0)
                                                                    dy_ball=-dy_ball;
                                                                }

                                                            }

                                                            else if(dx_ball>0)
                                                            {

                                                               if( x_ball<headplayer1.x+(2.2*headplayer1.w/10))
                                                                {
                                                                    dx_ball=-dx_ball;
                                                                    if(dy_ball>0)
                                                                    dy_ball=-dy_ball;
                                                                }
                                                                else
                                                                {
                                                                    if(dy_ball>0)
                                                                    dy_ball=-dy_ball;
                                                                }
                                                            }


                                                            if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                                            {
                                                                dx_ball*=1.2;

                                                            }
                                                            dy_ball=-15.5;



                                                            clock_player_hit=clock();
                                                            //dy_ball=-1.5*abs(dx_ball*0.55);




                                                           first_collision_ball=false;flag_first_collision_by_player=false;


                                                           if(flag_help3_power_headfireball_player2)
                                                            {
                                                                flag_help4_power_headfireball_player2=true;
                                                                start_clock_help4_headfireball2=clock();
                                                            }

                                                            if(flag_help3_power_kickfireball_player2)
                                                            {
                                                                flag_help4_power_kickfireball_player2=true;
                                                                start_clock_help4_kickfireball2=clock();
                                                            }


                                           }
                            }
                            else if ( SDL_HasIntersection (& ball_rect , & body1player12 ))
                            {
                                if(!(flag_help3_power_headfireball_player2)&& !(flag_help3_power_kickfireball_player2))
                                  {
                                            if( clock()-control_hitsurface_player1>=500)
                                           {
                                               control_hitsurface_player1=clock();

                                                            dx_ball=-dx_ball;

                                                            if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                                            {
                                                                dx_ball*=1.2;
                                                                clock_player_hit=clock();
                                                            }

                                                           first_collision_ball=false;flag_first_collision_by_player=false;


                                           }
                                  }
                            }
                            else if ( SDL_HasIntersection (& ball_rect , & body2player12 ))
                            {

                                   if(!(flag_help3_power_headfireball_player2)&& !(flag_help3_power_kickfireball_player2))
                                  {
                                               if( clock()-control_hitsurface_player1>=500)
                                           {
                                               control_hitsurface_player1=clock();

                                                            dx_ball=-dx_ball;

                                                            if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                                            {
                                                                dx_ball*=1.4;

                                                            }
                                                            clock_player_hit=clock();

                                                            dy_ball=-1*abs(dx_ball*0.55); // tan 29 degree


                                                           first_collision_ball=false;flag_first_collision_by_player=false;


                                           }
                                  }
                            }
                            else if ( SDL_HasIntersection (& ball_rect , & footplayer12 ))
                            {
                                  if(!(flag_help3_power_headfireball_player2)&& !(flag_help3_power_kickfireball_player2))
                                  {

                                                if( clock()-control_hitsurface_player1>=500)
                                           {
                                               control_hitsurface_player1=clock();

                                                            dx_ball=-dx_ball;

                                                            if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                                            {
                                                                dx_ball*=1.4;

                                                            }
                                                            clock_player_hit=clock();

                                                            dy_ball=-1*abs(dx_ball*0.55); // tan 29 degree

                                                            if(y_ball>footplayer1.y+(7*(footplayer1.h/10)))
                                                                dy_ball=abs(dx_ball*1);   // tan negeative 45 degree


                                                            first_collision_ball=false;flag_first_collision_by_player=false;



                                           }
                                  }

                            }
                            }


                            else if(counter_play_playing_player1=='2')
                            {

                            headplayer12.x=200+x_player1+40;
                            headplayer12.y=y_player1+3;
                            headplayer12.w=47;
                            headplayer12.h=48;

                            body1player12.x=200+x_player1+12;
                            body1player12.y=y_player1 + 50;
                            body1player12.w=80;
                            body1player12.h=43;

                            body2player12.x=200+x_player1+26;
                            body2player12.y=y_player1 + 93;
                            body2player12.w=60;
                            body2player12.h=80;

                            footplayer12.x=200+x_player1+64;
                            footplayer12.y=y_player1 + 174;
                            footplayer12.w=40;
                            footplayer12.h=54;



                           ball_rect.x=x_ball;
                            ball_rect.y=y_ball;
                           ball_rect.w=60;
                            ball_rect.h=80;



                            if ( SDL_HasIntersection (& ball_rect , & headplayer12 ))
                            {


                                           if( clock()-control_hitsurface_player1>=500)
                                           {
                                               control_hitsurface_player1=clock();

                                                            if(dx_ball<0 )
                                                            {
                                                                if( x_ball>headplayer1.x+(2.2*headplayer1.w/10))
                                                                {
                                                                    dx_ball=-dx_ball;
                                                                    if(dy_ball>0)
                                                                    dy_ball=-dy_ball;
                                                                }
                                                                else
                                                                {
                                                                    if(dy_ball>0)
                                                                    dy_ball=-dy_ball;
                                                                }

                                                            }

                                                            else if(dx_ball>0)
                                                            {

                                                               if( x_ball<headplayer1.x+(2.2*headplayer1.w/10))
                                                                {
                                                                    dx_ball=-dx_ball;
                                                                    if(dy_ball>0)
                                                                    dy_ball=-dy_ball;
                                                                }
                                                                else
                                                                {
                                                                    if(dy_ball>0)
                                                                    dy_ball=-dy_ball;
                                                                }
                                                            }

                                                            if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                                            {
                                                                dx_ball*=1.2;

                                                            }

                                                            dy_ball=-15.5;



                                                            clock_player_hit=clock();
                                                            //dy_ball=-1.5*abs(dx_ball*0.55);


                                                            first_collision_ball=false;flag_first_collision_by_player=false;

                                                            if(flag_help3_power_headfireball_player2)
                                                            {
                                                                flag_help4_power_headfireball_player2=true;
                                                                start_clock_help4_headfireball2=clock();
                                                            }

                                                            if(flag_help3_power_kickfireball_player2)
                                                            {
                                                                flag_help4_power_kickfireball_player2=true;
                                                                start_clock_help4_kickfireball2=clock();
                                                            }


                                           }



                            }
                            else if ( SDL_HasIntersection (& ball_rect , & body1player12 ))
                            {
                                if(!(flag_help3_power_headfireball_player2)&& !(flag_help3_power_kickfireball_player2))
                                  {

                                        if( clock()-control_hitsurface_player1>=500)
                                           {
                                               control_hitsurface_player1=clock();

                                                            dx_ball=-dx_ball;

                                                            if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                                            {
                                                                dx_ball*=1.2;

                                                            }

                                                            clock_player_hit=clock();

                                                            first_collision_ball=false;flag_first_collision_by_player=false;
                                           }
                                  }


                            }
                            else if ( SDL_HasIntersection (& ball_rect , & body2player12 ))
                            {
                                if(!(flag_help3_power_headfireball_player2)&& !(flag_help3_power_kickfireball_player2))
                                  {

                                            if( clock()-control_hitsurface_player1>=500)
                                           {
                                               control_hitsurface_player1=clock();

                                                            dx_ball=-dx_ball;

                                                            if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                                            {
                                                                dx_ball*=2.1;

                                                            }

                                                            clock_player_hit=clock();

                                                            dy_ball=-21; // tan 34 degree



                                                            first_collision_ball=false;flag_first_collision_by_player=false;
                                           }
                                  }
                            }
                            else if ( SDL_HasIntersection (& ball_rect , & footplayer12 ))
                            {
                                if(!(flag_help3_power_headfireball_player2)&& !(flag_help3_power_kickfireball_player2))
                                  {

                                            if( clock()-control_hitsurface_player1>=500)
                                           {
                                               control_hitsurface_player1=clock();

                                                            dx_ball=-dx_ball;

                                                            if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                                            {
                                                                dx_ball*=2.1;
                                                                clock_player_hit=clock();
                                                            }
                                                            else if(abs(dx_ball)==1.4*abs(dx0_ball))
                                                            {
                                                                dx_ball*=1.4;
                                                                clock_player_hit=clock();

                                                            }
                                                            clock_player_hit=clock();

                                                            dy_ball=-21; // tan 34 degree

                                                            if(y_ball>footplayer1.y+(7*(footplayer1.h/10)))
                                                                dy_ball=abs(dx_ball*1);   // tan negeative 45 degree


                                                            first_collision_ball=false;flag_first_collision_by_player=false;


                                           }
                                  }
                            }
                            }


                            if(counter_play_playing_player1=='0')
                            {


                            headplayer13.x=400+x_player1+32;
                            headplayer13.y=y_player1+3;
                            headplayer13.w=56;
                            headplayer13.h=51;


                            body1player13.x=400+x_player1+20;
                            body1player13.y=y_player1 +46;
                            body1player13.w=67;
                            body1player13.h=54;


                            body2player13.x=400+x_player1+24;
                            body2player13.y=y_player1 + 100;
                            body2player13.w=66;
                            body2player13.h=70;

                            footplayer13.x=400+x_player1+7;
                            footplayer13.y=y_player1 + 168;
                            footplayer13.w=45;
                            footplayer13.h=51;


                           ball_rect.x=x_ball;
                            ball_rect.y=y_ball;
                           ball_rect.w=60;
                            ball_rect.h=60;



                            if ( SDL_HasIntersection (& ball_rect , & headplayer13 ))
                            {
                                           if( clock()-control_hitsurface_player1>=500)
                                           {
                                               control_hitsurface_player1=clock();

                                                            if(dx_ball<0 )
                                                            {
                                                                if( x_ball>headplayer1.x+(2.2*headplayer1.w/10))
                                                                {
                                                                    dx_ball=-dx_ball;
                                                                    if(dy_ball>0)
                                                                    dy_ball=-dy_ball;
                                                                }
                                                                else
                                                                {
                                                                    if(dy_ball>0)
                                                                    dy_ball=-dy_ball;
                                                                }

                                                            }

                                                            else if(dx_ball>0)
                                                            {

                                                               if( x_ball<headplayer1.x+(2.2*headplayer1.w/10))
                                                                {
                                                                    dx_ball=-dx_ball;
                                                                    if(dy_ball>0)
                                                                    dy_ball=-dy_ball;
                                                                }
                                                                else
                                                                {
                                                                    if(dy_ball>0)
                                                                    dy_ball=-dy_ball;
                                                                }
                                                            }

                                                            if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                                            {
                                                                dx_ball*=1.2;

                                                            }
                                                                clock_player_hit=clock();


                                                            dy_ball=-15.5;


                                                           first_collision_ball=false;flag_first_collision_by_player=false;


                                                           if(flag_help3_power_headfireball_player2)
                                                            {
                                                                flag_help4_power_headfireball_player2=true;
                                                                start_clock_help4_headfireball2=clock();
                                                            }

                                                            if(flag_help3_power_kickfireball_player2)
                                                            {
                                                                flag_help4_power_kickfireball_player2=true;
                                                                start_clock_help4_kickfireball2=clock();
                                                            }

                                           }


                            }
                            else if ( SDL_HasIntersection (& ball_rect , & body1player13 ))
                            {
                                if(!(flag_help3_power_headfireball_player2) && !(flag_help3_power_kickfireball_player2))
                                  {
                                            if( clock()-control_hitsurface_player1>=500)
                                           {
                                               control_hitsurface_player1=clock();

                                                            dx_ball=-dx_ball;

                                                            if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                                            {
                                                                dx_ball*=1.2;

                                                            }
                                                            clock_player_hit=clock();
                                                            first_collision_ball=false;flag_first_collision_by_player=false;

                                           }
                                  }




                            }
                            else if ( SDL_HasIntersection (& ball_rect , & body2player13 ))
                            {
                                if(!(flag_help3_power_headfireball_player2)&& !(flag_help3_power_kickfireball_player2))
                                  {
                                            if( clock()-control_hitsurface_player1>=500)
                                           {
                                               control_hitsurface_player1=clock();


                                                            dx_ball=-dx_ball;


                                                            if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                                            {
                                                                dx_ball*=1.4;

                                                            }

                                                            clock_player_hit=clock();
                                                            dy_ball=-1*abs(dx_ball*0.55); // tan 29 degree




                                                            first_collision_ball=false;flag_first_collision_by_player=false;


                                           }
                                  }


                            }
                            else if ( SDL_HasIntersection (& ball_rect , & footplayer13 ))
                            {
                                if(!(flag_help3_power_headfireball_player2)&& !(flag_help3_power_kickfireball_player2))
                                  {
                                            if( clock()-control_hitsurface_player1>=500)
                                           {
                                               control_hitsurface_player1=clock();

                                                            dx_ball=-dx_ball;


                                                            if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                                            {
                                                                dx_ball*=1.4;

                                                            }

                                                            clock_player_hit=clock();
                                                            dy_ball=-1*abs(dx_ball*0.55); // tan 29 degree

                                                            if(y_ball>footplayer1.y+(7*(footplayer1.h/10)))
                                                                dy_ball=abs(dx_ball*1);   // tan negeative 45 degree




                                                            first_collision_ball=false;flag_first_collision_by_player=false;


                    //
                                           }
                                  }

                            }
                            }

                            else if(counter_play_playing_player1=='1')
                            {


                    //        if(x_ball>x_player1)
                    //        headplayer1.x=x_player1+28;
                    //        else
                            headplayer13.x=400+x_player1+30;
                            headplayer13.y=y_player1+4;
                            headplayer13.w=55;
                            headplayer13.h=42;



                    //        if(x_ball>x_player1)
                    //        body1player1.x=x_player1+80;
                    //        else
                            body1player13.x=400+x_player1+7;
                            body1player13.y=y_player1 + 44;
                            body1player13.w=77;
                            body1player13.h=60;


                    //        if(x_ball>x_player1)
                    //        body2player1.x=x_player1+50;
                    //        else
                            body2player13.x=400+x_player1+11;
                            body2player13.y=y_player1 + 105;
                            body2player13.w=56;
                            body2player13.h=72;



                    //        if(x_ball>x_player1)
                    //        footplayer1.x=x_player1+60;
                    //        else
                            footplayer13.x=400+x_player1+30;
                            footplayer13.y=y_player1 + 177;
                            footplayer13.w=30;
                            footplayer13.h=42;



                           ball_rect.x=x_ball;
                            ball_rect.y=y_ball;
                           ball_rect.w=60;
                            ball_rect.h=60;




                            if ( SDL_HasIntersection (& ball_rect , & headplayer13 ))
                            {
                                            if( clock()-control_hitsurface_player1>=500)
                                           {
                                               control_hitsurface_player1=clock();

                                                            if(dx_ball<0 )
                                                            {
                                                                if( x_ball>headplayer1.x+(2.2*headplayer1.w/10))
                                                                {
                                                                    dx_ball=-dx_ball;
                                                                    if(dy_ball>0)
                                                                    dy_ball=-dy_ball;
                                                                }
                                                                else
                                                                {
                                                                    if(dy_ball>0)
                                                                    dy_ball=-dy_ball;
                                                                }

                                                            }

                                                            else if(dx_ball>0)
                                                            {

                                                               if( x_ball<headplayer1.x+(2.2*headplayer1.w/10))
                                                                {
                                                                    dx_ball=-dx_ball;
                                                                    if(dy_ball>0)
                                                                    dy_ball=-dy_ball;
                                                                }
                                                                else
                                                                {
                                                                    if(dy_ball>0)
                                                                    dy_ball=-dy_ball;
                                                                }
                                                            }


                                                            if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                                            {
                                                                dx_ball*=1.2;

                                                            }
                                                            dy_ball=-15.5;



                                                            clock_player_hit=clock();
                                                            //dy_ball=-1.5*abs(dx_ball*0.55);




                                                           first_collision_ball=false;flag_first_collision_by_player=false;


                                                           if(flag_help3_power_headfireball_player2)
                                                            {
                                                                flag_help4_power_headfireball_player2=true;
                                                                start_clock_help4_headfireball2=clock();
                                                            }

                                                            if(flag_help3_power_kickfireball_player2)
                                                            {
                                                                flag_help4_power_kickfireball_player2=true;
                                                                start_clock_help4_kickfireball2=clock();
                                                            }


                                           }
                            }
                            else if ( SDL_HasIntersection (& ball_rect , & body1player13 ))
                            {
                                if(!(flag_help3_power_headfireball_player2)&& !(flag_help3_power_kickfireball_player2))
                                  {
                                            if( clock()-control_hitsurface_player1>=500)
                                           {
                                               control_hitsurface_player1=clock();

                                                            dx_ball=-dx_ball;

                                                            if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                                            {
                                                                dx_ball*=1.2;
                                                                clock_player_hit=clock();
                                                            }

                                                           first_collision_ball=false;flag_first_collision_by_player=false;


                                           }
                                  }
                            }
                            else if ( SDL_HasIntersection (& ball_rect , & body2player13 ))
                            {

                                   if(!(flag_help3_power_headfireball_player2)&& !(flag_help3_power_kickfireball_player2))
                                  {
                                               if( clock()-control_hitsurface_player1>=500)
                                           {
                                               control_hitsurface_player1=clock();

                                                            dx_ball=-dx_ball;

                                                            if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                                            {
                                                                dx_ball*=1.4;

                                                            }
                                                            clock_player_hit=clock();

                                                            dy_ball=-1*abs(dx_ball*0.55); // tan 29 degree


                                                           first_collision_ball=false;flag_first_collision_by_player=false;


                                           }
                                  }
                            }
                            else if ( SDL_HasIntersection (& ball_rect , & footplayer13 ))
                            {
                                  if(!(flag_help3_power_headfireball_player2)&& !(flag_help3_power_kickfireball_player2))
                                  {

                                                if( clock()-control_hitsurface_player1>=500)
                                           {
                                               control_hitsurface_player1=clock();

                                                            dx_ball=-dx_ball;

                                                            if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                                            {
                                                                dx_ball*=1.4;

                                                            }
                                                            clock_player_hit=clock();

                                                            dy_ball=-1*abs(dx_ball*0.55); // tan 29 degree

                                                            if(y_ball>footplayer1.y+(7*(footplayer1.h/10)))
                                                                dy_ball=abs(dx_ball*1);   // tan negeative 45 degree


                                                            first_collision_ball=false;flag_first_collision_by_player=false;



                                           }
                                  }

                            }
                            }


                            else if(counter_play_playing_player1=='2')
                            {

                            headplayer13.x=400+x_player1+40;
                            headplayer13.y=y_player1+3;
                            headplayer13.w=47;
                            headplayer13.h=48;

                            body1player13.x=400+x_player1+12;
                            body1player13.y=y_player1 + 50;
                            body1player13.w=80;
                            body1player13.h=43;


                            body2player13.x=x_player1+26;
                            body2player13.y=y_player1 + 93;
                            body2player13.w=60;
                            body2player13.h=80;


                            footplayer13.x=400+x_player1+64;
                            footplayer13.y=y_player1 + 174;
                            footplayer13.w=40;
                            footplayer13.h=54;


                           ball_rect.x=x_ball;
                            ball_rect.y=y_ball;
                           ball_rect.w=60;
                            ball_rect.h=80;



                            if ( SDL_HasIntersection (& ball_rect , & headplayer13 ))
                            {


                                           if( clock()-control_hitsurface_player1>=500)
                                           {
                                               control_hitsurface_player1=clock();

                                                            if(dx_ball<0 )
                                                            {
                                                                if( x_ball>headplayer1.x+(2.2*headplayer1.w/10))
                                                                {
                                                                    dx_ball=-dx_ball;
                                                                    if(dy_ball>0)
                                                                    dy_ball=-dy_ball;
                                                                }
                                                                else
                                                                {
                                                                    if(dy_ball>0)
                                                                    dy_ball=-dy_ball;
                                                                }

                                                            }

                                                            else if(dx_ball>0)
                                                            {

                                                               if( x_ball<headplayer1.x+(2.2*headplayer1.w/10))
                                                                {
                                                                    dx_ball=-dx_ball;
                                                                    if(dy_ball>0)
                                                                    dy_ball=-dy_ball;
                                                                }
                                                                else
                                                                {
                                                                    if(dy_ball>0)
                                                                    dy_ball=-dy_ball;
                                                                }
                                                            }

                                                            if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                                            {
                                                                dx_ball*=1.2;

                                                            }

                                                            dy_ball=-15.5;



                                                            clock_player_hit=clock();
                                                            //dy_ball=-1.5*abs(dx_ball*0.55);


                                                            first_collision_ball=false;flag_first_collision_by_player=false;

                                                            if(flag_help3_power_headfireball_player2)
                                                            {
                                                                flag_help4_power_headfireball_player2=true;
                                                                start_clock_help4_headfireball2=clock();
                                                            }

                                                            if(flag_help3_power_kickfireball_player2)
                                                            {
                                                                flag_help4_power_kickfireball_player2=true;
                                                                start_clock_help4_kickfireball2=clock();
                                                            }


                                           }



                            }
                            else if ( SDL_HasIntersection (& ball_rect , & body1player13 ))
                            {
                                if(!(flag_help3_power_headfireball_player2)&& !(flag_help3_power_kickfireball_player2))
                                  {

                                        if( clock()-control_hitsurface_player1>=500)
                                           {
                                               control_hitsurface_player1=clock();

                                                            dx_ball=-dx_ball;

                                                            if(abs(dx_ball)==abs(dx0_ball)  || abs(dx_ball)==1.4*abs(dx0_ball))
                                                            {
                                                                dx_ball*=1.2;

                                                            }

                                                            clock_player_hit=clock();

                                                            first_collision_ball=false;flag_first_collision_by_player=false;
                                           }
                                  }


                            }
                            else if ( SDL_HasIntersection (& ball_rect , & body2player13 ))
                            {
                                if(!(flag_help3_power_headfireball_player2)&& !(flag_help3_power_kickfireball_player2))
                                  {

                                            if( clock()-control_hitsurface_player1>=500)
                                           {
                                               control_hitsurface_player1=clock();

                                                            dx_ball=-dx_ball;

                                                            if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                                            {
                                                                dx_ball*=2.1;

                                                            }

                                                            clock_player_hit=clock();

                                                            dy_ball=-21; // tan 34 degree



                                                            first_collision_ball=false;flag_first_collision_by_player=false;
                                           }
                                  }
                            }
                            else if ( SDL_HasIntersection (& ball_rect , & footplayer13 ))
                            {
                                if(!(flag_help3_power_headfireball_player2)&& !(flag_help3_power_kickfireball_player2))
                                  {

                                            if( clock()-control_hitsurface_player1>=500)
                                           {
                                               control_hitsurface_player1=clock();

                                                            dx_ball=-dx_ball;

                                                            if(abs(dx_ball)==abs(dx0_ball) || abs(dx_ball)==1.2*abs(dx0_ball))
                                                            {
                                                                dx_ball*=2.1;
                                                                clock_player_hit=clock();
                                                            }
                                                            else if(abs(dx_ball)==1.4*abs(dx0_ball))
                                                            {
                                                                dx_ball*=1.4;
                                                                clock_player_hit=clock();

                                                            }
                                                            clock_player_hit=clock();

                                                            dy_ball=-21; // tan 34 degree

                                                            if(y_ball>footplayer1.y+(7*(footplayer1.h/10)))
                                                                dy_ball=abs(dx_ball*1);   // tan negeative 45 degree


                                                            first_collision_ball=false;flag_first_collision_by_player=false;


                                           }
                                  }
                            }
                            }



            }



            if(flag_power_punch_player1)
            {


                if(x_player2-x_player1-W_player1<=70)
                {
                    counter_power_handling_player1=0;

                    w_punch=x_player2-x_player1-W_player1;
                    flag_help_power_punch_player1=true;
                    flag_help2_power_punch_player1=true;

                    counter_play_playing_player1='2';

                    start_clock_help_punch=clock();
                    start_clock_help2_punch=clock();
                }
                flag_power_punch_player1=false;

            }

            if(flag_power_punch_player2)
            {


                if(x_player2-x_player1-W_player1<=70)
                {
                    counter_power_handling_player2=0;

                    w_punch=x_player2-x_player1-W_player1;
                    flag_help_power_punch_player2=true;
                    flag_help2_power_punch_player2=true;

                    counter_play_playing_player2='2';

                    start_clock_help_punch2=clock();
                    start_clock_help2_punch2=clock();
                }
                flag_power_punch_player2=false;

            }



                        if(flag_power_headfireball_player1)
                        {


                            if(641-y_ball-60 > W_player1 && y_player1==480)
                            {

                                first_collision_ball=false;flag_first_collision_by_player=false;

                                counter_power_handling_player1=0;

                                count_dx_player2=0;


                                flag_help_power_headfireball_player1=true;

                                dx_ball=0;dy_ball=-1.00;

                                dy_player1_help=(y_ball-y_player1+10)/6;

                                dx_player1_help=(x_ball-x_player1)/6;
                            }

                            flag_power_headfireball_player1=false;





                        }

                        if(flag_help_power_headfireball_player1)
                        {

                            dx_ball=0;dy_ball=-1.00;



                                x_player1+=dx_player1_help;

                                y_player1+=dy_player1_help;

                                if(counter_play_playing_player1=='0')
                                {
                                headplayer1.x=x_player1+30;
                                headplayer1.y=y_player1-5;
                                headplayer1.w=45;
                                headplayer1.h=51;
                                }
                                else if(counter_play_playing_player1=='1')
                                {
                                    headplayer1.x=x_player1+30;
                                    headplayer1.y=y_player1+4;
                                    headplayer1.w=45;
                                    headplayer1.h=42;
                                }

                                if ( SDL_HasIntersection (& ball_rect , & headplayer1 ))
                                {
                                    flag_help_power_headfireball_player1=false;
                                    if(H_secondgoal/(x_ball-x_secondgoal)<=1)
                                    {

                                        dx_ball=75;
                                        dy_ball=17;

                                    }
                                    flag_help2_power_headfireball_player1=true;
                                    flag_help3_power_headfireball_player1=true;
                                    start_clock_help3_headfireball=clock();
                                }


                        }

                        if(flag_help2_power_headfireball_player1)
                        {


                            if(start_jump_player1<0)
                            {
                                start_jump_player1=-start_jump_player1;
                            }

                            dy_player1_help=25;
                            if(y_player1<480)
                            {

                                y_player1+=dy_player1_help;
                                if(y_player1>480)
                                {
                                    y_player1=480;
                                    flag_help2_power_headfireball_player1=false;
                                }



                            }
                            else
                            {
                                flag_help2_power_headfireball_player1=false;
                            }



                        }

                        if(clock()-start_clock_help3_headfireball>=1200)
                        {
                            flag_help3_power_headfireball_player1=false;
                        }



                        if(flag_help3_power_headfireball_player1)
                        {
                             if( SDL_HasIntersection (& ball_rect , & body1player2 ))
                             {
                                 if(count_dx_player2<200)
                                 {
                                     if(dx_ball>0)
                                     {
                                     x_player2+=dx_ball;
                                     count_dx_player2+=dx_ball;

                                     }

                                }
                                else
                                {
                                    dx_ball=-dx_ball;
                                    flag_help3_power_headfireball_player1=false;
                                }
                             }
                            else if ( SDL_HasIntersection (& ball_rect , & body2player2 ))
                            {
                                if(count_dx_player2<200)
                                 {
                                     if(dx_ball>0)
                                     {
                                     x_player2+=dx_ball;
                                     count_dx_player2+=dx_ball;
                                     }
                                 }
                                 else
                                {
                                    dx_ball=-dx_ball;flag_help3_power_headfireball_player1=false;
                                }
                            }
                            else if ( SDL_HasIntersection (& ball_rect , & footplayer2 ))
                            {
                                if(count_dx_player2<200)
                                 {
                                     if(dx_ball>0)
                                     {
                                     x_player2+=dx_ball;
                                     count_dx_player2+=dx_ball;
                                     }
                                 }
                                 else
                                {
                                    dx_ball=-dx_ball;flag_help3_power_headfireball_player1=false;
                                }

                            }



                          }


                        if(flag_power_headfireball_player2 )
                        {


                            if(641-y_ball-60 > W_player2 && y_player2==480 )
                            {

                                first_collision_ball=false;flag_first_collision_by_player=false;

                                counter_power_handling_player2=0;

                                 count_dx_player1=200;

                                flag_help_power_headfireball_player2=true;
                                dx_ball=0;dy_ball=-1.00;

                                dy_player2_help=(y_ball-y_player2+10)/8;

                                dx_player2_help=(x_ball-x_player2)/8;
                            }

                            flag_power_headfireball_player2=false;





                        }

                        if(flag_help_power_headfireball_player2)
                        {
//                            if(y_player2==480)
//                            {
//                                y_player2-=20;
//                            }
                            dx_ball=0;dy_ball=-1.00;

//                                double v=sqrt(((y_player1-y_ball-60)*(y_player1-y_ball-60))+((x_player1-x_ball)*(x_player1-x_ball)));

//                                dy_player1_help=-abs((y_player1-y_ball)/v);
//
//                                dx_player1_help=abs((x_player1-x_ball)/v);

                                x_player2+=dx_player2_help;

                                y_player2+=dy_player2_help;

                                if(counter_play_playing_player2=='0')
                                {
                                    headplayer2.x=x_player2+9;
                                    headplayer2.y=y_player2+3;
                                    headplayer2.w=68;
                                    headplayer2.h=61;
                                }
                                else if(counter_play_playing_player2=='1')
                                {
                                    headplayer2.x=x_player2+8;
                                    headplayer2.y=y_player2+3;
                                    headplayer2.w=70;
                                    headplayer2.h=65;
                                }

                                if ( SDL_HasIntersection (& ball_rect , & headplayer2 ))
                                {
                                    flag_help_power_headfireball_player2=false;
                                    if(H_firstgoal/(x_ball-x_firstgoal)<=1)
                                    {

                                        dx_ball=-75;
                                        dy_ball=17;

                                    }
                                    flag_help2_power_headfireball_player2=true;
                                    flag_help3_power_headfireball_player2=true;
                                    start_clock_help3_headfireball2=clock();
                                }


                        }

                        if(flag_help2_power_headfireball_player2)
                        {
                            if(start_jump_player2<0)
                            {
                                start_jump_player2=-start_jump_player2;
                            }
                            dy_player2_help=25;
                            if(y_player2<480)
                            {
                                y_player2+=dy_player2_help;
                                if(y_player2>480)
                                {
                                    y_player2=480;
                                    flag_help2_power_headfireball_player2=false;

                                }



                            }
                            else
                            {
                                flag_help2_power_headfireball_player2=false;
                            }



                        }

                        if(clock()-start_clock_help3_headfireball2>=1200)
                        {
                            flag_help3_power_headfireball_player2=false;
                        }



                        if(flag_help3_power_headfireball_player2)
                        {
                             if( SDL_HasIntersection (& ball_rect , & body1player1 ))
                             {
                                 if(count_dx_player1>0)
                                 {
                                     if(dx_ball<0)
                                     {
                                     x_player1+=dx_ball;
                                     count_dx_player1+=dx_ball;

                                     }

                                }
                                else
                                {
                                    dx_ball=-dx_ball;
                                    flag_help3_power_headfireball_player2=false;
                                }
                             }
                            else if ( SDL_HasIntersection (& ball_rect , & body2player1 ))
                            {
                                if(count_dx_player1>0)
                                 {
                                     if(dx_ball<0)
                                     {
                                     x_player1+=dx_ball;
                                     count_dx_player1+=dx_ball;
                                     }
                                 }
                                 else
                                {
                                    dx_ball=-dx_ball;flag_help3_power_headfireball_player2=false;
                                }
                            }
                            else if ( SDL_HasIntersection (& ball_rect , & footplayer1 ))
                            {
                                if(count_dx_player1>0)
                                 {
                                     if(dx_ball<0)
                                     {
                                     x_player1+=dx_ball;
                                     count_dx_player1+=dx_ball;
                                     }
                                 }
                                 else
                                {
                                    dx_ball=-dx_ball;flag_help3_power_headfireball_player2=false;
                                }

                            }



                          }




                        if(flag_power_kickfireball_player1)
                        {


                            if(y_ball>y_player1+(2*W_player1/3) && x_ball>x_player1+W_player1 && x_ball<x_player1+W_player1+130)
                            {

                                first_collision_ball=false;flag_first_collision_by_player=false;

                                counter_power_handling_player1=0;

                                count_dx_player2=0;


                                flag_help_power_kickfireball_player1=true;

                                dx_ball=0;dy_ball=-1.00;

                                if(counter_play_playing_player1=='0')
                                {
                                    footplayer1.x=x_player1+7;
                                    footplayer1.y=y_player1 + 168;
                                    footplayer1.w=45;
                                    footplayer1.h=51;

                                    body2player1.x=x_player1+24;
                                    body2player1.y=y_player1 + 100;
                                    body2player1.w=66;
                                    body2player1.h=70;
                                }
                                else if(counter_play_playing_player1=='1')
                                {
                                    footplayer1.x=x_player1+30;
                                    footplayer1.y=y_player1 + 177;
                                    footplayer1.w=30;
                                    footplayer1.h=42;

                                    body2player1.x=x_player1+11;
                                    body2player1.y=y_player1 + 105;
                                    body2player1.w=56;
                                    body2player1.h=72;
                                }

//                                dy_player2_help=(y_ball-y_player2+10)/8;
//
//                                dx_player2_help=(x_ball-x_player2)/8;



                                dy_player1_help=abs((y_ball-footplayer1.y)/6);

                                if( y_player1!=480)
                                    dy_player1_help=-dy_player1_help;
//                                 dy_player1_help=-dy_player1_help-6;

                                if(y_ball<420)
                                {
                                    if(y_ball-15 >body2player1.y && y_ball+45<footplayer1.y+footplayer1.h)
                                    dy_player1_help=0;
                                }
                                else
                                {
                                    if(y_ball+15>body2player1.y && y_ball+15<footplayer1.y+footplayer1.h)
                                    dy_player1_help=0;
                                }



                                dx_player1_help=(x_ball-x_player1)/6;
                            }

                            flag_power_kickfireball_player1=false;





                        }

                        if(flag_help_power_kickfireball_player1)
                        {
                            if(y_player1==480)
                            {
                                y_player1-=20;
                            }
                            dx_ball=0;dy_ball=-1.00;


                                x_player1+=dx_player1_help;

                                y_player1+=dy_player1_help;

                                if(counter_play_playing_player1=='0')
                                {
                                    footplayer1.x=x_player1+7;
                                    footplayer1.y=y_player1 + 168;
                                    footplayer1.w=45;
                                    footplayer1.h=51;

                                    body2player1.x=x_player1+24;
                                    body2player1.y=y_player1 + 100;
                                    body2player1.w=66;
                                    body2player1.h=70;
                                }
                                else if(counter_play_playing_player1=='1')
                                {
                                    footplayer1.x=x_player1+30;
                                    footplayer1.y=y_player1 + 177;
                                    footplayer1.w=30;
                                    footplayer1.h=42;

                                    body2player1.x=x_player1+11;
                                    body2player1.y=y_player1 + 105;
                                    body2player1.w=56;
                                    body2player1.h=72;
                                }

                                if ( SDL_HasIntersection (& ball_rect , & footplayer1 )|| SDL_HasIntersection (& ball_rect , & body2player1 ))
                                {


                                    counter_play_playing_player1='2';

                                    flag_help_power_kickfireball_player1=false;


                                        dx_ball=105;
                                        dy_ball=-2;


                                    flag_help2_power_kickfireball_player1=true;
                                    flag_help3_power_kickfireball_player1=true;
                                    start_clock_help3_kickfireball=clock();
                                }


                        }

                        if(flag_help2_power_kickfireball_player1)
                        {
                            //counter_power_handling_player2=0;

                            dy_player1_help=25;

                            if(start_jump_player1<0)
                            {
                                start_jump_player1=-start_jump_player1;
                            }
                            if(y_player1<480)
                            {

                                y_player1+=dy_player1_help;
                                if(y_player1>480)
                                {
                                    y_player1=480;
                                    flag_help2_power_kickfireball_player1=false;
                                }



                            }
                            else
                            {
                                flag_help2_power_kickfireball_player1=false;
                                counter_play_playing_player1='1';
                            }



                        }

                        if(clock()-start_clock_help3_kickfireball>=1200)
                        {
                            flag_help3_power_kickfireball_player1=false;
                        }



                        if(flag_help3_power_kickfireball_player1)
                        {
                             if( SDL_HasIntersection (& ball_rect , & body1player2 ))
                             {
                                 if(count_dx_player2<200)
                                 {
                                     if(dx_ball>0)
                                     {
                                     x_player2+=dx_ball;
                                     count_dx_player2+=dx_ball;

                                     }

                                }
                                else
                                {
                                    dx_ball=-dx_ball;
                                    flag_help3_power_kickfireball_player1=false;
                                }
                             }
                            else if ( SDL_HasIntersection (& ball_rect , & body2player2 ))
                            {
                                if(count_dx_player2<200)
                                 {
                                     if(dx_ball>0)
                                     {
                                     x_player2+=dx_ball;
                                     count_dx_player2+=dx_ball;
                                     }
                                 }
                                 else
                                {
                                    dx_ball=-dx_ball;flag_help3_power_kickfireball_player1=false;
                                }
                            }
                            else if ( SDL_HasIntersection (& ball_rect , & footplayer2 ))
                            {
                                if(count_dx_player2<200)
                                 {
                                     if(dx_ball>0)
                                     {
                                     x_player2+=dx_ball;
                                     count_dx_player2+=dx_ball;
                                     }
                                 }
                                 else
                                {
                                    dx_ball=-dx_ball;flag_help3_power_kickfireball_player1=false;
                                }

                            }



                          }




                        if(flag_power_kickfireball_player2)
                        {


                            if(y_ball>y_player2+(2*W_player2/3) && x_ball>x_player2-130 && x_ball<x_player2)
                            {

                                first_collision_ball=false;flag_first_collision_by_player=false;

                                counter_power_handling_player2=0;

                                count_dx_player1=200;


                                flag_help_power_kickfireball_player2=true;

                                dx_ball=0;dy_ball=-1.00;

                                if(counter_play_playing_player2=='0')
                                {

                                    footplayer2.x=x_player2+42;
                                    footplayer2.y=y_player2 + 179;
                                    footplayer2.w=31;
                                    footplayer2.h=40;


                                    body2player2.x=x_player2+31;
                                    body2player2.y=y_player2 + 125;
                                    body2player2.w=56;
                                    body2player2.h=54;


                                }
                                else if(counter_play_playing_player2=='1')
                                {

                                    footplayer2.x=x_player2+50;
                                    footplayer2.y=y_player2 + 182;
                                    footplayer2.w=45;
                                    footplayer2.h=38;


                                    body2player2.x=x_player2+2;
                                    body2player2.y=y_player2 + 145;
                                    body2player2.w=75;
                                    body2player2.h=36;


                                }

//                                dy_player2_help=(y_ball-y_player2+10)/8;
//
//                                dx_player2_help=(x_ball-x_player2)/8;



                                dy_player2_help=abs((y_ball-footplayer2.y)/6);

                                if( y_player2!=480)
                                    dy_player2_help=-dy_player2_help;
//                                 dy_player1_help=-dy_player1_help-6;

                                if(y_ball<420)
                                {
                                    if(y_ball-15 >body2player2.y && y_ball+45<footplayer2.y+footplayer2.h)
                                    dy_player2_help=0;
                                }
                                else
                                {
                                    if(y_ball+15>body2player2.y && y_ball+15<footplayer2.y+footplayer2.h)
                                    dy_player2_help=0;
                                }



                                dx_player2_help=(x_ball-x_player2)/6;
                            }

                            flag_power_kickfireball_player2=false;





                        }

                        if(flag_help_power_kickfireball_player2)
                        {
                            if(y_player2==480)
                            {
                                y_player2-=20;
                            }
                            dx_ball=0;dy_ball=-1.00;

//                                double v=sqrt(((y_player1-y_ball-60)*(y_player1-y_ball-60))+((x_player1-x_ball)*(x_player1-x_ball)));

//                                dy_player1_help=-abs((y_player1-y_ball)/v);
//
//                                dx_player1_help=abs((x_player1-x_ball)/v);

                                x_player2+=dx_player2_help;

                                y_player2+=dy_player2_help;

                                if(counter_play_playing_player2=='0')
                                {
                                    footplayer2.x=x_player2+42;
                                    footplayer2.y=y_player2 + 179;
                                    footplayer2.w=31;
                                    footplayer2.h=40;


                                    body2player2.x=x_player2+31;
                                    body2player2.y=y_player2 + 125;
                                    body2player2.w=56;
                                    body2player2.h=54;
                                }
                                else if(counter_play_playing_player2=='1')
                                {
                                    footplayer2.x=x_player2+50;
                                    footplayer2.y=y_player2 + 182;
                                    footplayer2.w=45;
                                    footplayer2.h=38;


                                    body2player2.x=x_player2+2;
                                    body2player2.y=y_player2 + 145;
                                    body2player2.w=75;
                                    body2player2.h=36;
                                }

                                if ( SDL_HasIntersection (& ball_rect , & footplayer2 )|| SDL_HasIntersection (& ball_rect , & body2player2 ))
                                {


                                    counter_play_playing_player2='2';

                                    flag_help_power_kickfireball_player2=false;


                                        dx_ball=-105;
                                        dy_ball=-2;


                                    flag_help2_power_kickfireball_player2=true;
                                    flag_help3_power_kickfireball_player2=true;
                                    start_clock_help3_kickfireball2=clock();
                                }


                        }

                        if(flag_help2_power_kickfireball_player2)
                        {
                            //counter_power_handling_player2=0;

                            dy_player2_help=25;

                            if(start_jump_player2<0)
                            {
                                start_jump_player2=-start_jump_player2;
                            }
                            if(y_player2<480)
                            {

                                y_player2+=dy_player2_help;
                                if(y_player2>480)
                                {
                                    y_player2=480;
                                    flag_help2_power_kickfireball_player2=false;
                                }



                            }
                            else
                            {
                                flag_help2_power_kickfireball_player2=false;
                                counter_play_playing_player2='1';
                            }



                        }

                        if(clock()-start_clock_help3_kickfireball2>=1200)
                        {
                            flag_help3_power_kickfireball_player2=false;
                        }



                        if(flag_help3_power_kickfireball_player2)
                        {
                             if( SDL_HasIntersection (& ball_rect , & body1player1 ))
                             {
                                 if(count_dx_player1>0)
                                 {
                                     if(dx_ball<0)
                                     {
                                     x_player1+=dx_ball;
                                     count_dx_player1+=dx_ball;

                                     }

                                }
                                else
                                {
                                    dx_ball=-dx_ball;
                                    flag_help3_power_kickfireball_player2=false;
                                }
                             }
                            else if ( SDL_HasIntersection (& ball_rect , & body2player1 ))
                            {
                                if(count_dx_player1>0)
                                 {
                                     if(dx_ball<0)
                                     {
                                     x_player1+=dx_ball;
                                     count_dx_player1+=dx_ball;
                                     }
                                 }
                                 else
                                {
                                    dx_ball=-dx_ball;flag_help3_power_kickfireball_player2=false;
                                }
                            }
                            else if ( SDL_HasIntersection (& ball_rect , & footplayer1 ))
                            {
                                if(count_dx_player1>0)
                                 {
                                     if(dx_ball<0)
                                     {
                                     x_player1+=dx_ball;
                                     count_dx_player1+=dx_ball;
                                     }
                                 }
                                 else
                                {
                                    dx_ball=-dx_ball;flag_help3_power_kickfireball_player2=false;
                                }

                            }



                          }




                        if(flag_power_invisibleball_player1)
                        {


                            if(y_ball>y_player1+(2*W_player1/3) && x_ball>x_player1+W_player1 && x_ball<x_player1+W_player1+130)
                            {

                                first_collision_ball=false;flag_first_collision_by_player=false;

                                counter_power_handling_player1=0;

                                flag_help_power_invisibleball_kick_player1=true;

                                dx_ball=0;dy_ball=-1.00;

                                if(counter_play_playing_player1=='0')
                                {
                                    footplayer1.x=x_player1+7;
                                    footplayer1.y=y_player1 + 168;
                                    footplayer1.w=45;
                                    footplayer1.h=51;

                                    body2player1.x=x_player1+24;
                                    body2player1.y=y_player1 + 100;
                                    body2player1.w=66;
                                    body2player1.h=70;
                                }
                                else if(counter_play_playing_player1=='1')
                                {
                                    footplayer1.x=x_player1+30;
                                    footplayer1.y=y_player1 + 177;
                                    footplayer1.w=30;
                                    footplayer1.h=42;

                                    body2player1.x=x_player1+11;
                                    body2player1.y=y_player1 + 105;
                                    body2player1.w=56;
                                    body2player1.h=72;
                                }

//                                dy_player2_help=(y_ball-y_player2+10)/8;
//
//                                dx_player2_help=(x_ball-x_player2)/8;



                                dy_player1_help=abs((y_ball-footplayer1.y)/6);

                                if( y_player1!=480)
                                    dy_player1_help=-dy_player1_help;
//                                 dy_player1_help=-dy_player1_help-6;

                                if(y_ball<420)
                                {
                                    if(y_ball-15 >body2player1.y && y_ball+45<footplayer1.y+footplayer1.h)
                                    dy_player1_help=0;
                                }
                                else
                                {
                                    if(y_ball+15>body2player1.y && y_ball+15<footplayer1.y+footplayer1.h)
                                    dy_player1_help=0;
                                }



                                dx_player1_help=(x_ball-x_player1)/6;
                            }

                            else if(641-y_ball-60 > W_player1 && y_player1==480)
                            {

                                first_collision_ball=false;flag_first_collision_by_player=false;

                                counter_power_handling_player1=0;

                                flag_help_power_invisibleball_head_player1=true;

                                dx_ball=0;dy_ball=-1.00;

                                dy_player1_help=(y_ball-y_player1+10)/6;

                                dx_player1_help=(x_ball-x_player1)/6;
                            }

                            flag_power_invisibleball_player1=false;





                        }

                        if(flag_help_power_invisibleball_kick_player1)
                        {
                            if(y_player1==480)
                            {
                                y_player1-=20;
                            }
                            dx_ball=0;dy_ball=-1.00;



                                x_player1+=dx_player1_help;

                                y_player1+=dy_player1_help;

                                if(counter_play_playing_player1=='0')
                                {
                                    footplayer1.x=x_player1+7;
                                    footplayer1.y=y_player1 + 168;
                                    footplayer1.w=45;
                                    footplayer1.h=51;

                                    body2player1.x=x_player1+24;
                                    body2player1.y=y_player1 + 100;
                                    body2player1.w=66;
                                    body2player1.h=70;
                                }
                                else if(counter_play_playing_player1=='1')
                                {
                                    footplayer1.x=x_player1+30;
                                    footplayer1.y=y_player1 + 177;
                                    footplayer1.w=30;
                                    footplayer1.h=42;

                                    body2player1.x=x_player1+11;
                                    body2player1.y=y_player1 + 105;
                                    body2player1.w=56;
                                    body2player1.h=72;
                                }

                                if ( SDL_HasIntersection (& ball_rect , & footplayer1 )|| SDL_HasIntersection (& ball_rect , & body2player1 ))
                                {

//                                counter_play_playing_player1='2';


//                if( min_W_player1==W_player1)
//
//                {
//                        W_player1+=40;
//                }
                                    counter_play_playing_player1='2';

                                    flag_help_power_invisibleball_kick_player1=false;


                                        dx_ball=75;
                                        dy_ball=-15;

                                        invisibleball_power=true;
                                        start_clock_invisibleball_power=clock();


                                    flag_help2_power_invisibleball_kick_player1=true;
                                    //flag_help3_power_kickfireball_player1=true;
                                    //start_clock_help3_kickfireball=clock();
                                }


                        }

                        if(flag_help2_power_invisibleball_kick_player1)
                        {
                            //counter_power_handling_player2=0;

                            dy_player1_help=25;

                            if(start_jump_player1<0)
                            {
                                start_jump_player1=-start_jump_player1;
                            }
                            if(y_player1<480)
                            {

                                y_player1+=dy_player1_help;
                                if(y_player1>480)
                                {
                                    y_player1=480;
                                    flag_help2_power_invisibleball_kick_player1=false;
                                }



                            }
                            else
                            {
                                flag_help2_power_invisibleball_kick_player1=false;
                                counter_play_playing_player1='1';
                            }



                        }




                        if(flag_help_power_invisibleball_head_player1)
                        {

                            dx_ball=0;dy_ball=-1.00;


                                x_player1+=dx_player1_help;

                                y_player1+=dy_player1_help;

                                if(counter_play_playing_player1=='0')
                                {
                                headplayer1.x=x_player1+30;
                                headplayer1.y=y_player1-5;
                                headplayer1.w=45;
                                headplayer1.h=51;
                                }
                                else if(counter_play_playing_player1=='1')
                                {
                                    headplayer1.x=x_player1+30;
                                    headplayer1.y=y_player1+4;
                                    headplayer1.w=45;
                                    headplayer1.h=42;
                                }

                                if ( SDL_HasIntersection (& ball_rect , & headplayer1 ))
                                {
                                    flag_help_power_invisibleball_head_player1=false;
                                    if(H_secondgoal/(x_ball-x_secondgoal)<=1)
                                    {

                                        dx_ball=75;
                                        dy_ball=17;

                                        invisibleball_power=true;
                                        start_clock_invisibleball_power=clock();

                                    }
                                    flag_help2_power_invisibleball_head_player1=true;

                                }


                        }

                        if(flag_help2_power_invisibleball_head_player1)
                        {
                            //counter_power_handling_player2=0;

                            if(start_jump_player1<0)
                            {
                                start_jump_player1=-start_jump_player1;
                            }

                            dy_player1_help=25;
                            if(y_player1<480)
                            {

                                y_player1+=dy_player1_help;
                                if(y_player1>480)
                                {
                                    y_player1=480;
                                    flag_help2_power_invisibleball_head_player1=false;
                                }



                            }
                            else
                            {
                                flag_help2_power_invisibleball_head_player1=false;
                            }



                        }




                          if(dx_ball>27)
                          {
                              dx_ball-=2;
                          }


                        if(flag_power_invisibleball_player2)
                        {


                            if(y_ball>y_player2+(2*W_player2/3) && x_ball>x_player2-130 && x_ball<x_player2)
                            {

                                first_collision_ball=false;flag_first_collision_by_player=false;

                                counter_power_handling_player2=0;




                                flag_help_power_invisibleball_kick_player2=true;

                                dx_ball=0;dy_ball=-1.00;

                                if(counter_play_playing_player2=='0')
                                {

                                    footplayer2.x=x_player2+42;
                                    footplayer2.y=y_player2 + 179;
                                    footplayer2.w=31;
                                    footplayer2.h=40;


                                    body2player2.x=x_player2+31;
                                    body2player2.y=y_player2 + 125;
                                    body2player2.w=56;
                                    body2player2.h=54;


                                }
                                else if(counter_play_playing_player2=='1')
                                {

                                    footplayer2.x=x_player2+50;
                                    footplayer2.y=y_player2 + 182;
                                    footplayer2.w=45;
                                    footplayer2.h=38;


                                    body2player2.x=x_player2+2;
                                    body2player2.y=y_player2 + 145;
                                    body2player2.w=75;
                                    body2player2.h=36;


                                }


                                dy_player2_help=abs((y_ball-footplayer2.y)/6);

                                if( y_player2!=480)
                                    dy_player2_help=-dy_player2_help;
//                                 dy_player1_help=-dy_player1_help-6;

                                if(y_ball<420)
                                {
                                    if(y_ball-15 >body2player2.y && y_ball+45<footplayer2.y+footplayer2.h)
                                    dy_player2_help=0;
                                }
                                else
                                {
                                    if(y_ball+15>body2player2.y && y_ball+15<footplayer2.y+footplayer2.h)
                                    dy_player2_help=0;
                                }



                                dx_player2_help=(x_ball-x_player2)/6;
                            }

                            else if(641-y_ball-60 > W_player2 && y_player2==480 )
                            {

                                first_collision_ball=false;flag_first_collision_by_player=false;

                                counter_power_handling_player2=0;



                                flag_help_power_invisibleball_head_player2=true;
                                dx_ball=0;dy_ball=-1.00;

                                dy_player2_help=(y_ball-y_player2+10)/8;

                                dx_player2_help=(x_ball-x_player2)/8;
                            }

                            flag_power_invisibleball_player2=false;

                        }

                        if(flag_help_power_invisibleball_kick_player2)
                        {
                            if(y_player2==480)
                            {
                                y_player2-=20;
                            }
                            dx_ball=0;dy_ball=-1.00;



                                x_player2+=dx_player2_help;

                                y_player2+=dy_player2_help;

                                if(counter_play_playing_player2=='0')
                                {
                                    footplayer2.x=x_player2+42;
                                    footplayer2.y=y_player2 + 179;
                                    footplayer2.w=31;
                                    footplayer2.h=40;


                                    body2player2.x=x_player2+31;
                                    body2player2.y=y_player2 + 125;
                                    body2player2.w=56;
                                    body2player2.h=54;
                                }
                                else if(counter_play_playing_player2=='1')
                                {
                                    footplayer2.x=x_player2+50;
                                    footplayer2.y=y_player2 + 182;
                                    footplayer2.w=45;
                                    footplayer2.h=38;


                                    body2player2.x=x_player2+2;
                                    body2player2.y=y_player2 + 145;
                                    body2player2.w=75;
                                    body2player2.h=36;
                                }

                                if ( SDL_HasIntersection (& ball_rect , & footplayer2 )|| SDL_HasIntersection (& ball_rect , & body2player2 ))
                                {

//                }
                                    counter_play_playing_player2='2';

                                    flag_help_power_invisibleball_kick_player2=false;


                                        dx_ball=-105;
                                        dy_ball=-2;

                                        invisibleball_power=true;
                                        start_clock_invisibleball_power=clock();


                                    flag_help2_power_invisibleball_kick_player2=true;
                                    //flag_help3_power_kickfireball_player2=true;
                                    //start_clock_help3_kickfireball2=clock();
                                }


                        }

                        if(flag_help2_power_invisibleball_kick_player2)
                        {
                            //counter_power_handling_player2=0;

                            dy_player2_help=25;

                            if(start_jump_player2<0)
                            {
                                start_jump_player2=-start_jump_player2;
                            }
                            if(y_player2<480)
                            {

                                y_player2+=dy_player2_help;
                                if(y_player2>480)
                                {
                                    y_player2=480;
                                    flag_help2_power_invisibleball_kick_player2=false;
                                }



                            }
                            else
                            {
                                flag_help2_power_invisibleball_kick_player2=false;
                                counter_play_playing_player2='1';
                            }



                        }







                        if(flag_help_power_invisibleball_head_player2)
                        {

                            dx_ball=0;dy_ball=-1.00;

//

                                x_player2+=dx_player2_help;

                                y_player2+=dy_player2_help;

                                if(counter_play_playing_player2=='0')
                                {
                                    headplayer2.x=x_player2+9;
                                    headplayer2.y=y_player2+3;
                                    headplayer2.w=68;
                                    headplayer2.h=61;
                                }
                                else if(counter_play_playing_player2=='1')
                                {
                                    headplayer2.x=x_player2+8;
                                    headplayer2.y=y_player2+3;
                                    headplayer2.w=70;
                                    headplayer2.h=65;
                                }

                                if ( SDL_HasIntersection (& ball_rect , & headplayer2 ))
                                {
                                    flag_help_power_invisibleball_head_player2=false;
                                    if(H_firstgoal/(x_ball-x_firstgoal)<=1)
                                    {

                                        dx_ball=-75;
                                        dy_ball=17;

                                        invisibleball_power=true;
                                        start_clock_invisibleball_power=clock();

                                    }
                                    flag_help2_power_invisibleball_head_player2=true;
                                    //flag_help3_power_headfireball_player2=true;
                                    //start_clock_help3_headfireball2=clock();
                                }


                        }

                        if(flag_help2_power_invisibleball_head_player2)
                        {
                            if(start_jump_player2<0)
                            {
                                start_jump_player2=-start_jump_player2;
                            }
                            dy_player2_help=25;
                            if(y_player2<480)
                            {
                                y_player2+=dy_player2_help;
                                if(y_player2>480)
                                {
                                    y_player2=480;
                                    flag_help2_power_invisibleball_head_player2=false;

                                }



                            }
                            else
                            {
                                flag_help2_power_invisibleball_head_player2=false;
                            }



                        }


                          if(invisibleball_power)
                          {
                              if(clock()-start_clock_invisibleball_power>=3000)
                              {
                                  invisibleball_power=false;
                              }
                          }




                          if(dx_ball<-27)
                          {
                              dx_ball+=2;
                          }



        if(start_clocking_full)
            {
                start_clocking_full_time_game=clock();

                start_clocking_full=false;


            }




        if(start_clocking_kick_player1)
        {
            if( (clock()- start_kick_player1)/1000.0>=0.35)

            {


//            if(e->type==SDL_KEYDOWN)
//            if ( keyboard_state_array[SDL_SCANCODE_D]  )
                if( min_W_player1!=W_player1)
                {
                       W_player1=min_W_player1;counter_play_playing_player1='0';
                }



                 start_clocking_kick_player1=false;
            }
        }


        if(start_clocking_kick_player2)
        {
            if( (clock()- start_kick_player2)/1000.0>=0.35)

            {




                if( min_W_player2!=W_player2)
                {
                       W_player2=min_W_player2;counter_play_playing_player2='0';
                }


                 start_clocking_kick_player2=false;
            }
        }

        if(start_clocking_jump_player1)
        {

            if(y_player1>320 && control_jump_player1)
            {
                if(start_jump_player1>0)
                    start_jump_player1=-start_jump_player1;
                 y_player1+= start_jump_player1;

                 if(y_player1==320)
                 {
                       control_jump_player1=false;

                       start_jump_player1=-start_jump_player1;

                        if(counter_play_playing_player1=='0')
                        {
                            counter_play_playing_player1='1';
                        }
                        else
                        {
                             counter_play_playing_player1='0';
                        }
                 }
            }

            else
            {
                y_player1+= start_jump_player1;
            }


             if(y_player1>480)
            {
                    y_player1=480;
            }

            if(y_player1==480)
            {
                start_clocking_jump_player1=false;

                control_jump_player1=true;


            }




                if( min_W_player1!=W_player1)
                {
                      W_player1=min_W_player1;
                }

        }




        if(start_clocking_jump_player2)
        {
            if(y_player2>320 && control_jump_player2)
            {
                if(start_jump_player2>0)
                    start_jump_player2=-start_jump_player2;
                 y_player2+= start_jump_player2;


                 if(y_player2==320)
                 {
                       control_jump_player2=false;

                       start_jump_player2=-start_jump_player2;

                        if(counter_play_playing_player2=='0')
                        {
                            counter_play_playing_player2='1';
                        }
                        else
                        {
                             counter_play_playing_player2='0';
                        }
                 }
            }

            else
            {
                y_player2+= start_jump_player2;
            }

            if(y_player2>480)
            {
                    y_player2=480;
            }

            if(y_player2==480)
            {
                start_clocking_jump_player2=false;

                control_jump_player2=true;


            }



                if( min_W_player2!=W_player2)
                {
                      W_player2=min_W_player2;
                }

        }

}

redraw=true;



                        if(save_result)
                        {
                            k=0;num=0;
                           ever_played_player1=false;
                           ever_played_player2=false;




                                ifstream names("names.txt");
                                while (names.good())
                                {
                                 names>>asami[k];

                                       if( name_player1_help==asami[k])
                                        {
                                             directer_ever_played_player1=k;

                                             ever_played_player1=true;

                                        }

                                        if( name_player2_help==asami[k])
                                        {
                                             directer_ever_played_player2=k;

                                             ever_played_player2=true;

                                        }


                                 k++;
                                 num++;

                                }
                                names.close();



                                if(ever_played_player1)
                                {

                                        if(counter_goal_plyer1>counter_goal_plyer2)
                                        {
                                            int tedad_bord[10000];
                                            ifstream nbord("num_of_wins.txt");
                                            if (nbord.good())
                                            {
                                                   for (int i=0;i<num;i++)
                                                   {
                                                       nbord>>tedad_bord[i];

                                                       if(i==directer_ever_played_player1)
                                                       {
                                                          tedad_bord[i]++;
                                                       }
                                                   }

                                                   nbord.close();
                                            }

                                            ofstream out_nbord("num_of_wins.txt");

                                            for(int i=0;i<num;i++)
                                            {
                                                out_nbord<<tedad_bord[i]<<endl;
                                            }

                                            out_nbord.close();

                                        }

                                        if(counter_goal_plyer1!=0)
                                        {
                                            ifstream ngoalzade("num_of_goal_scores.txt");
                                            int tedad_goal_zade[10000];
                                            if (ngoalzade.good())
                                            {
                                                for (int i=0;i<num;i++)
                                                {
                                                    ngoalzade>>tedad_goal_zade[i];

                                                    if(i==directer_ever_played_player1)
                                                    {
                                                        tedad_goal_zade[i]+=counter_goal_plyer1;
                                                    }
                                                }
                                                ngoalzade.close();
                                            }
                                            ofstream out_nbord("num_of_goal_scores.txt");

                                            for(int i=0;i<num;i++)
                                            {
                                                out_nbord<<tedad_goal_zade[i]<<endl;
                                            }

                                            out_nbord.close();

                                        }

                                        if(counter_goal_plyer2!=0)
                                        {
                                            ifstream ngoalkhorde("num_of_goal_concedes.txt");
                                            int tedad_goal_khorde[10000];
                                            if (ngoalkhorde.good())
                                            {
                                                for (int i=0;i<num;i++)
                                                {
                                                    ngoalkhorde>>tedad_goal_khorde[i];

                                                    if(i==directer_ever_played_player1)
                                                    {
                                                        tedad_goal_khorde[i]+=counter_goal_plyer2;
                                                    }
                                                }
                                                ngoalkhorde.close();
                                            }

                                            ofstream out_nbord("num_of_goal_concedes.txt");

                                            for(int i=0;i<num;i++)
                                            {
                                                out_nbord<<tedad_goal_khorde[i]<<endl;
                                            }

                                            out_nbord.close();
                                        }

                                        if(counter_goal_plyer1<counter_goal_plyer2)
                                        {
                                            int tedad_bakht[10000];
                                            ifstream nbakht("num_of_defeats.txt");
                                            if (nbakht.good())
                                            {
                                                   for (int i=0;i<num;i++)
                                                   {
                                                       nbakht>>tedad_bakht[i];

                                                       if(i==directer_ever_played_player1)
                                                        {
                                                            tedad_bakht[i]++;
                                                        }
                                                   }
                                                   nbakht.close();
                                            }
                                            ofstream out_nbord("num_of_defeats.txt");

                                            for(int i=0;i<num;i++)
                                            {
                                                out_nbord<<tedad_bakht[i]<<endl;
                                            }

                                            out_nbord.close();
                                        }

                                        if(counter_goal_plyer1==counter_goal_plyer2)
                                        {
                                            int tedad_mosavi[10000];
                                            ifstream nmosavi("num_of_drawns.txt");
                                            if (nmosavi.good())
                                            {
                                                   for (int i=0;i<num;i++)
                                                   {
                                                       nmosavi>>tedad_mosavi[i];

                                                       if(i==directer_ever_played_player1)
                                                        {
                                                            tedad_mosavi[i]++;
                                                        }
                                                   }
                                                   nmosavi.close();
                                            }

                                            ofstream out_nbord("num_of_drawns.txt");

                                            for(int i=0;i<num;i++)
                                            {
                                                out_nbord<<tedad_mosavi[i]<<endl;
                                            }

                                            out_nbord.close();

                                            }

                                            int tedad_bazi[10000];
                                            ifstream nbazi("num_of_performances.txt");
                                            if (nbazi.good())
                                            {
                                                   for (int i=0;i<num;i++)
                                                   {
                                                       nbazi>>tedad_bazi[i];

                                                       if(i==directer_ever_played_player1)
                                                        {
                                                            tedad_bazi[i]++;
                                                        }
                                                   }
                                                   nbazi.close();

                                                ofstream out_nbord("num_of_performances.txt");

                                                for(int i=0;i<num;i++)
                                                {
                                                    out_nbord<<tedad_bazi[i]<<endl;
                                                }

                                                out_nbord.close();
                                            }

                                            if(counter_goal_plyer1!=counter_goal_plyer2)
                                            {
                                                int tedad_tafazol_goal[10000];
                                                ifstream ntafazol("num_of_goal_difference.txt");
                                                if (ntafazol.good())
                                                {
                                                       for (int i=0;i<num;i++)
                                                       {
                                                           ntafazol>>tedad_tafazol_goal[i];

                                                           if(i==directer_ever_played_player1)
                                                            {
                                                                tedad_tafazol_goal[i]+=(counter_goal_plyer1-counter_goal_plyer2);
                                                            }
                                                       }
                                                       ntafazol.close();
                                                }

                                                ofstream out_nbord("num_of_goal_difference.txt");

                                                for(int i=0;i<num;i++)
                                                {
                                                    out_nbord<<tedad_tafazol_goal[i]<<endl;
                                                }

                                                out_nbord.close();

                                            }

                                            if(counter_goal_plyer1>=counter_goal_plyer2)
                                            {
                                                int emtiazha[10000];
                                                ifstream emtiaz("num_of_points.txt");
                                                if (emtiaz.good())
                                                {
                                                       for (int i=0;i<num;i++)
                                                       {
                                                           emtiaz>>emtiazha[i];

                                                           if(i==directer_ever_played_player1)
                                                            {
                                                                if(counter_goal_plyer1==counter_goal_plyer2)
                                                                emtiazha[i]++;
                                                                else
                                                                emtiazha[i]+=3;
                                                            }
                                                       }
                                                       emtiaz.close();
                                                }

                                                ofstream out_nbord("num_of_points.txt");

                                                for(int i=0;i<num;i++)
                                                {
                                                    out_nbord<<emtiazha[i]<<endl;
                                                }

                                                out_nbord.close();


                                            }

                                }
                                else
                                {

                                            ofstream out_nasami("names.txt" ,  ios::app );
                                            out_nasami<<name_player1_help<<endl;
                                            out_nasami.close();


                                            ofstream out_nbord("num_of_wins.txt",  ios::app);
                                            if(counter_goal_plyer1>counter_goal_plyer2)
                                            {
                                                int nwin=1;
                                                out_nbord<<nwin<<endl;


                                            }
                                            else if(counter_goal_plyer1<counter_goal_plyer2)
                                            {
                                                 int nwin=0;
                                                out_nbord<<nwin<<endl;

                                            }
                                            else if(counter_goal_plyer1==counter_goal_plyer2)
                                            {
                                                 int nwin=0;
                                                out_nbord<<nwin<<endl;

                                            }

                                            out_nbord.close();

                                            ofstream out_ngoalzade("num_of_goal_scores.txt",  ios::app);
                                            out_ngoalzade<<counter_goal_plyer1<<endl;
                                            out_ngoalzade.close();


                                            ofstream out_ngoalkhorde("num_of_goal_concedes.txt",  ios::app);
                                            out_ngoalkhorde<<counter_goal_plyer2<<endl;
                                            out_ngoalkhorde.close();




                                            ofstream out_nbakht("num_of_defeats.txt",  ios::app);

                                            if(counter_goal_plyer1>counter_goal_plyer2)
                                            {
                                                int ndefeat=0;
                                                out_nbakht<<ndefeat<<endl;

                                            }
                                            else if(counter_goal_plyer1<counter_goal_plyer2)
                                            {
                                                int ndefeat=1;
                                                out_nbakht<<ndefeat<<endl;

                                            }
                                            else if(counter_goal_plyer1==counter_goal_plyer2)
                                            {
                                               int ndefeat=0;
                                                out_nbakht<<ndefeat<<endl;

                                            }

                                            out_nbakht.close();




                                            ofstream out_nmosavi("num_of_drawns.txt",  ios::app);
                                            if(counter_goal_plyer1>counter_goal_plyer2)
                                            {
                                               int ndrawn=0;
                                               out_nmosavi<<ndrawn<<endl;

                                            }
                                            else if(counter_goal_plyer1<counter_goal_plyer2)
                                            {
                                                int ndrawn=0;
                                               out_nmosavi<<ndrawn<<endl;

                                            }
                                            else if(counter_goal_plyer1==counter_goal_plyer2)
                                            {
                                                int ndrawn=1;
                                               out_nmosavi<<ndrawn<<endl;

                                            }

                                            out_nmosavi.close();



                                                ofstream out_nbazi("num_of_performances.txt",  ios::app);
                                                 int nperfprmance=1;
                                                out_nbazi<<nperfprmance<<endl;cout<<nperfprmance<<endl;
                                                out_nbazi.close();



                                                ofstream out_ntafazol("num_of_goal_difference.txt",  ios::app);

                                                int ndiffernce=counter_goal_plyer1-counter_goal_plyer2;
                                                out_ntafazol<<ndiffernce<<endl;

                                                out_ntafazol.close();





                                                ofstream out_emtiaz("num_of_points.txt",  ios::app);
                                                if(counter_goal_plyer1>counter_goal_plyer2)
                                                {
                                                     int pointss=3;out_emtiaz<<pointss<<endl;
                                                }

                                                else if(counter_goal_plyer1==counter_goal_plyer2)
                                                {
                                                     int pointss=1;out_emtiaz<<pointss<<endl;
                                                }

                                                else
                                                {
                                                    int pointss=0;out_emtiaz<<pointss<<endl;
                                                }



                                                out_emtiaz.close();





                                                num++;



                                }




                                if(ever_played_player2)
                                {

                                        if(counter_goal_plyer2>counter_goal_plyer1)
                                        {
                                            int tedad_bord[10000];
                                            ifstream nbord("num_of_wins.txt");
                                            if (nbord.good())
                                            {
                                                   for (int i=0;i<num;i++)
                                                   {
                                                       nbord>>tedad_bord[i];

                                                       if(i==directer_ever_played_player2)
                                                       {
                                                          tedad_bord[i]++;
                                                       }
                                                   }

                                                   nbord.close();
                                            }

                                            ofstream out_nbord("num_of_wins.txt");

                                            for(int i=0;i<num;i++)
                                            {
                                                out_nbord<<tedad_bord[i]<<endl;
                                            }

                                            out_nbord.close();

                                        }

                                        if(counter_goal_plyer2!=0)
                                        {
                                            ifstream ngoalzade("num_of_goal_scores.txt");
                                            int tedad_goal_zade[10000];
                                            if (ngoalzade.good())
                                            {
                                                for (int i=0;i<num;i++)
                                                {
                                                    ngoalzade>>tedad_goal_zade[i];

                                                    if(i==directer_ever_played_player2)
                                                    {
                                                        tedad_goal_zade[i]+=counter_goal_plyer2;
                                                    }
                                                }
                                                ngoalzade.close();
                                            }
                                            ofstream out_nbord("num_of_goal_scores.txt");

                                            for(int i=0;i<num;i++)
                                            {
                                                out_nbord<<tedad_goal_zade[i]<<endl;
                                            }

                                            out_nbord.close();

                                        }

                                        if(counter_goal_plyer1!=0)
                                        {
                                            ifstream ngoalkhorde("num_of_goal_concedes.txt");
                                            int tedad_goal_khorde[10000];
                                            if (ngoalkhorde.good())
                                            {
                                                for (int i=0;i<num;i++)
                                                {
                                                    ngoalkhorde>>tedad_goal_khorde[i];

                                                    if(i==directer_ever_played_player2)
                                                    {
                                                        tedad_goal_khorde[i]+=counter_goal_plyer1;
                                                    }
                                                }
                                                ngoalkhorde.close();
                                            }

                                            ofstream out_nbord("num_of_goal_concedes.txt");

                                            for(int i=0;i<num;i++)
                                            {
                                                out_nbord<<tedad_goal_khorde[i]<<endl;
                                            }

                                            out_nbord.close();
                                        }

                                        if(counter_goal_plyer2<counter_goal_plyer1)
                                        {
                                            int tedad_bakht[10000];
                                            ifstream nbakht("num_of_defeats.txt");
                                            if (nbakht.good())
                                            {
                                                   for (int i=0;i<num;i++)
                                                   {
                                                       nbakht>>tedad_bakht[i];

                                                       if(i==directer_ever_played_player2)
                                                        {
                                                            tedad_bakht[i]++;
                                                        }
                                                   }
                                                   nbakht.close();
                                            }
                                            ofstream out_nbord("num_of_defeats.txt");

                                            for(int i=0;i<num;i++)
                                            {
                                                out_nbord<<tedad_bakht[i]<<endl;
                                            }

                                            out_nbord.close();
                                        }

                                        if(counter_goal_plyer1==counter_goal_plyer2)
                                        {
                                            int tedad_mosavi[10000];
                                            ifstream nmosavi("num_of_drawns.txt");
                                            if (nmosavi.good())
                                            {
                                                   for (int i=0;i<num;i++)
                                                   {
                                                       nmosavi>>tedad_mosavi[i];

                                                       if(i==directer_ever_played_player2)
                                                        {
                                                            tedad_mosavi[i]++;
                                                        }
                                                   }
                                                   nmosavi.close();
                                            }

                                            ofstream out_nbord("num_of_drawns.txt");

                                            for(int i=0;i<num;i++)
                                            {
                                                out_nbord<<tedad_mosavi[i]<<endl;
                                            }

                                            out_nbord.close();

                                            }

                                            int tedad_bazi[10000];
                                            ifstream nbazi("num_of_performances.txt");
                                            if (nbazi.good())
                                            {
                                                   for (int i=0;i<num;i++)
                                                   {
                                                       nbazi>>tedad_bazi[i];

                                                       if(i==directer_ever_played_player2)
                                                        {
                                                            tedad_bazi[i]++;
                                                        }
                                                   }
                                                   nbazi.close();

                                                ofstream out_nbord("num_of_performances.txt");

                                                for(int i=0;i<num;i++)
                                                {
                                                    out_nbord<<tedad_bazi[i]<<endl;
                                                }

                                                out_nbord.close();
                                            }

                                            if(counter_goal_plyer1!=counter_goal_plyer2)
                                            {
                                                int tedad_tafazol_goal[10000];
                                                ifstream ntafazol("num_of_goal_difference.txt");
                                                if (ntafazol.good())
                                                {
                                                       for (int i=0;i<num;i++)
                                                       {
                                                           ntafazol>>tedad_tafazol_goal[i];

                                                           if(i==directer_ever_played_player2)
                                                            {
                                                                tedad_tafazol_goal[i]+=(counter_goal_plyer2-counter_goal_plyer1);
                                                            }
                                                       }
                                                       ntafazol.close();
                                                }

                                                ofstream out_nbord("num_of_goal_difference.txt");

                                                for(int i=0;i<num;i++)
                                                {
                                                    out_nbord<<tedad_tafazol_goal[i]<<endl;
                                                }

                                                out_nbord.close();

                                            }

                                            if(counter_goal_plyer2>=counter_goal_plyer1)
                                            {
                                                int emtiazha[10000];
                                                ifstream emtiaz("num_of_points.txt");
                                                if (emtiaz.good())
                                                {
                                                       for (int i=0;i<num;i++)
                                                       {
                                                           emtiaz>>emtiazha[i];

                                                           if(i==directer_ever_played_player2)
                                                            {
                                                                if(counter_goal_plyer1==counter_goal_plyer2)
                                                                emtiazha[i]++;
                                                                else
                                                                emtiazha[i]+=3;
                                                            }
                                                       }
                                                       emtiaz.close();
                                                }

                                                ofstream out_nbord("num_of_points.txt");

                                                for(int i=0;i<num;i++)
                                                {
                                                    out_nbord<<emtiazha[i]<<endl;
                                                }

                                                out_nbord.close();


                                            }

                                }
                                else
                                {

                                            ofstream out_nasami("names.txt",  ios::app);
                                            out_nasami<<name_player2_help<<endl;
                                            out_nasami.close();

                                            ofstream out_nbord("num_of_wins.txt",  ios::app);

                                            if(counter_goal_plyer2>counter_goal_plyer1)
                                            {
                                                int nwin2=1;out_nbord<<nwin2<<endl;

                                            }
                                            else if(counter_goal_plyer2<counter_goal_plyer1)
                                            {
                                                int nwin2=0;out_nbord<<nwin2<<endl;
                                            }
                                            else if(counter_goal_plyer1==counter_goal_plyer2)
                                            {
                                                int nwin2=0;out_nbord<<nwin2<<endl;

                                            }
                                            out_nbord.close();





                                            ofstream out_ngoalzade("num_of_goal_scores.txt",  ios::app);
                                            out_ngoalzade<<counter_goal_plyer2<<endl;
                                            out_ngoalzade.close();



                                            ofstream out_ngoalkhorde("num_of_goal_concedes.txt",  ios::app);
                                            out_ngoalkhorde<<counter_goal_plyer1<<endl;
                                            out_ngoalkhorde.close();



                                            ofstream out_nbakht("num_of_defeats.txt",  ios::app);
                                            if(counter_goal_plyer2>counter_goal_plyer1)
                                            {
                                                int ndefeat2=0;out_nbakht<<ndefeat2<<endl;

                                            }
                                            else if(counter_goal_plyer2<counter_goal_plyer1)
                                            {
                                                int ndefeat2=1;out_nbakht<<ndefeat2<<endl;

                                            }
                                            else if(counter_goal_plyer1==counter_goal_plyer2)
                                            {
                                                int ndefeat2=0;out_nbakht<<ndefeat2<<endl;

                                            }


                                            out_nbakht.close();




                                            ofstream out_nmosavi("num_of_drawns.txt",  ios::app);
                                            if(counter_goal_plyer2>counter_goal_plyer1)
                                            {
                                                int ndrwan2=0; out_nmosavi<<ndrwan2<<endl;

                                            }
                                            else if(counter_goal_plyer2<counter_goal_plyer1)
                                            {
                                                int ndrwan2=0; out_nmosavi<<ndrwan2<<endl;

                                            }
                                            else if(counter_goal_plyer1==counter_goal_plyer2)
                                            {
                                                int ndrwan2=1; out_nmosavi<<ndrwan2<<endl;

                                            }


                                            out_nmosavi.close();



                                                ofstream out_nbazi("num_of_performances.txt",  ios::app);
                                                 int nperformance2=1;
                                                out_nbazi<<nperformance2<<endl;

                                                out_nbazi.close();



                                                ofstream out_ntafazol("num_of_goal_difference.txt",  ios::app);
                                                int ndiffernce2=counter_goal_plyer2-counter_goal_plyer1;
                                                out_ntafazol<<ndiffernce2<<endl;
                                                out_ntafazol.close();






                                                ofstream out_emtiaz("num_of_points.txt",  ios::app);
                                                if(counter_goal_plyer2>counter_goal_plyer1)
                                                {
                                                   int emtiaz2=3;  out_emtiaz<<emtiaz2<<endl;
                                                }

                                                else if(counter_goal_plyer1==counter_goal_plyer2)
                                                {
                                                   int emtiaz2=1;  out_emtiaz<<emtiaz2<<endl;
                                                }

                                                else
                                                {
                                                    int emtiaz2=0; out_emtiaz<<emtiaz2<<endl;
                                                }



                                                out_emtiaz.close();
                                }







                                save_result=false;

                        }

    redraw=true;

while(flag9)
{




    SDL_PollEvent(e);


                        if(redraw)
                        {
                                texture(m_renderer,0,0,"result.png",1500,750);

                                boxRGBA(m_renderer,0,180,1500,330,255,0,255,255);


                                string win_player;
                                    if(counter_goal_plyer1==counter_goal_plyer2)
                                    {

                                        win_player=" Tie ! Players divided points";
                                    }
                                    if(counter_goal_plyer1>counter_goal_plyer2)
                                    {
                                        string win0= " won the match ! did you enjoy it ?";
                                        win_player=name_player1_help+win0;
                                    }
                                    if(counter_goal_plyer1<counter_goal_plyer2)
                                    {
                                        string win0= " won the match ! did you enjoy it ?";
                                        win_player=name_player2_help+win0;
                                    }


                                textColor(m_renderer,20,200, win_player.c_str(),font_address_03 ,font_size_enter_name+20,text_color_setting_loading2,angle,NONE);


                                texture(m_renderer,0,0,"scoreboard.png",1500,180);

                                textColor(m_renderer,1220,10, name_player2_help.c_str(),font_address_02 ,font_size_enter_name-10,text_color_setting_loading,angle,NONE);
                                textColor(m_renderer,20,10, name_player1_help.c_str(),font_address_02 ,font_size_enter_name-10,text_color_setting_loading,angle,NONE);



                                string numGoal_player1="1";
                                numGoal_player1.push_back(counter_numGoal_player1);
                                numGoal_player1+=".png";



                                string numGoal_player2="2";
                                numGoal_player2.push_back(counter_numGoal_player2);
                                numGoal_player2+=".png";


//
//                                boxRGBA(m_renderer,690,110,810,150,255,255,0,255);
//
//
                                texture(m_renderer,530,15,numGoal_player1,100,150);

                                texture(m_renderer,870,15,numGoal_player2,100,150);


                                texture(m_renderer,700,350,"restart.png",300,120);
                                texture(m_renderer,850,485,"menu.png",300,120);
                                texture(m_renderer,1000,620,"exit.png",300,120);


                                redraw=false;

                                SDL_RenderPresent( m_renderer );
                        }

                        counter_power_handling_player2=0;counter_power_handling_player1=0;


                        if(e->type==SDL_MOUSEBUTTONDOWN)
                         {
                             x_mouse=e->motion.x;
                             y_mouse=e->motion.y;


                             for(int i=0;i<8;i++)
                                {
                                    aacircleRGBA(m_renderer,x_mouse,y_mouse,30*i/5,255,0,0,255);
                                }

                                SDL_RenderPresent(m_renderer);

                                string chunk_sound = "resources\\mouse_button.ogg"; //Chunk sound Address
                                Mix_Chunk *collision = Mix_LoadWAV(chunk_sound.c_str()); //Load sound for wall collision
                                Mix_PlayChannel(-1,collision,0);




                                if(x_mouse >1000 && x_mouse < 1300 && y_mouse > 620 && y_mouse < 740 )
                               {

                                 flag9=false;

                                 //flag_control_whole_game=false;

                                 flag_exit=true;

                                 sound = "resources\\exit1.mp3";
                    GameSound = Mix_LoadMUS(sound.c_str());
                    Mix_PlayMusic(GameSound,-1);

                               }


                               else if(x_mouse >700 && x_mouse < 1000 && y_mouse > 350 && y_mouse < 470 )
                               {

                                    flag9=false;

                                    flag_setting_compile_game=false;

                                    flag8=true;




                                    string sound = "resources\\0.mp3"; //Background sound Address

                                    Mix_Music *GameSound = Mix_LoadMUS(sound.c_str()); //Load background sound

                                    Mix_PlayMusic(GameSound,-1); //Play the sound.  -1 means play it till the end



                            flag_visible_ball=true;
                            x_ball=x0_ball;
                            y_ball=y0_ball;
                            dx_ball=dx0_ball;
                            dy_ball=dy0_ball;
                            first_collision_ball=true;
                            y_ball_goal=500;
                            x_ball_goal=750;
                            dx_ball_goal=0;
                            dy_ball_goal=0;
                            x_player1=200;
                            x_player2=1200;
                            flag_help2_power_headfireball_player1=false;
                            flag_help3_power_headfireball_player1=false;
                            count_dx_player2=0;
                            flag_help4_power_headfireball_player1=false;
                            flag_help2_power_headfireball_player2=false;
                            flag_help3_power_headfireball_player2=false;
                            count_dx_player1=200;
                            flag_help4_power_headfireball_player2=false;

                            flag_help2_power_kickfireball_player1=false;
                            flag_help3_power_kickfireball_player1=false;
                            count_dx_player2=0;
                            flag_help4_power_kickfireball_player1=false;

                            flag_help2_power_kickfireball_player2=false;
                            flag_help3_power_kickfireball_player2=false;
                            count_dx_player1=200;
                            flag_help4_power_kickfireball_player2=false;


                            y_player1=480;
                            y_player2=480;


                            counter_play_playing_player1='0';
                            counter_play_playing_player2='0';



                            flag_power_invisibleball_player1=false,flag_help_power_invisibleball_kick_player1=false,flag_help2_power_invisibleball_kick_player1=false;
                            flag_help_power_invisibleball_head_player1=false,flag_help2_power_invisibleball_head_player1=false,flag_help3_power_invisibleball_head_player1=false,flag_help4_power_invisibleball_head_player1=false;


                            flag_power_invisibleball_player2=false,flag_help_power_invisibleball_kick_player2=false,flag_help2_power_invisibleball_kick_player2=false;
                            flag_help_power_invisibleball_head_player2=false,flag_help2_power_invisibleball_head_player2=false,flag_help3_power_invisibleball_head_player2=false,flag_help4_power_invisibleball_head_player2=false;

                            flag_power_punch_player1=false,flag_help_power_punch_player1=false,flag_help2_power_punch_player1=false;
                            start_clock_help_punch=0,start_clock_help2_punch=0;

                            w_punch=0;


                            flag_power_punch_player2=false,flag_help_power_punch_player2=false,flag_help2_power_punch_player2=false;
                            start_clock_help_punch2=0,start_clock_help2_punch2=0;


                            w_punch=0;

                            texture(m_renderer,385,0,"black.png",730,180);
                            texture(m_renderer,490,10,"yellow.png",182,160);
                            texture(m_renderer,828,10,"yellow.png",184,160);

                            draw_score_board=true;

                            counter_numGoal_player1='0';
                            counter_goal_plyer1=0;
                            counter_numGoal_player2='0';
                            counter_goal_plyer2=0;


                            setTime=setTime0;


                               }



                               else if(x_mouse >850 && x_mouse < 1150 && y_mouse > 485 && y_mouse < 605 )
                               {

                                    flag9=false;

                                    flag_setting_compile_game=false;

                                    flag1=true;redraw=true;




                                    string sound = "resources\\0.mp3"; //Background sound Address

                                    Mix_Music *GameSound = Mix_LoadMUS(sound.c_str()); //Load background sound

                                    Mix_PlayMusic(GameSound,-1); //Play the sound.  -1 means play it till the end



                                    flag_visible_ball=true;
                            x_ball=x0_ball;
                            y_ball=y0_ball;
                            dx_ball=dx0_ball;
                            dy_ball=dy0_ball;
                            first_collision_ball=true;
                            y_ball_goal=500;
                            x_ball_goal=750;
                            dx_ball_goal=0;
                            dy_ball_goal=0;
                            x_player1=200;
                            x_player2=1200;
                            flag_help2_power_headfireball_player1=false;
                            flag_help3_power_headfireball_player1=false;
                            count_dx_player2=0;
                            flag_help4_power_headfireball_player1=false;
                            flag_help2_power_headfireball_player2=false;
                            flag_help3_power_headfireball_player2=false;
                            count_dx_player1=200;
                            flag_help4_power_headfireball_player2=false;

                            flag_help2_power_kickfireball_player1=false;
                            flag_help3_power_kickfireball_player1=false;
                            count_dx_player2=0;
                            flag_help4_power_kickfireball_player1=false;

                            flag_help2_power_kickfireball_player2=false;
                            flag_help3_power_kickfireball_player2=false;
                            count_dx_player1=200;
                            flag_help4_power_kickfireball_player2=false;


                            y_player1=480;
                            y_player2=480;


                            counter_play_playing_player1='0';
                            counter_play_playing_player2='0';



                            flag_power_invisibleball_player1=false,flag_help_power_invisibleball_kick_player1=false,flag_help2_power_invisibleball_kick_player1=false;
                            flag_help_power_invisibleball_head_player1=false,flag_help2_power_invisibleball_head_player1=false,flag_help3_power_invisibleball_head_player1=false,flag_help4_power_invisibleball_head_player1=false;


                            flag_power_invisibleball_player2=false,flag_help_power_invisibleball_kick_player2=false,flag_help2_power_invisibleball_kick_player2=false;
                            flag_help_power_invisibleball_head_player2=false,flag_help2_power_invisibleball_head_player2=false,flag_help3_power_invisibleball_head_player2=false,flag_help4_power_invisibleball_head_player2=false;

                            flag_power_punch_player1=false,flag_help_power_punch_player1=false,flag_help2_power_punch_player1=false;
                            start_clock_help_punch=0,start_clock_help2_punch=0;

                            w_punch=0;


                            flag_power_punch_player2=false,flag_help_power_punch_player2=false,flag_help2_power_punch_player2=false;
                            start_clock_help_punch2=0,start_clock_help2_punch2=0;


                            w_punch=0;

                            texture(m_renderer,385,0,"black.png",730,180);
                            texture(m_renderer,490,10,"yellow.png",182,160);
                            texture(m_renderer,828,10,"yellow.png",184,160);

                            draw_score_board=true;

                            counter_numGoal_player1='0';
                            counter_goal_plyer1=0;
                            counter_numGoal_player2='0';
                            counter_goal_plyer2=0;


                            setTime=setTime0;


                               }
                         }


                         if(dy_ball>30)
                         {
                             dy_ball-=3;

                         }
                        if(dy_ball<-30)
                         {
                             dy_ball+=3;

                         }








        if(clock()-start_clock_ball>=0 && clock()-start_clock_ball>200)
        {
            counter_play_ball='2';
        }
        if(clock()-start_clock_ball>=200 && clock()-start_clock_ball>400)
        {
            counter_play_ball='3';
        }
        if(clock()-start_clock_ball>=400 && clock()-start_clock_ball>600)
        {
            counter_play_ball='4';
        }
        if(clock()-start_clock_ball>=600 && clock()-start_clock_ball>800)
        {
            counter_play_ball='1';
            start_clock_ball=clock();
        }

    string ball="ball";
    ball.push_back(counter_setting_ball);
    ball.push_back(counter_play_ball);
    ball+=".png";


}

redraw=true;


 while(flag10)
    {

        SDL_PollEvent(e);


        if(redraw)
        {
                texture(m_renderer,0,0,"setting_background.png",1500,750);
                texture(m_renderer,20,650,"back.png",130,80);
                texture(m_renderer,350,80,"change_music.png",800,80);
                texture(m_renderer,300,240,"UEFA_Champions_League_sound.png",400,80);
                texture(m_renderer,800,240,"game_of_thrones_sound.png",400,80);
                texture(m_renderer,300,340,"the_champ_returns_sound.png",400,80);
                texture(m_renderer,800,340,"the_king_wins_sound.png",400,80);
                texture(m_renderer,300,440,"yungo_beat_sound.png",400,80);
                texture(m_renderer,800,440,"funk_bright_sound.png",400,80);
                texture(m_renderer,560,600,"volume1.png",80,80);
                texture(m_renderer,660,600,"volume2.png",80,80);
                texture(m_renderer,760,600,"volume3.png",80,80);
                texture(m_renderer,860,600,"volume4.png",80,80);


                redraw=false;

                SDL_RenderPresent( m_renderer );
        }






        if(e->type==SDL_MOUSEBUTTONDOWN)
         {
             x_mouse=e->motion.x;
             y_mouse=e->motion.y;



            string chunk_sound = "resources\\mouse_button.ogg"; //Chunk sound Address
            Mix_Chunk *collision = Mix_LoadWAV(chunk_sound.c_str()); //Load sound for wall collision
            Mix_PlayChannel(-1,collision,0);




                if(x_mouse >20 && x_mouse < 150 && y_mouse > 650 && y_mouse < 730 )
               {
                 flag10=false;
                 flag1=true;
               }
                else if(x_mouse > 300 && x_mouse < 700 && y_mouse > 240 && y_mouse < 320 )
                {
                    sound = "resources\\1.mp3";
                    GameSound = Mix_LoadMUS(sound.c_str());
                    Mix_PlayMusic(GameSound,-1);
                }
                 else if(x_mouse > 800 && x_mouse < 1200 && y_mouse >240 && y_mouse < 320 )
                {
                    sound = "resources\\2.mp3";
                    GameSound = Mix_LoadMUS(sound.c_str());
                    Mix_PlayMusic(GameSound,-1);
                }
                else if(x_mouse > 300 && x_mouse < 700 && y_mouse > 340 && y_mouse < 420 )
                {
                    sound = "resources\\3.mp3";
                    GameSound = Mix_LoadMUS(sound.c_str());
                    Mix_PlayMusic(GameSound,-1);
                }
                 else if(x_mouse > 800 && x_mouse < 1200 && y_mouse >340 && y_mouse < 420 )
                {
                    sound = "resources\\4.mp3";
                    GameSound = Mix_LoadMUS(sound.c_str());
                    Mix_PlayMusic(GameSound,-1);
                }
                else if(x_mouse > 300 && x_mouse < 700 && y_mouse > 440 && y_mouse < 520 )
                {
                    sound = "resources\\5.mp3";
                    GameSound = Mix_LoadMUS(sound.c_str());
                    Mix_PlayMusic(GameSound,-1);
                }
                 else if(x_mouse > 800 && x_mouse < 1200 && y_mouse >440 && y_mouse < 520 )
                {
                    sound = "resources\\6.mp3";
                    GameSound = Mix_LoadMUS(sound.c_str());
                    Mix_PlayMusic(GameSound,-1);
                }

                 else if(x_mouse > 560 && x_mouse < 640 && y_mouse >600 && y_mouse < 680 )
                {
                      Mix_VolumeMusic(500);

                }
                 else if(x_mouse > 660 && x_mouse < 740 && y_mouse >600 && y_mouse < 680 )
                {
                        Mix_VolumeMusic(200);

                }
                 else if(x_mouse > 760 && x_mouse < 840 && y_mouse >600 && y_mouse < 680 )
                {
                        Mix_VolumeMusic(50);

                }
                 else if(x_mouse > 860 && x_mouse < 940 && y_mouse >600 && y_mouse < 680 )
                {
                        Mix_VolumeMusic(0);

                }




         }

        e->type = 0;

    }


    redraw=true;




    while(flag11)
    {
        k=0;num=0;string asami[100];string table;


        SDL_PollEvent(e);


        if(redraw)
        {
                texture(m_renderer,0,0,"load_stadium.png",1500,750);
                texture(m_renderer,20,650,"back.png",130,80);



                redraw=false;

                SDL_RenderPresent( m_renderer );
        }


        if(e->type==SDL_MOUSEBUTTONDOWN)
         {
             x_mouse=e->motion.x;
             y_mouse=e->motion.y;

             for(int i=0;i<8;i++)
            {
                aacircleRGBA(m_renderer,x_mouse,y_mouse,30*i/5,255,0,0,255);
            }

            SDL_RenderPresent(m_renderer);

            string chunk_sound = "resources\\mouse_button.ogg"; //Chunk sound Address
            Mix_Chunk *collision = Mix_LoadWAV(chunk_sound.c_str()); //Load sound for wall collision
            Mix_PlayChannel(-1,collision,0);




                if(x_mouse >20 && x_mouse < 150 && y_mouse > 650 && y_mouse < 730 )
               {
                 flag11=false;
                 flag1=true;
               }

         }



       if(draw_table)
       {




            ifstream names("names.txt");
            while (names.good())
            {
             names>>asami[k];

             if(names.good())
             {
                k++;
                num++;
             }

            }
            names.close();
            string tedad_bord[10000];
            ifstream nbord("num_of_wins.txt");
            if (nbord.good())
            {
                   for (int i=0;i<num;)
                   {
                       nbord>>tedad_bord[i];

                       if (nbord.good())
                        {
                            i++;
                        }
                   }
                   nbord.close();
            }
            ifstream ngoalzade("num_of_goal_scores.txt");
            string tedad_goal_zade[10000];
            if (ngoalzade.good())
            {
                for (int i=0;i<num;)
                {
                    ngoalzade>>tedad_goal_zade[i];

                    if (ngoalzade.good())
                        i++;
                }

                ngoalzade.close();
            }
            ifstream ngoalkhorde("num_of_goal_concedes.txt");
            string tedad_goal_khorde[10000];
            if (ngoalkhorde.good())
            {
                for (int i=0;i<num;)
                {
                    ngoalkhorde>>tedad_goal_khorde[i];

                    if (ngoalkhorde.good())
                        i++;
                }
                ngoalkhorde.close();
            }
            string tedad_bakht[10000];
            ifstream nbakht("num_of_defeats.txt");
            if (nbakht.good())
            {
                   for (int i=0;i<num;)
                   {
                       nbakht>>tedad_bakht[i];

                       if (nbakht.good())
                        i++;
                   }
                   nbakht.close();
            }
            string tedad_mosavi[10000];
            ifstream nmosavi("num_of_drawns.txt");
            if (nmosavi.good())
            {
                   for (int i=0;i<num;)
                   {
                       nmosavi>>tedad_mosavi[i];

                       if (nmosavi.good())
                        i++;
                   }
                   nmosavi.close();
            }
            string tedad_bazi[10000];
            ifstream nbazi("num_of_performances.txt");
            if (nbazi.good())
            {
                   for (int i=0;i<num;)
                   {
                       nbazi>>tedad_bazi[i];

                       if (nbazi.good())
                        i++;
                   }
                   nbazi.close();
            }
            string tedad_tafazol_goal[10000];
            ifstream ntafazol("num_of_goal_difference.txt");
            if (ntafazol.good())
            {
                   for (int i=0;i<num;)
                   {
                       ntafazol>>tedad_tafazol_goal[i];
                       if (ntafazol.good())
                        i++;
                   }
                   ntafazol.close();
            }
            string emtiazha[10000];
            ifstream emtiaz("num_of_points.txt");
            if (emtiaz.good())
            {
                   for (int i=0;i<num;)
                   {
                       emtiaz>>emtiazha[i];
                       if (emtiaz.good())
                        i++;
                   }
                   emtiaz.close();
            }



            boxRGBA(m_renderer,100,30,1250,30+70*(num+1),90,90,90,255);
            for(int f=1;f<=num;f++)
            {
                aalineRGBA(m_renderer,100,30+f*70,1250,30+f*70,255,0,0,255);

                SDL_RenderPresent(m_renderer);
            }
            for(int f=1;f<=8;f++)
            {
                aalineRGBA(m_renderer,340+100*f,30,340+100*f,30+70*(num+1),255,0,0,255);
                SDL_RenderPresent(m_renderer);
            }
            table="player's name";
            textColor(m_renderer,120,40, table.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading,angle,NONE);
            table="MP";
            textColor(m_renderer,470,40, table.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading,angle,NONE);
            table="W";
            textColor(m_renderer,573,40, table.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading,angle,NONE);
            table="P";
            textColor(m_renderer,680,40, table.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading,angle,NONE);
            table="L";
            textColor(m_renderer,780,40, table.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading,angle,NONE);
            table="GF";
            textColor(m_renderer,870,40, table.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading,angle,NONE);
            table="GA";
            textColor(m_renderer,970,40, table.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading,angle,NONE);
            table="GD";
            textColor(m_renderer,1070,40, table.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading,angle,NONE);
            table="PTs";
            textColor(m_renderer,1170,40, table.c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading,angle,NONE);

            for(int f=0;f<num;f++)
            {
               textColor(m_renderer,120,105+f*70, asami[f].c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading2,angle,NONE);
            }
            for(int f=0;f<num;f++)
            {
               textColor(m_renderer,480,105+f*70, tedad_bazi[f].c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading2,angle,NONE);
            }
            for(int f=0;f<num;f++)
            {
               textColor(m_renderer,580,105+f*70, tedad_bord[f].c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading2,angle,NONE);
            }
            for(int f=0;f<num;f++)
            {
               textColor(m_renderer,680,105+f*70, tedad_mosavi[f].c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading2,angle,NONE);
            }
            for(int f=0;f<num;f++)
            {
               textColor(m_renderer,780,105+f*70, tedad_bakht[f].c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading2,angle,NONE);
            }
            for(int f=0;f<num;f++)
            {
               textColor(m_renderer,880,105+f*70, tedad_goal_zade[f].c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading2,angle,NONE);
            }
            for(int f=0;f<num;f++)
            {
               textColor(m_renderer,980,105+f*70, tedad_goal_khorde[f].c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading2,angle,NONE);
            }
            for(int f=0;f<num;f++)
            {
               textColor(m_renderer,1080,105+f*70, tedad_tafazol_goal[f].c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading2,angle,NONE);
            }
            for(int f=0;f<num;f++)
            {
               textColor(m_renderer,1180,105+f*70, emtiazha[f].c_str(),font_address_02 ,font_size_enter_name-20,text_color_setting_loading2,angle,NONE);
            }



            draw_table=false;

       }



        e->type = 0;

    }

    redraw=true;











                    while(flag12)
                    {


                        SDL_PollEvent(e);


                        if(redraw)
                        {
                                texture(m_renderer,0,0,"result.png",1500,750);

                                boxRGBA(m_renderer,0,180,1500,330,255,0,255,255);
                                string win0= " won the match ! did you enjoy it ?";
                                string win_player=name_player2_help+win0;

                                textColor(m_renderer,20,200, win_player.c_str(),font_address_03 ,font_size_enter_name+20,text_color_setting_loading2,angle,NONE);


                                texture(m_renderer,0,0,"scoreboard.png",1500,180);

                                textColor(m_renderer,1220,10, name_player2_help.c_str(),font_address_02 ,font_size_enter_name-10,text_color_setting_loading,angle,NONE);
                                textColor(m_renderer,20,10, name_player1_help.c_str(),font_address_02 ,font_size_enter_name-10,text_color_setting_loading,angle,NONE);




                                counter_numGoal_player1='0';
                                counter_numGoal_player2='5';
//
                                string numGoal_player1="1";
                                numGoal_player1.push_back(counter_numGoal_player1);
                                numGoal_player1+=".png";





                                string numGoal_player2="2";
                                numGoal_player2.push_back(counter_numGoal_player2);
                                numGoal_player2+=".png";

                                counter_numGoal_player1='0';
                                counter_numGoal_player2='0';
                                counter_goal_plyer1=0;
                                counter_goal_plyer2=0;
//
//                                boxRGBA(m_renderer,690,110,810,150,255,255,0,255);
//
//
                                texture(m_renderer,530,15,numGoal_player1,100,150);

                                texture(m_renderer,870,15,numGoal_player2,100,150);


                                texture(m_renderer,700,350,"restart.png",300,120);
                                texture(m_renderer,850,485,"menu.png",300,120);
                                texture(m_renderer,1000,620,"exit.png",300,120);




                                redraw=false;

                                SDL_RenderPresent( m_renderer );
                        }

                        counter_power_handling_player2=0;counter_power_handling_player1=0;

                        if(e->type==SDL_MOUSEBUTTONDOWN)
                         {
                             x_mouse=e->motion.x;
                             y_mouse=e->motion.y;

                             for(int i=0;i<8;i++)
                            {
                                aacircleRGBA(m_renderer,x_mouse,y_mouse,30*i/5,255,0,0,255);
                            }

                            SDL_RenderPresent(m_renderer);

                            string chunk_sound = "resources\\mouse_button.ogg"; //Chunk sound Address
                            Mix_Chunk *collision = Mix_LoadWAV(chunk_sound.c_str()); //Load sound for wall collision
                            Mix_PlayChannel(-1,collision,0);




                                if(x_mouse >1000 && x_mouse < 1300 && y_mouse > 620 && y_mouse < 740 )
                               {

                                 flag12=false;

                                 //flag_control_whole_game=false;

                                 flag_exit=true;

                                 sound = "resources\\exit1.mp3";
                    GameSound = Mix_LoadMUS(sound.c_str());
                    Mix_PlayMusic(GameSound,-1);

                               }


                               else if(x_mouse >700 && x_mouse < 1000 && y_mouse > 350 && y_mouse < 470 )
                               {

                                    flag12=false;

                                    flag_setting_compile_game=false;

                                    flag8=true;




                                    string sound = "resources\\0.mp3"; //Background sound Address

                                    Mix_Music *GameSound = Mix_LoadMUS(sound.c_str()); //Load background sound

                                    Mix_PlayMusic(GameSound,-1); //Play the sound.  -1 means play it till the end



                            flag_visible_ball=true;
                            x_ball=x0_ball;
                            y_ball=y0_ball;
                            dx_ball=dx0_ball;
                            dy_ball=dy0_ball;
                            first_collision_ball=true;
                            y_ball_goal=500;
                            x_ball_goal=750;
                            dx_ball_goal=0;
                            dy_ball_goal=0;
                            x_player1=200;
                            x_player2=1200;
                            flag_help2_power_headfireball_player1=false;
                            flag_help3_power_headfireball_player1=false;
                            count_dx_player2=0;
                            flag_help4_power_headfireball_player1=false;
                            flag_help2_power_headfireball_player2=false;
                            flag_help3_power_headfireball_player2=false;
                            count_dx_player1=200;
                            flag_help4_power_headfireball_player2=false;

                            flag_help2_power_kickfireball_player1=false;
                            flag_help3_power_kickfireball_player1=false;
                            count_dx_player2=0;
                            flag_help4_power_kickfireball_player1=false;

                            flag_help2_power_kickfireball_player2=false;
                            flag_help3_power_kickfireball_player2=false;
                            count_dx_player1=200;
                            flag_help4_power_kickfireball_player2=false;


                            y_player1=480;
                            y_player2=480;


                            counter_play_playing_player1='0';
                            counter_play_playing_player2='0';



                            flag_power_invisibleball_player1=false,flag_help_power_invisibleball_kick_player1=false,flag_help2_power_invisibleball_kick_player1=false;
                            flag_help_power_invisibleball_head_player1=false,flag_help2_power_invisibleball_head_player1=false,flag_help3_power_invisibleball_head_player1=false,flag_help4_power_invisibleball_head_player1=false;


                            flag_power_invisibleball_player2=false,flag_help_power_invisibleball_kick_player2=false,flag_help2_power_invisibleball_kick_player2=false;
                            flag_help_power_invisibleball_head_player2=false,flag_help2_power_invisibleball_head_player2=false,flag_help3_power_invisibleball_head_player2=false,flag_help4_power_invisibleball_head_player2=false;

                            flag_power_punch_player1=false,flag_help_power_punch_player1=false,flag_help2_power_punch_player1=false;
                            start_clock_help_punch=0,start_clock_help2_punch=0;

                            w_punch=0;


                            flag_power_punch_player2=false,flag_help_power_punch_player2=false,flag_help2_power_punch_player2=false;
                            start_clock_help_punch2=0,start_clock_help2_punch2=0;


                            w_punch=0;

                            texture(m_renderer,385,0,"black.png",730,180);
                            texture(m_renderer,490,10,"yellow.png",182,160);
                            texture(m_renderer,828,10,"yellow.png",184,160);

                            draw_score_board=true;

                            counter_numGoal_player1='0';
                            counter_goal_plyer1=0;
                            counter_numGoal_player2='0';
                            counter_goal_plyer2=0;


                            setTime=setTime0;


                               }



                               else if(x_mouse >850 && x_mouse < 1150 && y_mouse > 485 && y_mouse < 605 )
                               {

                                    flag12=false;

                                    flag_setting_compile_game=false;

                                    flag1=true;redraw=true;




                                    string sound = "resources\\0.mp3"; //Background sound Address

                                    Mix_Music *GameSound = Mix_LoadMUS(sound.c_str()); //Load background sound

                                    Mix_PlayMusic(GameSound,-1); //Play the sound.  -1 means play it till the end



                                    flag_visible_ball=true;
                            x_ball=x0_ball;
                            y_ball=y0_ball;
                            dx_ball=dx0_ball;
                            dy_ball=dy0_ball;
                            first_collision_ball=true;
                            y_ball_goal=500;
                            x_ball_goal=750;
                            dx_ball_goal=0;
                            dy_ball_goal=0;
                            x_player1=200;
                            x_player2=1200;
                            flag_help2_power_headfireball_player1=false;
                            flag_help3_power_headfireball_player1=false;
                            count_dx_player2=0;
                            flag_help4_power_headfireball_player1=false;
                            flag_help2_power_headfireball_player2=false;
                            flag_help3_power_headfireball_player2=false;
                            count_dx_player1=200;
                            flag_help4_power_headfireball_player2=false;

                            flag_help2_power_kickfireball_player1=false;
                            flag_help3_power_kickfireball_player1=false;
                            count_dx_player2=0;
                            flag_help4_power_kickfireball_player1=false;

                            flag_help2_power_kickfireball_player2=false;
                            flag_help3_power_kickfireball_player2=false;
                            count_dx_player1=200;
                            flag_help4_power_kickfireball_player2=false;


                            y_player1=480;
                            y_player2=480;


                            counter_play_playing_player1='0';
                            counter_play_playing_player2='0';



                            flag_power_invisibleball_player1=false,flag_help_power_invisibleball_kick_player1=false,flag_help2_power_invisibleball_kick_player1=false;
                            flag_help_power_invisibleball_head_player1=false,flag_help2_power_invisibleball_head_player1=false,flag_help3_power_invisibleball_head_player1=false,flag_help4_power_invisibleball_head_player1=false;


                            flag_power_invisibleball_player2=false,flag_help_power_invisibleball_kick_player2=false,flag_help2_power_invisibleball_kick_player2=false;
                            flag_help_power_invisibleball_head_player2=false,flag_help2_power_invisibleball_head_player2=false,flag_help3_power_invisibleball_head_player2=false,flag_help4_power_invisibleball_head_player2=false;

                            flag_power_punch_player1=false,flag_help_power_punch_player1=false,flag_help2_power_punch_player1=false;
                            start_clock_help_punch=0,start_clock_help2_punch=0;

                            w_punch=0;


                            flag_power_punch_player2=false,flag_help_power_punch_player2=false,flag_help2_power_punch_player2=false;
                            start_clock_help_punch2=0,start_clock_help2_punch2=0;


                            w_punch=0;

                            texture(m_renderer,385,0,"black.png",730,180);
                            texture(m_renderer,490,10,"yellow.png",182,160);
                            texture(m_renderer,828,10,"yellow.png",184,160);

                            draw_score_board=true;

                            counter_numGoal_player1='0';
                            counter_goal_plyer1=0;
                            counter_numGoal_player2='0';
                            counter_goal_plyer2=0;


                            setTime=setTime0;


                               }
                         }
                    }



redraw=true;




                     while(flag13)
                    {




                        SDL_PollEvent(e);


                        if(redraw)
                        {
                                texture(m_renderer,0,0,"result.png",1500,750);

                                boxRGBA(m_renderer,0,180,1500,330,255,0,255,255);
                                string win0= " won the match ! did you enjoy it ?";
                                string win_player=name_player1_help+win0;

                                textColor(m_renderer,20,200, win_player.c_str(),font_address_03 ,font_size_enter_name+20,text_color_setting_loading2,angle,NONE);


                                texture(m_renderer,0,0,"scoreboard.png",1500,180);

                                textColor(m_renderer,1220,10, name_player2_help.c_str(),font_address_02 ,font_size_enter_name-10,text_color_setting_loading,angle,NONE);
                                textColor(m_renderer,20,10, name_player1_help.c_str(),font_address_02 ,font_size_enter_name-10,text_color_setting_loading,angle,NONE);




                                counter_numGoal_player1='5';
                                counter_numGoal_player2='0';
//
                                string numGoal_player1="1";
                                numGoal_player1.push_back(counter_numGoal_player1);
                                numGoal_player1+=".png";





                                string numGoal_player2="2";
                                numGoal_player2.push_back(counter_numGoal_player2);
                                numGoal_player2+=".png";


                                counter_numGoal_player1='0';
                                counter_numGoal_player2='0';
                                counter_goal_plyer1=0;
                                counter_goal_plyer2=0;
//                                boxRGBA(m_renderer,690,110,810,150,255,255,0,255);
//
//
                                texture(m_renderer,530,15,numGoal_player1,100,150);

                                texture(m_renderer,870,15,numGoal_player2,100,150);


                                texture(m_renderer,700,350,"restart.png",300,120);
                                texture(m_renderer,850,485,"menu.png",300,120);
                                texture(m_renderer,1000,620,"exit.png",300,120);




                                redraw=false;

                                SDL_RenderPresent( m_renderer );
                        }


                        counter_power_handling_player2=0;counter_power_handling_player1=0;

                        if(e->type==SDL_MOUSEBUTTONDOWN)
                         {
                             x_mouse=e->motion.x;
                             y_mouse=e->motion.y;

                             for(int i=0;i<8;i++)
                            {
                                aacircleRGBA(m_renderer,x_mouse,y_mouse,30*i/5,255,0,0,255);
                            }

                            SDL_RenderPresent(m_renderer);

                            string chunk_sound = "resources\\mouse_button.ogg"; //Chunk sound Address
                            Mix_Chunk *collision = Mix_LoadWAV(chunk_sound.c_str()); //Load sound for wall collision
                            Mix_PlayChannel(-1,collision,0);




                                if(x_mouse >1000 && x_mouse < 1300 && y_mouse > 620 && y_mouse < 740 )
                               {

                                 flag13=false;

                                 //flag_control_whole_game=false;

                                 flag_exit=true;

                                 sound = "resources\\exit1.mp3";
                    GameSound = Mix_LoadMUS(sound.c_str());
                    Mix_PlayMusic(GameSound,-1);

                               }


                               else if(x_mouse >700 && x_mouse < 1000 && y_mouse > 350 && y_mouse < 470 )
                               {

                                    flag13=false;

                                    flag_setting_compile_game=false;

                                    flag8=true;




                                    string sound = "resources\\0.mp3"; //Background sound Address

                                    Mix_Music *GameSound = Mix_LoadMUS(sound.c_str()); //Load background sound

                                    Mix_PlayMusic(GameSound,-1); //Play the sound.  -1 means play it till the end



                            flag_visible_ball=true;
                            x_ball=x0_ball;
                            y_ball=y0_ball;
                            dx_ball=dx0_ball;
                            dy_ball=dy0_ball;
                            first_collision_ball=true;
                            y_ball_goal=500;
                            x_ball_goal=750;
                            dx_ball_goal=0;
                            dy_ball_goal=0;
                            x_player1=200;
                            x_player2=1200;
                            flag_help2_power_headfireball_player1=false;
                            flag_help3_power_headfireball_player1=false;
                            count_dx_player2=0;
                            flag_help4_power_headfireball_player1=false;
                            flag_help2_power_headfireball_player2=false;
                            flag_help3_power_headfireball_player2=false;
                            count_dx_player1=200;
                            flag_help4_power_headfireball_player2=false;

                            flag_help2_power_kickfireball_player1=false;
                            flag_help3_power_kickfireball_player1=false;
                            count_dx_player2=0;
                            flag_help4_power_kickfireball_player1=false;

                            flag_help2_power_kickfireball_player2=false;
                            flag_help3_power_kickfireball_player2=false;
                            count_dx_player1=200;
                            flag_help4_power_kickfireball_player2=false;


                            y_player1=480;
                            y_player2=480;


                            counter_play_playing_player1='0';
                            counter_play_playing_player2='0';



                            flag_power_invisibleball_player1=false,flag_help_power_invisibleball_kick_player1=false,flag_help2_power_invisibleball_kick_player1=false;
                            flag_help_power_invisibleball_head_player1=false,flag_help2_power_invisibleball_head_player1=false,flag_help3_power_invisibleball_head_player1=false,flag_help4_power_invisibleball_head_player1=false;


                            flag_power_invisibleball_player2=false,flag_help_power_invisibleball_kick_player2=false,flag_help2_power_invisibleball_kick_player2=false;
                            flag_help_power_invisibleball_head_player2=false,flag_help2_power_invisibleball_head_player2=false,flag_help3_power_invisibleball_head_player2=false,flag_help4_power_invisibleball_head_player2=false;

                            flag_power_punch_player1=false,flag_help_power_punch_player1=false,flag_help2_power_punch_player1=false;
                            start_clock_help_punch=0,start_clock_help2_punch=0;

                            w_punch=0;


                            flag_power_punch_player2=false,flag_help_power_punch_player2=false,flag_help2_power_punch_player2=false;
                            start_clock_help_punch2=0,start_clock_help2_punch2=0;


                            w_punch=0;

                            texture(m_renderer,385,0,"black.png",730,180);
                            texture(m_renderer,490,10,"yellow.png",182,160);
                            texture(m_renderer,828,10,"yellow.png",184,160);

                            draw_score_board=true;

                            counter_numGoal_player1='0';
                            counter_goal_plyer1=0;
                            counter_numGoal_player2='0';
                            counter_goal_plyer2=0;


                            setTime=setTime0;


                               }



                               else if(x_mouse >850 && x_mouse < 1150 && y_mouse > 485 && y_mouse < 605 )
                               {

                                    flag13=false;

                                    flag_setting_compile_game=false;

                                    flag1=true;redraw=true;




                                    string sound = "resources\\0.mp3"; //Background sound Address

                                    Mix_Music *GameSound = Mix_LoadMUS(sound.c_str()); //Load background sound

                                    Mix_PlayMusic(GameSound,-1); //Play the sound.  -1 means play it till the end



                                    flag_visible_ball=true;
                            x_ball=x0_ball;
                            y_ball=y0_ball;
                            dx_ball=dx0_ball;
                            dy_ball=dy0_ball;
                            first_collision_ball=true;
                            y_ball_goal=500;
                            x_ball_goal=750;
                            dx_ball_goal=0;
                            dy_ball_goal=0;
                            x_player1=200;
                            x_player2=1200;
                            flag_help2_power_headfireball_player1=false;
                            flag_help3_power_headfireball_player1=false;
                            count_dx_player2=0;
                            flag_help4_power_headfireball_player1=false;
                            flag_help2_power_headfireball_player2=false;
                            flag_help3_power_headfireball_player2=false;
                            count_dx_player1=200;
                            flag_help4_power_headfireball_player2=false;

                            flag_help2_power_kickfireball_player1=false;
                            flag_help3_power_kickfireball_player1=false;
                            count_dx_player2=0;
                            flag_help4_power_kickfireball_player1=false;

                            flag_help2_power_kickfireball_player2=false;
                            flag_help3_power_kickfireball_player2=false;
                            count_dx_player1=200;
                            flag_help4_power_kickfireball_player2=false;


                            y_player1=480;
                            y_player2=480;


                            counter_play_playing_player1='0';
                            counter_play_playing_player2='0';



                            flag_power_invisibleball_player1=false,flag_help_power_invisibleball_kick_player1=false,flag_help2_power_invisibleball_kick_player1=false;
                            flag_help_power_invisibleball_head_player1=false,flag_help2_power_invisibleball_head_player1=false,flag_help3_power_invisibleball_head_player1=false,flag_help4_power_invisibleball_head_player1=false;


                            flag_power_invisibleball_player2=false,flag_help_power_invisibleball_kick_player2=false,flag_help2_power_invisibleball_kick_player2=false;
                            flag_help_power_invisibleball_head_player2=false,flag_help2_power_invisibleball_head_player2=false,flag_help3_power_invisibleball_head_player2=false,flag_help4_power_invisibleball_head_player2=false;

                            flag_power_punch_player1=false,flag_help_power_punch_player1=false,flag_help2_power_punch_player1=false;
                            start_clock_help_punch=0,start_clock_help2_punch=0;

                            w_punch=0;


                            flag_power_punch_player2=false,flag_help_power_punch_player2=false,flag_help2_power_punch_player2=false;
                            start_clock_help_punch2=0,start_clock_help2_punch2=0;


                            w_punch=0;

                            texture(m_renderer,385,0,"black.png",730,180);
                            texture(m_renderer,490,10,"yellow.png",182,160);
                            texture(m_renderer,828,10,"yellow.png",184,160);

                            draw_score_board=true;

                            counter_numGoal_player1='0';
                            counter_goal_plyer1=0;
                            counter_numGoal_player2='0';
                            counter_goal_plyer2=0;


                            setTime=setTime0;


                               }
                         }
                    }


redraw=true;



while(flag_exit)
    {



                        if(redraw)
                        {
                                texture(m_renderer,0,0,"result.png",1500,750);

                                redraw=false;

                                SDL_RenderPresent( m_renderer );
                        }


                    char chp=49;

                    for(chp=49;chp<58;chp++)
                    {
                        string video;
                        //if(chp<10)
                        //video="ezgif-frame-00";
                        //else
                        video="exit\\ezgif-frame-00";
                        //string shp=to_sting(jj);
                        //char chp=shp.c_str();
                        video.push_back(chp);
                        video+=".png";

                        texture(m_renderer,200,50,video,1100,650);

                        SDL_RenderPresent(m_renderer);SDL_Delay(91);


                    }

                    for(chp=48;chp<58;chp++)
                    {
                        string video;
                        //if(chp<10)
                        //video="ezgif-frame-00";
                        //else
                        video="exit\\ezgif-frame-01";
                        //string shp=to_sting(jj);
                        //char chp=shp.c_str();
                        video.push_back(chp);
                        video+=".png";

                        texture(m_renderer,200,50,video,1100,650); SDL_RenderPresent(m_renderer);SDL_Delay(91);



                    }

                    for(chp=48;chp<58;chp++)
                    {
                        string video;
                        //if(chp<10)
                        //video="ezgif-frame-00";
                        //else
                        video="exit\\ezgif-frame-02";
                        //string shp=to_sting(jj);
                        //char chp=shp.c_str();
                        video.push_back(chp);
                        video+=".png";

                        texture(m_renderer,200,50,video,1100,650); SDL_RenderPresent(m_renderer);SDL_Delay(91);



                    }

                    for(chp=48;chp<58;chp++)
                    {
                        string video;
                        //if(chp<10)
                        //video="ezgif-frame-00";
                        //else
                        video="exit\\ezgif-frame-03";
                        //string shp=to_sting(jj);
                        //char chp=shp.c_str();
                        video.push_back(chp);
                        video+=".png";

                        texture(m_renderer,200,50,video,1100,650); SDL_RenderPresent(m_renderer);SDL_Delay(91);



                    }



                    for(chp=48;chp<58;chp++)
                    {
                        string video;
                        //if(chp<10)
                        //video="ezgif-frame-00";
                        //else
                        video="exit\\ezgif-frame-04";
                        //string shp=to_sting(jj);
                        //char chp=shp.c_str();
                        video.push_back(chp);
                        video+=".png";

                        texture(m_renderer,200,50,video,1100,650); SDL_RenderPresent(m_renderer);SDL_Delay(90);



                    }

                    for(chp=48;chp<58;chp++)
                    {
                        string video;
                        //if(chp<10)
                        //video="ezgif-frame-00";
                        //else
                        video="exit\\ezgif-frame-05";
                        //string shp=to_sting(jj);
                        //char chp=shp.c_str();
                        video.push_back(chp);
                        video+=".png";

                        texture(m_renderer,200,50,video,1100,650);SDL_RenderPresent(m_renderer);SDL_Delay(90);



                    }
                    for(chp=48;chp<58;chp++)
                    {
                        string video;
                        //if(chp<10)
                        //video="ezgif-frame-00";
                        //else
                        video="exit\\ezgif-frame-06";
                        //string shp=to_sting(jj);
                        //char chp=shp.c_str();
                        video.push_back(chp);
                        video+=".png";

                        texture(m_renderer,200,50,video,1100,650);
                        SDL_RenderPresent(m_renderer);SDL_Delay(90);



                    }
                    for(chp=48;chp<58;chp++)
                    {
                        string video;
                        //if(chp<10)
                        //video="ezgif-frame-00";
                        //else
                        video="exit\\ezgif-frame-07";
                        //string shp=to_sting(jj);
                        //char chp=shp.c_str();
                        video.push_back(chp);
                        video+=".png";

                        texture(m_renderer,200,50,video,1100,650); SDL_RenderPresent(m_renderer);SDL_Delay(90);



                    }
                    for(chp=48;chp<58;chp++)
                    {
                        string video;
                        //if(chp<10)
                        //video="ezgif-frame-00";
                        //else
                        video="exit\\ezgif-frame-08";
                        //string shp=to_sting(jj);
                        //char chp=shp.c_str();
                        video.push_back(chp);
                        video+=".png";

                        texture(m_renderer,200,50,video,1100,650); SDL_RenderPresent(m_renderer);SDL_Delay(90);



                    }
                    for(chp=48;chp<58;chp++)
                    {
                        string video;
                        //if(chp<10)
                        //video="ezgif-frame-00";
                        //else
                        video="exit\\ezgif-frame-09";
                        //string shp=to_sting(jj);
                        //char chp=shp.c_str();
                        video.push_back(chp);
                        video+=".png";

                        texture(m_renderer,200,50,video,1100,650); SDL_RenderPresent(m_renderer);SDL_Delay(90);



                    }
                    for(chp=48;chp<58;chp++)
                    {
                        string video;
                        //if(chp<10)
                        //video="ezgif-frame-00";
                        //else
                        video="exit\\ezgif-frame-10";
                        //string shp=to_sting(jj);
                        //char chp=shp.c_str();
                        video.push_back(chp);
                        video+=".png";

                        texture(m_renderer,200,50,video,1100,650);SDL_RenderPresent(m_renderer);SDL_Delay(90);



                    }
                    for(chp=48;chp<58;chp++)
                    {
                        string video;
                        //if(chp<10)
                        //video="ezgif-frame-00";
                        //else
                        video="exit\\ezgif-frame-11";
                        //string shp=to_sting(jj);
                        //char chp=shp.c_str();
                        video.push_back(chp);
                        video+=".png";

                       texture(m_renderer,200,50,video,1100,650); SDL_RenderPresent(m_renderer);SDL_Delay(90);



                    }

                    for(chp=48;chp<58;chp++)
                    {
                        string video;
                        //if(chp<10)
                        //video="ezgif-frame-00";
                        //else
                        video="exit\\ezgif-frame-12";
                        //string shp=to_sting(jj);
                        //char chp=shp.c_str();
                        video.push_back(chp);
                        video+=".png";

                        texture(m_renderer,200,50,video,1100,650); SDL_RenderPresent(m_renderer);SDL_Delay(90);

                    }

                    for(chp=48;chp<58;chp++)
                    {
                        string video;
                        //if(chp<10)
                        //video="ezgif-frame-00";
                        //else
                        video="exit\\ezgif-frame-13";
                        //string shp=to_sting(jj);
                        //char chp=shp.c_str();
                        video.push_back(chp);
                        video+=".png";

                        texture(m_renderer,200,50,video,1100,650); SDL_RenderPresent(m_renderer);SDL_Delay(90);

                    }

                    for(chp=48;chp<58;chp++)
                    {
                        string video;
                        //if(chp<10)
                        //video="ezgif-frame-00";
                        //else
                        video="exit\\ezgif-frame-14";
                        //string shp=to_sting(jj);
                        //char chp=shp.c_str();
                        video.push_back(chp);
                        video+=".png";

                        texture(m_renderer,200,50,video,1100,650);SDL_RenderPresent(m_renderer);SDL_Delay(90);


                    }


                    flag_exit=false;
                    flag_sure=true;

                    string sound = "resources\\4.mp3"; //Background sound Address

                                    Mix_Music *GameSound = Mix_LoadMUS(sound.c_str()); //Load background sound

                                    Mix_PlayMusic(GameSound,-1); //Play the sound.  -1 means play it till the end

    }


    redraw=true;


    while(flag_sure)
    {

                        SDL_PollEvent(e);


                        if(redraw)
                        {
                                texture(m_renderer,0,0,"result.png",1500,750);
                                texture(m_renderer,400,40,"sure.png",700,100);
                                texture(m_renderer,500,190,"yes.png",200,100);
                                texture(m_renderer,800,190,"no.png",200,100);
                                redraw=false;

                                SDL_RenderPresent( m_renderer );
                        }


                        if(e->type==SDL_MOUSEBUTTONDOWN)
                         {
                             x_mouse=e->motion.x;
                             y_mouse=e->motion.y;

                             for(int i=0;i<8;i++)
                            {
                                aacircleRGBA(m_renderer,x_mouse,y_mouse,30*i/5,255,0,0,255);
                            }


                            SDL_RenderPresent(m_renderer);

                            string chunk_sound = "resources\\mouse_button.ogg"; //Chunk sound Address
            Mix_Chunk *collision = Mix_LoadWAV(chunk_sound.c_str()); //Load sound for wall collision
            Mix_PlayChannel(-1,collision,0);




                                if(x_mouse >500 && x_mouse < 700 && y_mouse > 190 && y_mouse < 290 )
                               {

                                 flag_sure=false;

                                 flag_control_whole_game=false;

                               }


                               else if(x_mouse >800 && x_mouse < 1000 && y_mouse > 190 && y_mouse < 290 )
                               {

                                    flag_sure=false;

                                    flag_setting_compile_game=false;

                                    flag1=true;




                                    string sound = "resources\\0.mp3"; //Background sound Address

                                    Mix_Music *GameSound = Mix_LoadMUS(sound.c_str()); //Load background sound

                                    Mix_PlayMusic(GameSound,-1); //Play the sound.  -1 means play it till the end



                            flag_visible_ball=true;
                            x_ball=x0_ball;
                            y_ball=y0_ball;
                            dx_ball=dx0_ball;
                            dy_ball=dy0_ball;
                            first_collision_ball=true;
                            y_ball_goal=500;
                            x_ball_goal=750;
                            dx_ball_goal=0;
                            dy_ball_goal=0;
                            x_player1=200;
                            x_player2=1200;
                            flag_help2_power_headfireball_player1=false;
                            flag_help3_power_headfireball_player1=false;
                            count_dx_player2=0;
                            flag_help4_power_headfireball_player1=false;
                            flag_help2_power_headfireball_player2=false;
                            flag_help3_power_headfireball_player2=false;
                            count_dx_player1=200;
                            flag_help4_power_headfireball_player2=false;

                            flag_help2_power_kickfireball_player1=false;
                            flag_help3_power_kickfireball_player1=false;
                            count_dx_player2=0;
                            flag_help4_power_kickfireball_player1=false;

                            flag_help2_power_kickfireball_player2=false;
                            flag_help3_power_kickfireball_player2=false;
                            count_dx_player1=200;
                            flag_help4_power_kickfireball_player2=false;


                            y_player1=480;
                            y_player2=480;


                            counter_play_playing_player1='0';
                            counter_play_playing_player2='0';



                            flag_power_invisibleball_player1=false,flag_help_power_invisibleball_kick_player1=false,flag_help2_power_invisibleball_kick_player1=false;
                            flag_help_power_invisibleball_head_player1=false,flag_help2_power_invisibleball_head_player1=false,flag_help3_power_invisibleball_head_player1=false,flag_help4_power_invisibleball_head_player1=false;


                            flag_power_invisibleball_player2=false,flag_help_power_invisibleball_kick_player2=false,flag_help2_power_invisibleball_kick_player2=false;
                            flag_help_power_invisibleball_head_player2=false,flag_help2_power_invisibleball_head_player2=false,flag_help3_power_invisibleball_head_player2=false,flag_help4_power_invisibleball_head_player2=false;

                            flag_power_punch_player1=false,flag_help_power_punch_player1=false,flag_help2_power_punch_player1=false;
                            start_clock_help_punch=0,start_clock_help2_punch=0;

                            w_punch=0;


                            flag_power_punch_player2=false,flag_help_power_punch_player2=false,flag_help2_power_punch_player2=false;
                            start_clock_help_punch2=0,start_clock_help2_punch2=0;


                            w_punch=0;

                            texture(m_renderer,385,0,"black.png",730,180);
                            texture(m_renderer,490,10,"yellow.png",182,160);
                            texture(m_renderer,828,10,"yellow.png",184,160);

                            draw_score_board=true;

                            counter_numGoal_player1='0';
                            counter_goal_plyer1=0;
                            counter_numGoal_player2='0';
                            counter_goal_plyer2=0;


                            setTime=setTime0;


                               }



                               else if(x_mouse >850 && x_mouse < 1150 && y_mouse > 485 && y_mouse < 605 )
                               {

                                    flag13=false;

                                    flag_setting_compile_game=false;

                                    flag1=true;redraw=true;




                                    string sound = "resources\\0.mp3"; //Background sound Address

                                    Mix_Music *GameSound = Mix_LoadMUS(sound.c_str()); //Load background sound

                                    Mix_PlayMusic(GameSound,-1); //Play the sound.  -1 means play it till the end



                                    flag_visible_ball=true;
                            x_ball=x0_ball;
                            y_ball=y0_ball;
                            dx_ball=dx0_ball;
                            dy_ball=dy0_ball;
                            first_collision_ball=true;
                            y_ball_goal=500;
                            x_ball_goal=750;
                            dx_ball_goal=0;
                            dy_ball_goal=0;
                            x_player1=200;
                            x_player2=1200;
                            flag_help2_power_headfireball_player1=false;
                            flag_help3_power_headfireball_player1=false;
                            count_dx_player2=0;
                            flag_help4_power_headfireball_player1=false;
                            flag_help2_power_headfireball_player2=false;
                            flag_help3_power_headfireball_player2=false;
                            count_dx_player1=200;
                            flag_help4_power_headfireball_player2=false;

                            flag_help2_power_kickfireball_player1=false;
                            flag_help3_power_kickfireball_player1=false;
                            count_dx_player2=0;
                            flag_help4_power_kickfireball_player1=false;

                            flag_help2_power_kickfireball_player2=false;
                            flag_help3_power_kickfireball_player2=false;
                            count_dx_player1=200;
                            flag_help4_power_kickfireball_player2=false;


                            y_player1=480;
                            y_player2=480;


                            counter_play_playing_player1='0';
                            counter_play_playing_player2='0';



                            flag_power_invisibleball_player1=false,flag_help_power_invisibleball_kick_player1=false,flag_help2_power_invisibleball_kick_player1=false;
                            flag_help_power_invisibleball_head_player1=false,flag_help2_power_invisibleball_head_player1=false,flag_help3_power_invisibleball_head_player1=false,flag_help4_power_invisibleball_head_player1=false;


                            flag_power_invisibleball_player2=false,flag_help_power_invisibleball_kick_player2=false,flag_help2_power_invisibleball_kick_player2=false;
                            flag_help_power_invisibleball_head_player2=false,flag_help2_power_invisibleball_head_player2=false,flag_help3_power_invisibleball_head_player2=false,flag_help4_power_invisibleball_head_player2=false;

                            flag_power_punch_player1=false,flag_help_power_punch_player1=false,flag_help2_power_punch_player1=false;
                            start_clock_help_punch=0,start_clock_help2_punch=0;

                            w_punch=0;


                            flag_power_punch_player2=false,flag_help_power_punch_player2=false,flag_help2_power_punch_player2=false;
                            start_clock_help_punch2=0,start_clock_help2_punch2=0;


                            w_punch=0;

                            texture(m_renderer,385,0,"black.png",730,180);
                            texture(m_renderer,490,10,"yellow.png",182,160);
                            texture(m_renderer,828,10,"yellow.png",184,160);

                            draw_score_board=true;

                            counter_numGoal_player1='0';
                            counter_goal_plyer1=0;
                            counter_numGoal_player2='0';
                            counter_goal_plyer2=0;


                            setTime=setTime0;


                               }
                         }


                         e->type = 0;
    }



redraw=true;

e->type = 0;


}


    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
	IMG_Quit();
	Mix_Quit();
	SDL_Quit();
    return 0;

}


void window_color(SDL_Renderer *Renderer, int R, int G, int B)
{
    SDL_SetRenderDrawColor(Renderer,R,G,B,255);
    SDL_RenderClear(Renderer);
}


void textColor(SDL_Renderer *renderer,int x,int y,const char * text,const char * font,int font_size,SDL_Color textColor,double angle,short flip_num)
{
    int mWidth = 0;
	int mHeight = 0;
    SDL_Rect* clip = NULL;
    TTF_Font *gFont = NULL;
    SDL_Point* center = NULL;

    SDL_RendererFlip flip;
    switch(flip_num){
        case 0:
            flip = SDL_FLIP_NONE;
            break;
        case 1:
            flip = SDL_FLIP_HORIZONTAL;
            break;
        case 2:
            flip = SDL_FLIP_VERTICAL;
            break;
        case 3:
            flip = (SDL_RendererFlip) (SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);
            break;
        default:
            flip = SDL_FLIP_NONE;
    }

    SDL_Texture* mTexture = NULL;
    gFont = TTF_OpenFont(font, font_size);

    SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, text, textColor);

    mWidth = textSurface->w;
    mHeight = textSurface->h;
    mTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);


    SDL_Rect renderQuad = {x , y, mWidth, mHeight};
    SDL_RenderCopyEx(renderer, mTexture, clip, &renderQuad, angle, center, flip);

    SDL_DestroyTexture(mTexture);
    SDL_RenderPresent(renderer);
}
void texture(SDL_Renderer *m_renderer,int xp,int yp,string addressOfImage,int width,int height)
{
        int n = addressOfImage.length();
        char char_array[n+1];

        strcpy(char_array, addressOfImage.c_str());
        SDL_Texture *myTexture;
        myTexture = IMG_LoadTexture( m_renderer, char_array);
        int w1, h1;
        SDL_QueryTexture(myTexture, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = xp;
        texr1.y = yp;
        texr1.w = width;
        texr1.h = height;
        SDL_RenderCopy( m_renderer, myTexture, NULL, &texr1);
            SDL_DestroyTexture(myTexture);
}
