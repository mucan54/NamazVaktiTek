#include <pebble.h>
  
#define G1 0
#define Tch 1
#define G2 2
#define G3 3
#define G4 4
#define G5 5

static char Hour[] = "00";
static char Min[] = "00";

  
static Window *s_main_window;
static TextLayer *s_time_layer;
static TextLayer *s_timev_layer;
static TextLayer *s_timevt_layer;
static TextLayer *s_timek_layer;


static GFont s_timev_font;
static GFont s_time_font;
static GFont s_weather_font;

static char g1[300]="0";
static char g2[300]="0";
static char g3[300]="0";
static char g4[300]="0";
static char g5[300]="0";
static char gs[300]="0";
static int ttimes;
static int ttimes2;
static int iimsak;
static int iimsak2;
static int ggunes;
static int oogle;
static int iikindi;
static int aaksam;
static int yyatsi;
static int hay;
static int tod=1;
static int hayyg;
static int yy=0;
static int shw=0;
static int tch=0;
static int shw2=0;
static char imsak[6]="0";
static char imsak2[6]="0";
static char gunes[6]="0";
static char ogle[6]="0";
static char ikindi[6]="0";
static char aksam[6]="0";
static char yatsi[6]="0";
static char ttime[12]="0";
   char vakit[11]="0";
   char vakitt[6]="0";
static char dateString[] = "0000-00-00";
static char tarih[11];
static char htarih[11];
   static int timer=0,timer3=0,updt=0;
  int x=0,y=1,ctrl;
  int buffer=0;
        static char ay[] = "00";
          static char ayg[] = "00";
static char Day[] = "00";
    int days;
static char dayt[11];
static char ayt[11];
static char hayy[20];
static char bufftr[20];
static char buffhtr[20];
  int ays;


static void tarihsp ()
  {
  
   days=Day[0]-'0';
    ays=(ayg[0]-'0')*10+(ayg[1]-'0')-1;
     if(days==1)
       {
       snprintf(dayt, sizeof(dayt), "Pzrts");
        }
       if(days==2)
       {
                snprintf(dayt, sizeof(dayt), "Salı");
          }
       if(days==3)
       {
         snprintf(dayt, sizeof(dayt), "Çrşmb");
         }
       if(days==4)
       {
         snprintf(dayt, sizeof(dayt), "Prşmb");
          }
       if(days==5)
       {
         snprintf(dayt, sizeof(dayt), "Cuma");
          }
       if(days==6)
       {
         snprintf(dayt, sizeof(dayt), "Cmrts");
          }
       if(days==0)
       {
         snprintf(dayt, sizeof(dayt), "Pazar");
          }
    if(ays==0)
      {
      snprintf(ayt, sizeof(ayt), "Ocak");
       }
      if(ays==1)
      {
         snprintf(ayt, sizeof(ayt), "Şubt");
        }
      if(ays==2)
      {
         snprintf(ayt, sizeof(ayt), "Mart");
        }
      if(ays==03)
      {
         snprintf(ayt, sizeof(ayt), "Nisn");
        }
      if(ays==4)
      {
         snprintf(ayt, sizeof(ayt), "Mays");
     }
      if(ays==5)
      {
         snprintf(ayt, sizeof(ayt), "Hzrn");
      }
      if(ays==6)
      {
         snprintf(ayt, sizeof(ayt), "Tmmz");
    }
      if(ays==7)
      {
         snprintf(ayt, sizeof(ayt), "Ağsts");
     }
      if(ays==8)
      {
         snprintf(ayt, sizeof(ayt), "Eyll");
        }
      if(ays==9)
      {
         snprintf(ayt, sizeof(ayt), "Ekim");
         }
      if(ays==10)
      {
         snprintf(ayt, sizeof(ayt), "Kasm");
         }
      if(ays==11)
      {
         snprintf(ayt, sizeof(ayt), "Arlık");
         }
  snprintf(bufftr, sizeof(bufftr), "%s %s %s",ay,ayt,dayt);
     text_layer_set_text(s_timek_layer, bufftr);
}

    
  

static void namazkalan()
  {
      buffer=((Hour[0]-'0')*600)+((Hour[1]-'0')*60)+((Min[0]*10))+Min[1];
    buffer=buffer-528;

       if(buffer<iimsak)
      {
      x=5;
         ttimes=iimsak;
               if(yy!=x){ yy=x;
         snprintf(vakit, sizeof(vakit), "İmsak");
        snprintf(vakitt, sizeof(vakitt),"%s", imsak);
                              text_layer_set_text(s_timev_layer, vakit);
         text_layer_set_text(s_timevt_layer, vakitt);
                 // timer=(imsak[0]-'0')*600+(imsak[1]-'0')*60+(imsak[3]-'0')*10+(imsak[4]-'0');
               }
 
     }
  
     if(buffer>=iimsak)
      {
      x=15;
       ttimes=ggunes;
             //  vakit="Güneş:"; 
      if(yy!=x){
       snprintf(vakit, sizeof(vakit), "Günes");
        snprintf(vakitt, sizeof(vakitt),"%s", gunes);
             text_layer_set_text(s_timev_layer, vakit);
         text_layer_set_text(s_timevt_layer, vakitt);
     yy=x;
      }
    //  timer=(gunes[0]-'0')*600+(gunes[1]-'0')*60+(gunes[3]-'0')*10+(gunes[4]-'0');
 
     }
    
   if(buffer>=ggunes)
      {
      x=25;
     ttimes=oogle;
            //   vakit="Öğle:";
      if(yy!=x){yy=x;
       snprintf(vakit, sizeof(vakit), "Öğle");
      snprintf(vakitt, sizeof(vakitt),"%s", ogle);
                     text_layer_set_text(s_timev_layer, vakit);
         text_layer_set_text(s_timevt_layer, vakitt);
       //  timer=(ogle[0]-'0')*600+(ogle[1]-'0')*60+(ogle[3]-'0')*10+(ogle[4]-'0');
    }
   }
  
 if(buffer>=oogle)
    {
    x=35;
   ttimes=iikindi;
    if(yy!=x){ yy=x;
           //  vakit="İkindi:";
     snprintf(vakit, sizeof(vakit), "İkindi");
    snprintf(vakitt, sizeof(vakitt),"%s", ikindi);
                   text_layer_set_text(s_timev_layer, vakit);
         text_layer_set_text(s_timevt_layer, vakitt);
   //  timer=(ikindi[0]-'0')*600+(ikindi[1]-'0')*60+(ikindi[3]-'0')*10+(ikindi[4]-'0');
  }
 }
  if(buffer>=iikindi)
    {
    x=45;
    ttimes=aaksam;
     if(yy!=x){ yy=x;
            // vakit="Akşam:";
     snprintf(vakit, sizeof(vakit), "Aksam");
    snprintf(vakitt, sizeof(vakitt),"%s", aksam);
                    text_layer_set_text(s_timev_layer, vakit);
         text_layer_set_text(s_timevt_layer, vakitt);
  // timer=(aksam[0]-'0')*600+(aksam[1]-'0')*60+(aksam[3]-'0')*10+(aksam[4]-'0');
  }
  }
 if(buffer>=aaksam)
    {
   ttimes=yyatsi;
    x=55;
   if(yy!=x){ yy=x;
            // vakit="Yatsı:";
     snprintf(vakit, sizeof(vakit), "Yatsı");
    snprintf(vakitt, sizeof(vakitt),"%s", yatsi);
                  text_layer_set_text(s_timev_layer, vakit);
         text_layer_set_text(s_timevt_layer, vakitt);
  // timer=(yatsi[0]-'0')*600+(yatsi[1]-'0')*60+(yatsi[3]-'0')*10+(yatsi[4]-'0');
    }
}
     if(buffer>=yyatsi)
    {
      
    x=65;
       ttimes=iimsak2;
      ctrl=0;
     if(yy!=x){ yy=x;
             // vakit="İmsak:";
       snprintf(vakit, sizeof(vakit), "İmsak");
      snprintf(vakitt, sizeof(vakitt),"%s", imsak2);
                    text_layer_set_text(s_timev_layer, vakit);
         text_layer_set_text(s_timevt_layer, vakitt);
  /*    if(Hour[0]==49)
        {
     timer=(14-(Hour[1]-'0'))*60+60-(((Min[0]-'0')*10)+Min[1])+(imsak[0]-'0')*600+(imsak[1]-'0')*60+(imsak[4]-'0')*10+(imsak[5]-'0')+buffer;}
      else if(Hour[0]==50)
        {timer=(4-(Hour[1]-'0'))*60+60-(((Min[0]-'0')*10)+Min[1])+(imsak[0]-'0')*600+(imsak[1]-'0')*60+(imsak[4]-'0')*10+(imsak[5]-'0')+buffer;}  */
    }
    }

  if(tch==1)
    {
    if(ttimes-buffer>0)
      {
     ttimes=ttimes-buffer;
      }
    else
      {
      ttimes=1440-buffer+ttimes;
     }
  snprintf(ttime, sizeof(ttime),"%02d:%02d (K)", ttimes/60,ttimes%60);
  text_layer_set_text(s_timevt_layer, ttime);
  }
  
 /* timer3=timer-buffer;
  st=timer3/60;
  dk=timer3%60;

snprintf(weather2_layer_buffer, sizeof(weather2_layer_buffer), "%02d:%02d", st, dk);*/
 

}





      static void yazdir()
  {
      if(x==5)
      {

         snprintf(vakit, sizeof(vakit), "İmsak");
        snprintf(vakitt, sizeof(vakitt),"%s", imsak);
                              text_layer_set_text(s_timev_layer, vakit);
         text_layer_set_text(s_timevt_layer, vakitt);

 
     }
  
     if(x==15)
      {
      x=15;

       snprintf(vakit, sizeof(vakit), "Günes");
        snprintf(vakitt, sizeof(vakitt),"%s", gunes);
             text_layer_set_text(s_timev_layer, vakit);
         text_layer_set_text(s_timevt_layer, vakitt);

     }
    
   if(x==25)
      {

       snprintf(vakit, sizeof(vakit), "Öğle");
      snprintf(vakitt, sizeof(vakitt),"%s", ogle);
                     text_layer_set_text(s_timev_layer, vakit);
         text_layer_set_text(s_timevt_layer, vakitt);

   }
  
 if(x==35)
    {
    

     snprintf(vakit, sizeof(vakit), "İkindi");
    snprintf(vakitt, sizeof(vakitt),"%s", ikindi);
                   text_layer_set_text(s_timev_layer, vakit);
         text_layer_set_text(s_timevt_layer, vakitt);
 }
  if(x==45)
    {

     snprintf(vakit, sizeof(vakit), "Aksam");
    snprintf(vakitt, sizeof(vakitt),"%s", aksam);
                    text_layer_set_text(s_timev_layer, vakit);
         text_layer_set_text(s_timevt_layer, vakitt);

  }
 if(x==55)
    {
   
     snprintf(vakit, sizeof(vakit), "Yatsı");
    snprintf(vakitt, sizeof(vakitt),"%s", yatsi);
                  text_layer_set_text(s_timev_layer, vakit);
         text_layer_set_text(s_timevt_layer, vakitt);
}
        

        
  }


static void update_time() {

  // Get a tm structure
  time_t temp = time(NULL); 
  struct tm *tick_time = localtime(&temp);
   strftime(Hour, sizeof("00"), "%H", tick_time);
   strftime(Min, sizeof("00"), "%M", tick_time);
   strftime(Day, sizeof("0"), "%w", tick_time);
          strftime(ay, sizeof("00"), "%d", tick_time);
            strftime(ayg, sizeof("00"), "%m", tick_time);
 
  // Create a long-lived buffer
  static char buffera[] = "00:00";

  // Write the current hours and minutes into the buffer
  if(clock_is_24h_style() == true) {
    //Use 2h hour format
    strftime(buffera, sizeof("00:00"), "%H:%M", tick_time);
  } else {
    //Use 12 hour format
    strftime(buffera, sizeof("00:00"), "%I:%M", tick_time);
  }

  // Display this time on the TextLayer
  text_layer_set_text(s_time_layer, buffera);
  namazkalan();
  
}
void gst()
  {
  if (tod==1)
    {snprintf(gs, sizeof(gs), g1);}
  else if (tod==2)
    {snprintf(gs, sizeof(gs), g1);}
    else if (tod==3)
    {snprintf(gs, sizeof(gs), g1);}
    else if (tod==4)
    {snprintf(gs, sizeof(gs), g1);}
    else if (tod==5)
    {snprintf(gs, sizeof(gs), g1);}
  else if (tod>5)
    {updt=55;}
   
}
void namazsetup()
  {

  gst();
  int u,zmn=99,i2,i,ii,y9;

  
  //elimizdeki 28 günü tek tek analiz edip hangi günün bugün olduğunu bulalım
 for(i = 0; i < 6; i++)
   {
   
    for(u = 0; u < 10; u++)   
   {
      //tarihimiz 10 haneli olduğu için 10 kez dönüyor, tarihi  ise atamayı tick fonksiyonunda datestring üzerinden attık
      i2=u+(i*50);
      tarih[u]=gs[i2];
      i2=i2+10;
      htarih[u]=gs[i2];
      
    }
   //aşşağıda da 28 günün içerisinden sırasıyla seçtiğimiz günleri bugünle karşılaştırıyoruz bugüne eşitse döngüden çıkıyoruz
    if(strncmp(dateString, tarih, 100)==0)
     {
      zmn=i;
      updt=0;
      break;
    }
   else{
     updt++;}
   if(updt!=0&&i==6&&updt!=55)
     {     tod++;
     gst();
     i=0;
     }
   
 }
   
  

  //bugünün bizdeki 28 günden hangisine eşit olduğunu bulduktan sonra da matrisimizde belli sıraya göre dizilmiş olan namaz vakitlerini o sırayı bulacak olan denklemle bulup hafızaya alıyoruz
      for(u = 0; u < 5; u++)
   {
      i2=u+(zmn*50+20);
        ii=u+((zmn+1)*50+20);
      imsak[u]=g1[i2];
        imsak2[u]=g1[ii];
      i2=i2+5;
      gunes[u]=g1[i2];
            i2=i2+5;
      ogle[u]=g1[i2];
              i2=i2+5;
      ikindi[u]=g1[i2];
              i2=i2+5;
      aksam[u]=g1[i2];
            i2=i2+5;
      yatsi[u]=g1[i2];
      
    }
 iimsak= (imsak[0]-'0')*600+(imsak[1]-'0')*60+(imsak[3]-'0')*10+(imsak[4]-'0');
   iimsak2= (imsak2[0]-'0')*600+(imsak2[1]-'0')*60+(imsak2[3]-'0')*10+(imsak2[4]-'0');
  ggunes=(gunes[0]-'0')*600+(gunes[1]-'0')*60+(gunes[3]-'0')*10+(gunes[4]-'0');
  oogle=(ogle[0]-'0')*600+(ogle[1]-'0')*60+(ogle[3]-'0')*10+(ogle[4]-'0');
  iikindi= (ikindi[0]-'0')*600+(ikindi[1]-'0')*60+(ikindi[3]-'0')*10+(ikindi[4]-'0');
  aaksam=(aksam[0]-'0')*600+(aksam[1]-'0')*60+(aksam[3]-'0')*10+(aksam[4]-'0');
  yyatsi=(yatsi[0]-'0')*600+(yatsi[1]-'0')*60+(yatsi[3]-'0')*10+(yatsi[4]-'0');
  hay=(htarih[5]-'0')*10+(htarih[6]-'0');
  hayyg=(htarih[8]-'0')*10+(htarih[9]-'0');
namazkalan();
   tarihsp();

  
}

void hicrisetup()
  {
  
           if(hay==1)
            {
             snprintf(hayy, sizeof(hayy), "Muharrem");
              }
          if(hay==2)
            {
            snprintf(hayy, sizeof(hayy), "Safer");
             }
          if(hay==3)
            {
            snprintf(hayy, sizeof(hayy), "Rebiülevvel");
            }
          if(hay==4)
            {
            snprintf(hayy, sizeof(hayy), "Rebiülahir");
             }
          if(hay==6)
            {
            snprintf(hayy, sizeof(hayy), "Cemaziyelahir");
             }
          if(hay==7)
            {
            snprintf(hayy, sizeof(hayy), "Recep");
             }
          if(hay==8)
            {
            snprintf(hayy, sizeof(hayy), "Şaban");
             }
          if(hay==9)
            {
            snprintf(hayy, sizeof(hayy), "Ramazan");
             }
          if(hay==10)
            {
            snprintf(hayy, sizeof(hayy), "Şevval");
             }
          if(hay==11)
            {
            snprintf(hayy, sizeof(hayy), "Zilkade");
             }
          if(hay==5)
            {
            snprintf(hayy, sizeof(hayy), "Cemaziyelevvel");
             }
          if(hay==12)
            {
            snprintf(hayy, sizeof(hayy), "Zilhicce");
             }
  
  snprintf(buffhtr, sizeof(buffhtr), "%02d %s ",hayyg,hayy);
     text_layer_set_text(s_timek_layer, buffhtr);
  
}


static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
  tch=0;
 persist_delete(G1);
    // Begin dictionary
    DictionaryIterator *iter;
    app_message_outbox_begin(&iter);

    // Add a key-value pair
    dict_write_uint8(iter, 0, 0);

    // Send the message!
    app_message_outbox_send();
  shw=0;
  shw2=0;
  namazkalan();
   yazdir();
  

}
static void up_click_handler(ClickRecognizerRef recognizer, void *context) {


  if(x>55)
    {x=5;}
  else{x=x+10;
      }
  shw=1;
    shw2=1;
  yazdir();

}
static void down_click_handler(ClickRecognizerRef recognizer, void *context) {

if(x!=5)
  {x=x-10;}
  else
    {x=55;}
  shw=1;
    shw2=1;
  yazdir();


}

void select_long_click_handler(ClickRecognizerRef recognizer, void *context) {
  tch=1;
  namazkalan();
  hicrisetup();
 
}
void select_long_click_release_handler(ClickRecognizerRef recognizer, void *context) {
namazkalan();
  tarihsp ();
}

static void click_config_provider(void *context) {
  // Register the ClickHandlers
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
  window_long_click_subscribe(BUTTON_ID_SELECT, 250, select_long_click_handler, select_long_click_release_handler);

  

}




static void main_window_load(Window *window) {
    
  if (persist_exists(G1))
  {
  persist_read_string(G1, g1, sizeof(g1));
     persist_read_string(G2, g2, sizeof(g2));
     persist_read_string(G3, g3, sizeof(g3));
     persist_read_string(G4, g4, sizeof(g4));
     persist_read_string(G5, g5, sizeof(g5));
  }
  
    if (persist_exists(Tch))
  {
  tch=persist_read_int(Tch);
  }
  
  // Create time TextLayer
  s_time_layer = text_layer_create(GRect(0, 0, 144, 49));
  text_layer_set_background_color(s_time_layer, GColorBlack);
  text_layer_set_text_color(s_time_layer, GColorWhite);
  text_layer_set_text(s_time_layer, "00:00");
  
   //Create GFont
  s_time_font = fonts_get_system_font(FONT_KEY_BITHAM_42_MEDIUM_NUMBERS);

  //Apply to TextLayer
  text_layer_set_font(s_time_layer, s_time_font);
  text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);

  // Add it as a child layer to the Window's root layer
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_time_layer));
  
    // Create time TextLayer
  s_timev_layer = text_layer_create(GRect(0, 83, 144, 40));
  text_layer_set_background_color(s_timev_layer, GColorBlack);
  text_layer_set_text_color(s_timev_layer, GColorWhite);
  s_timev_font = fonts_get_system_font(FONT_KEY_DROID_SERIF_28_BOLD);
  text_layer_set_font(s_timev_layer, s_timev_font);
  text_layer_set_text_alignment(s_timev_layer, GTextAlignmentCenter);
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_timev_layer));
  
     // Create time TextLayer
  s_timevt_layer = text_layer_create(GRect(0, 117, 144, 40));
  text_layer_set_background_color(s_timevt_layer, GColorBlack);
  text_layer_set_text_color(s_timevt_layer, GColorWhite);
  text_layer_set_font(s_timevt_layer, s_timev_font);
  text_layer_set_text_alignment(s_timevt_layer, GTextAlignmentCenter);
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_timevt_layer));
   

  // Create second custom font, apply it and add to Window
  s_weather_font = fonts_get_system_font(FONT_KEY_GOTHIC_28_BOLD);

  
  
       s_timek_layer = text_layer_create(GRect(0, 50, 140, 30));
  text_layer_set_background_color(s_timek_layer, GColorClear);
  text_layer_set_text_color(s_timek_layer, GColorBlack);
   text_layer_set_text_alignment(s_timek_layer, GTextAlignmentCenter);
   text_layer_set_font(s_timek_layer, s_weather_font);
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_timek_layer));
  
  
    namazsetup();
  // Make sure the time is displayed from the start
  update_time();
}

static void main_window_unload(Window *window) {
  //Unload GFont
 
  
  // Destroy TextLayer
  text_layer_destroy(s_time_layer);
   text_layer_destroy(s_timev_layer);
   text_layer_destroy(s_timevt_layer);
    text_layer_destroy(s_timek_layer);

  
  // Destroy weather elements

}


static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
 
   strftime(dateString, sizeof(dateString), "%Y-%m-%d", tick_time);  //bugünün tarihi
  update_time();
   if(strncmp(dateString, tarih, 100)!=0)  //bugünün tarihi bizim tarih ile aynı değilse namaz vakitlerini güncelle
     {
     ctrl=0;
     updt++;
    namazsetup();
    }
  // Get weather update every 30 minutes
  if(tick_time->tm_min % 30 == 0||updt!=0) {
    if( bluetooth_connection_service_peek())
      {
  updt=0;
    // Begin dictionary
    DictionaryIterator *iter;
    app_message_outbox_begin(&iter);

    // Add a key-value pair
    dict_write_uint8(iter, 0, 0);

    // Send the message!
    app_message_outbox_send();}
  }
}

static void inbox_received_callback(DictionaryIterator *iterator, void *context) {
  // Store incoming information
 
  
  // Read first item
  Tuple *t = dict_read_first(iterator);

  // For all items
  while(t != NULL) {
    // Which key was received?
    switch(t->key) {
    case G1:
      snprintf(g1, sizeof(g1), "%s", t->value->cstring);
      break;
         case G2:
      snprintf(g2, sizeof(g2), "%s", t->value->cstring);
      break;
         case G3:
      snprintf(g3, sizeof(g3), "%s", t->value->cstring);
      break;
         case G4:
      snprintf(g4, sizeof(g4), "%s", t->value->cstring);
      break;
         case G5:
      snprintf(g5, sizeof(g5), "%s", t->value->cstring);
      break;

    default:
      APP_LOG(APP_LOG_LEVEL_ERROR, "Key %d not recognized!", (int)t->key);
      break;
    }

    // Look for next item
    t = dict_read_next(iterator);
  }
  
  // Assemble full string and display
  persist_write_string(G1, g1);
  persist_write_string(G2, g2);
  persist_write_string(G3, g3);
  persist_write_string(G4, g4);
  persist_write_string(G5, g5);
   namazsetup();
  
}

static void inbox_dropped_callback(AppMessageResult reason, void *context) {
  APP_LOG(APP_LOG_LEVEL_ERROR, "Message dropped!");
}

static void outbox_failed_callback(DictionaryIterator *iterator, AppMessageResult reason, void *context) {
  APP_LOG(APP_LOG_LEVEL_ERROR, "Outbox send failed!");
}

static void outbox_sent_callback(DictionaryIterator *iterator, void *context) {
  APP_LOG(APP_LOG_LEVEL_INFO, "Outbox send success!");
}
  
static void init() {
  // Create main Window element and assign to pointer
  s_main_window = window_create();
 window_set_click_config_provider(s_main_window, click_config_provider);
  // Set handlers to manage the elements inside the Window
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });

  // Show the Window on the watch, with animated=true
  window_stack_push(s_main_window, true);
  
  // Register with TickTimerService
  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
  
  // Register callbacks
  app_message_register_inbox_received(inbox_received_callback);
  app_message_register_inbox_dropped(inbox_dropped_callback);
  app_message_register_outbox_failed(outbox_failed_callback);
  app_message_register_outbox_sent(outbox_sent_callback);
  
  // Open AppMessage
  app_message_open(app_message_inbox_size_maximum(), app_message_outbox_size_maximum());
}

static void deinit() {
  // Destroy Window
    persist_write_string(G1, g1);
   persist_write_string(G2, g2);
   persist_write_string(G3, g3);
   persist_write_string(G4, g4);
   persist_write_string(G5, g5);
  persist_write_int(Tch, tch);
  window_destroy(s_main_window);
  
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
