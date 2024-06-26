#include<bits/stdc++.h>
#include"iGraphics.h"
using namespace std;
const int screenWidth = 1024;
const int screenHeight = 600;
char background[20] = "im\\Background.bmp";
char gameover[20] = "im\\Game_over.bmp";
void round_one(); // shows the first round
void round_one_letter(); // matches the letter with answer
void round_one_move(int button,int state,int mx,int my); // takes input string
void round_two();// shows the second round
void round_two_letter(); // matches the letter with answer
void round_two_move(int button,int state,int mx,int my);
void round_three(); // shows the three
void round_three_letter(); // matches the letter with answer
void round_three_move(int button,int state,int mx,int my); // takes input string
bool round1 = 1;// checks if it is round one
bool round2 = 0;// checks if it is round two
bool round3 = 0;// checks if it is round three
char point[100]; // stores score
string s1[20] = {""};  //  HOT
string s2[20] = {""};  // LIGHT
string s3[20] = {""}; // LIFE  
char A[20] = {"im\\Aa.bmp"};
char B[20] = {"im\\Bb.bmp"};
char H[20] = {"im\\Hh.bmp"};
char O[20] = {"im\\Oo.bmp"};
char S[20] = {"im\\Ss.bmp"};
char T[20] = {"im\\Tt.bmp"};
char E[20] = {"im\\Ee.bmp"};
char R[20] = {"im\\Rr.bmp"};
char F[20] = {"im\\ff.bmp"};
char sr[20] = {"im\\black.bmp"};
char L[20] = {"im\\Ll.bmp"};
char G[20] = {"im\\Gg.bmp"};
char I[20] = {"im\\Ii.bmp"};
char Life[20] = {"im\\life.bmp"};
char hot[20] = {"im\\hot.bmp"};
char Light[20] = {"im\\light.bmp"};
bool game_state = 0;
int score = 0;
char Alphabets[30][30] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
int index = -1;
int r1letter1=0,r1letter2=0,r1letter3=0; // flags for each letter in round one
int r1letter1_id =-1,r1letter2_id =-1,r1letter3_id =-1; // stores index for each letter in round one
int r2letter1=0,r2letter2=0,r2letter3=0,r2letter4=0,r2letter5=0; // flags for each letter in round two
int r2letter1_id =-1,r2letter2_id =-1,r2letter3_id =-1,r2letter4_id =-1,r2letter5_id =-1; // stores index for each letter in round two
int r3letter1=0,r3letter2=0,r3letter3=0,r3letter4=0; // flags for each letter in round three
int r3letter1_id =-1,r3letter2_id =-1,r3letter3_id =-1,r3letter4_id=-1; // // stores index for each letter in round three
string ans1 = "HOT";
string ans2 = "LIGHT";
string ans3 = "LIFE";
int get1 = 0; // flag to start round two
int get2 = 0; // flag to start round three
int get3 = 0; // flag to start next round
void round_one(){
    iShowBMP2(100,200,A,0); iShowBMP2(180,200,B,0);
    iShowBMP2(260,200,H,0); iShowBMP2(340,200,O,0);
    iShowBMP2(100,100,S,0); iShowBMP2(180,100,T,0);
    iShowBMP2(260,100,E,0); iShowBMP2(340,100,R,0);
    iShowBMP2(600,266,hot,0);
}
void round_two(){
    iShowBMP2(100,200,A,0); iShowBMP2(180,200,B,0);
    iShowBMP2(340,100,R,0); iShowBMP2(260,200,H,0);
    iShowBMP2(180,100,T,0); iShowBMP2(260,100,L,0);
    iShowBMP2(340,200,G,0); iShowBMP2(100,100,I,0);
    iShowBMP2(555,266,Light,0);
}
void round_three(){
    iShowBMP2(100,200,A,0); iShowBMP2(180,200,B,0);
    iShowBMP2(260,200,F,0); iShowBMP2(340,200,O,0);
    iShowBMP2(100,100,S,0); iShowBMP2(180,100,L,0);
    iShowBMP2(260,100,E,0); iShowBMP2(340,100,I,0);
    iShowBMP2(600,300,Life,0);
}
void round_one_letter(){ // prints output & result for round 1
    if(r1letter1){
        iText(808,100,Alphabets[r1letter1_id],GLUT_BITMAP_TIMES_ROMAN_24);
        //686 
    }
    if(r1letter2){
        iText(828,100,Alphabets[r1letter2_id],GLUT_BITMAP_TIMES_ROMAN_24);
        //706
    }
    if(r1letter3){
        iText(850,100,Alphabets[r1letter3_id],GLUT_BITMAP_TIMES_ROMAN_24);
        // 728
    }
    if(s1[0].size()==ans1.size()){
        if(s1[0][0]==ans1[0]&&s1[0][1]==ans1[1]&&s1[0][2]==ans1[2]){
        iText(220,320,"CORRECT ANSWER",GLUT_BITMAP_TIMES_ROMAN_24);
        get1 = 1;
        score=10;
        }
        else{
        iText(220,320,"WRONG ANSWER",GLUT_BITMAP_TIMES_ROMAN_24);
        get3 = 1;
        }
    }
}
void round_two_letter(){
    if(r2letter1){
        iText(808,100,Alphabets[r2letter1_id],GLUT_BITMAP_TIMES_ROMAN_24);
        //686
    }
    if(r2letter2){
        iText(828,100,Alphabets[r2letter2_id],GLUT_BITMAP_TIMES_ROMAN_24);
        //706
    }
    if(r2letter3){
        iText(844,100,Alphabets[r2letter3_id],GLUT_BITMAP_TIMES_ROMAN_24);
        //722
    }
    if(r2letter4){
        iText(867,100,Alphabets[r2letter4_id],GLUT_BITMAP_TIMES_ROMAN_24);
        //745
    }
    if(r2letter5){
        iText(888,100,Alphabets[r2letter5_id],GLUT_BITMAP_TIMES_ROMAN_24);
        //766
    }
    if(s2[0].size()==ans2.size()){
        if(s2[0][0]==ans2[0]&&s2[0][1]==ans2[1]&&s2[0][2]==ans2[2]&&s2[0][3]==ans2[3]&&s2[0][4]==ans2[4]){
        iText(220,320,"CORRECT ANSWER",GLUT_BITMAP_TIMES_ROMAN_24);
        get2 = 1;
        score = 20;
        }
        else{
        iText(220,320,"WRONG ANSWER",GLUT_BITMAP_TIMES_ROMAN_24);
        get3 = 1;
        }
        }
}
void round_three_letter(){
    if(r3letter1){
        iText(808,100,Alphabets[r3letter1_id],GLUT_BITMAP_TIMES_ROMAN_24);
        // 686
    }
    if(r3letter2){
        iText(828,100,Alphabets[r3letter2_id],GLUT_BITMAP_TIMES_ROMAN_24);
        //706
    }
    if(r3letter3){
        iText(848,100,Alphabets[r3letter3_id],GLUT_BITMAP_TIMES_ROMAN_24);
        //720
    }
    if(r3letter4){
        iText(868,100,Alphabets[r3letter4_id],GLUT_BITMAP_TIMES_ROMAN_24);
        //736
    }
    if(s3[0].size()==ans3.size()){
        if(s3[0][0]==ans3[0]&&s3[0][1]==ans3[1]&&s3[0][2]==ans3[2]&&s3[0][3]==ans3[3]){
        iText(220,320,"CORRECT ANSWER",GLUT_BITMAP_TIMES_ROMAN_24);
        score = 30;
        }
        else{
        iText(220,320,"WRONG ANSWER",GLUT_BITMAP_TIMES_ROMAN_24);
        get3 = 1;
        }
    }
} 
void round_one_move(int button,int state,int mx,int my){
if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN){
        if(mx>100&&mx<180&&my>=200&&my<=280){
            // for A
            if(r1letter1==0){
                r1letter1 = 1;
                r1letter1_id = 'a'-'a';
                s1[0].push_back(Alphabets[r1letter1_id][0]);
            }else if(r1letter2==0){
                r1letter2 = 1;
                r1letter2_id = 'a'-'a';
                s1[0].push_back(Alphabets[r1letter2_id][0]);
            }else if(r1letter3==0){
                r1letter3 = 1;
                r1letter3_id = 'a'-'a';
                s1[0].push_back(Alphabets[r1letter3_id][0]);
            }
            
        }else if(mx>260&&mx<340&&my>=200&&my<=280){
            // for H
            if(r1letter1==0){
                r1letter1 = 1;
                r1letter1_id = 'h' - 'a';
                s1[0].push_back(Alphabets[r1letter1_id][0]);
            }else if(r1letter2==0){
                r1letter2 = 1;
                r1letter2_id = 'h' - 'a';
                s1[0].push_back(Alphabets[r1letter2_id][0]);
            }else if(r1letter3==0){
                r1letter3 = 1;
                r1letter3_id = 'h' - 'a';
                s1[0].push_back(Alphabets[r1letter3_id][0]);
            }
            
        }else if(mx>340&&mx<420&&my>=200&&my<=280){
            // for O
            if(r1letter1==0){
                r1letter1 = 1;
                r1letter1_id = 'o'-'a';
                s1[0].push_back(Alphabets[r1letter1_id][0]);
            }else if(r1letter2==0){
                r1letter2 = 1;
                r1letter2_id = 'o'-'a';
                s1[0].push_back(Alphabets[r1letter2_id][0]);
            }else if(r1letter3==0){
                r1letter3 = 1;
                r1letter3_id = 'o'-'a';
                s1[0].push_back(Alphabets[r1letter3_id][0]);
            }   
        }else if(mx>180&&mx<260&&my>=100&&my<=180){
            // for T
            if(r1letter1==0){
                r1letter1 = 1;
                r1letter1_id = 't'-'a';
                s1[0].push_back(Alphabets[r1letter1_id][0]);
            }else if(r1letter2==0){
                r1letter2 = 1;
                r1letter2_id = 't'-'a';
                s1[0].push_back(Alphabets[r1letter2_id][0]);
            }else if(r1letter3==0){
                r1letter3 = 1;
                r1letter3_id = 't'-'a';
                s1[0].push_back(Alphabets[r1letter3_id][0]);
            }   
        }else if(mx>340&&mx<420&&my>=100&&my<=180){
            // for R
            if(r1letter1==0){
                r1letter1 = 1;
                r1letter1_id = 'r'-'a';
                s1[0].push_back(Alphabets[r1letter1_id][0]);
            }else if(r1letter2==0){
                r1letter2 = 1;
                r1letter2_id = 'r'-'a';
                s1[0].push_back(Alphabets[r1letter2_id][0]);
            }else if(r1letter3==0){
                r1letter3 = 1;
                r1letter3_id = 'r'-'a';
                s1[0].push_back(Alphabets[r1letter3_id][0]);
            }   
        }else if(mx>100&&mx<=180&&my>=100&&my<=180){
            // for S
            if(r1letter1==0){
                r1letter1 = 1;
                r1letter1_id = 's'-'a';
                s1[0].push_back(Alphabets[r1letter1_id][0]);
            }else if(r1letter2==0){
                r1letter2 = 1;
                r1letter2_id = 's'-'a';
                s1[0].push_back(Alphabets[r1letter2_id][0]);
            }else if(r1letter3==0){
                r1letter3 = 1;
                r1letter3_id = 's'-'a';
                s1[0].push_back(Alphabets[r1letter3_id][0]);
            }   
        }else if(mx>260&&mx<340&&my>100&&my<160){
            // for E
            if(r1letter1==0){
                r1letter1 = 1;
                r1letter1_id = 'e'-'a';
                s1[0].push_back(Alphabets[r1letter1_id][0]);
            }else if(r1letter2==0){
                r1letter2 = 1;
                r1letter2_id = 'e'-'a';
                s1[0].push_back(Alphabets[r1letter2_id][0]);
            }else if(r1letter3==0){
                r1letter3 = 1;
                r1letter3_id = 'e'-'a';
                s1[0].push_back(Alphabets[r1letter3_id][0]);
            }   
        }else if(mx>180&&mx<260&&my>=200&&my<=280){
            // for B
            if(r1letter1==0){
                r1letter1 = 1;
                r1letter1_id = 'b'-'a';
                s1[0].push_back(Alphabets[r1letter1_id][0]);
            }else if(r1letter2==0){
                r1letter2 = 1;
                r1letter2_id = 'b'-'a';
                s1[0].push_back(Alphabets[r1letter2_id][0]);
            }else if(r1letter3==0){
                r1letter3 = 1;
                r1letter3_id = 'b'-'a';
                s1[0].push_back(Alphabets[r1letter3_id][0]);
            }   
        }
    }
}
void round_one_click(int button,int state,int mx,int my){
    if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN){
        if(mx>0&&my>0){ // Takes a click from the user after round one
            round1 = 0;
            round2 = 1;
        }
    }
}
void round_two_move(int button,int state,int mx,int my){
    if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN){
        if(mx>100&&mx<180&&my>=200&&my<=280){
            // for A
            if(r2letter1==0){
                r2letter1 = 1;
                r2letter1_id = 'a'-'a';
                s2[0].push_back(Alphabets[r2letter1_id][0]);
            }else if(r2letter2==0){
                r2letter2 = 1;
                r2letter2_id = 'a'-'a';
                s2[0].push_back(Alphabets[r2letter2_id][0]);
            }else if(r2letter3==0){
                r2letter3 = 1;
                r2letter3_id = 'a'-'a';
                s2[0].push_back(Alphabets[r2letter3_id][0]);
            }else if(r2letter4==0){
                r2letter4 = 1;
                r2letter4_id = 'a'-'a';
                s2[0].push_back(Alphabets[r2letter4_id][0]);
            }else if(r2letter5==0){
                r2letter5 = 1;
                r2letter5_id = 'a'-'a';
                s2[0].push_back(Alphabets[r2letter5_id][0]);
            }
        }else if(mx>260&&mx<340&&my>=200&&my<=280){
             // for H
            if(r2letter1==0){
                r2letter1 = 1;
                r2letter1_id = 'h'-'a';
                s2[0].push_back(Alphabets[r2letter1_id][0]);
            }else if(r2letter2==0){
                r2letter2 = 1;
                r2letter2_id = 'h'-'a';
                s2[0].push_back(Alphabets[r2letter2_id][0]);
            }else if(r2letter3==0){
                r2letter3 = 1;
                r2letter3_id = 'h'-'a';
                s2[0].push_back(Alphabets[r2letter3_id][0]);
            }else if(r2letter4==0){
                r2letter4 = 1;
                r2letter4_id = 'h'-'a';
                s2[0].push_back(Alphabets[r2letter4_id][0]);
            }else if(r2letter5==0){
                r2letter5 = 1;
                r2letter5_id = 'h'-'a';
                s2[0].push_back(Alphabets[r2letter5_id][0]);
            }
        }else if(mx>180&&mx<260&&my>=200&&my<=280){
            // for B
            if(r2letter1==0){
                r2letter1 = 1;
                r2letter1_id = 'b'-'a';
                s2[0].push_back(Alphabets[r2letter1_id][0]);
            }else if(r2letter2==0){
                r2letter2 = 1;
                r2letter2_id = 'b'-'a';
                s2[0].push_back(Alphabets[r2letter2_id][0]);
            }else if(r2letter3==0){
                r2letter3 = 1;
                r2letter3_id = 'b'-'a';
                s2[0].push_back(Alphabets[r2letter3_id][0]);
            }else if(r2letter4==0){
                r2letter4 = 1;
                r2letter4_id = 'b'-'a';
                s2[0].push_back(Alphabets[r2letter4_id][0]);
            }else if(r2letter5==0){
                r2letter5 = 1;
                r2letter5_id = 'b'-'a';
                s2[0].push_back(Alphabets[r2letter5_id][0]);
            }
        }else if(mx>180&&mx<260&&my>=100&&my<=180){
            // for T
            if(r2letter1==0){
                r2letter1 = 1;
                r2letter1_id = 't'-'a';
                s2[0].push_back(Alphabets[r2letter1_id][0]);
            }else if(r2letter2==0){
                r2letter2 = 1;
                r2letter2_id = 't'-'a';
                s2[0].push_back(Alphabets[r2letter2_id][0]);
            }else if(r2letter3==0){
                r2letter3 = 1;
                r2letter3_id = 't'-'a';
                s2[0].push_back(Alphabets[r2letter3_id][0]);
            }else if(r2letter4==0){
                r2letter4 = 1;
                r2letter4_id = 't'-'a';
                s2[0].push_back(Alphabets[r2letter4_id][0]);
            }else if(r2letter5==0){
                r2letter5 = 1;
                r2letter5_id = 't'-'a';
                s2[0].push_back(Alphabets[r2letter5_id][0]);
            }
        }else if(mx>340&&mx<420&&my>=100&&my<=180){
            //For R
            if(r2letter1==0){
                r2letter1 = 1;
                r2letter1_id = 'r'-'a';
                s2[0].push_back(Alphabets[r2letter1_id][0]);
            }else if(r2letter2==0){
                r2letter2 = 1;
                r2letter2_id = 'r'-'a';
                s2[0].push_back(Alphabets[r2letter2_id][0]);
            }else if(r2letter3==0){
                r2letter3 = 1;
                r2letter3_id = 'r'-'a';
                s2[0].push_back(Alphabets[r2letter3_id][0]);
            }else if(r2letter4==0){
                r2letter4 = 1;
                r2letter4_id = 'r'-'a';
                s2[0].push_back(Alphabets[r2letter4_id][0]);
            }else if(r2letter5==0){
                r2letter5 = 1;
                r2letter5_id = 'r'-'a';
                s2[0].push_back(Alphabets[r2letter5_id][0]);
            }
        }else if(mx>260&&mx<340&&my>100&&my<160){
            if(r2letter1==0){
                r2letter1 = 1;
                r2letter1_id = 'l'-'a';
                s2[0].push_back(Alphabets[r2letter1_id][0]);
            }else if(r2letter2==0){
                r2letter2 = 1;
                r2letter2_id = 'l'-'a';
                s2[0].push_back(Alphabets[r2letter2_id][0]);
            }else if(r2letter3==0){
                r2letter3 = 1;
                r2letter3_id = 'l'-'a';
                s2[0].push_back(Alphabets[r2letter3_id][0]);
            }else if(r2letter4==0){
                r2letter4 = 1;
                r2letter4_id = 'l'-'a';
                s2[0].push_back(Alphabets[r2letter4_id][0]);
            }else if(r2letter5==0){
                r2letter5 = 1;
                r2letter5_id = 'l'-'a';
                s2[0].push_back(Alphabets[r2letter5_id][0]);
            }
        }else if(mx>340&&mx<420&&my>=200&&my<=280){
            if(r2letter1==0){
                r2letter1 = 1;
                r2letter1_id = 'g'-'a';
                s2[0].push_back(Alphabets[r2letter1_id][0]);
            }else if(r2letter2==0){
                r2letter2 = 1;
                r2letter2_id = 'g'-'a';
                s2[0].push_back(Alphabets[r2letter2_id][0]);
            }else if(r2letter3==0){
                r2letter3 = 1;
                r2letter3_id = 'g'-'a';
                s2[0].push_back(Alphabets[r2letter3_id][0]);
            }else if(r2letter4==0){
                r2letter4 = 1;
                r2letter4_id = 'g'-'a';
                s2[0].push_back(Alphabets[r2letter4_id][0]);
            }else if(r2letter5==0){
                r2letter5 = 1;
                r2letter5_id = 'g'-'a';
                s2[0].push_back(Alphabets[r2letter5_id][0]);
            }
        }else if(mx>100&&mx<=180&&my>=100&&my<=180){
            if(r2letter1==0){
                r2letter1 = 1;
                r2letter1_id = 'i'-'a';
                s2[0].push_back(Alphabets[r2letter1_id][0]);
            }else if(r2letter2==0){
                r2letter2 = 1;
                r2letter2_id = 'i'-'a';
                s2[0].push_back(Alphabets[r2letter2_id][0]);
            }else if(r2letter3==0){
                r2letter3 = 1;
                r2letter3_id = 'i'-'a';
                s2[0].push_back(Alphabets[r2letter3_id][0]);
            }else if(r2letter4==0){
                r2letter4 = 1;
                r2letter4_id = 'i'-'a';
                s2[0].push_back(Alphabets[r2letter4_id][0]);
            }else if(r2letter5==0){
                r2letter5 = 1;
                r2letter5_id = 'i'-'a';
                s2[0].push_back(Alphabets[r2letter5_id][0]);
            }
        }
    }
}
void round_two_click(int button,int state,int mx,int my){
    if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN){
        if(mx>0&&my>0){ // Takes a click from the user after round two
            round2 = 0; 
            round3 = 1;
        }
    }
}
void round_three_move(int button,int state,int mx,int my){
    if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN){
        if(mx>100&&mx<180&&my>=200&&my<=280){
            // for A
            if(r3letter1==0){
                r3letter1 = 1;
                r3letter1_id = 'a'-'a';
                s3[0].push_back(Alphabets[r3letter1_id][0]);
            }else if(r3letter2==0){
                r3letter2 = 1;
                r3letter2_id = 'a'-'a';
                s3[0].push_back(Alphabets[r3letter2_id][0]);
            }else if(r3letter3==0){
                r3letter3 = 1;
                r3letter3_id = 'a'-'a';
                s3[0].push_back(Alphabets[r3letter3_id][0]);
            }else if(r3letter4==0){
                r3letter4 = 1;
                r3letter4_id = 'a'-'a';
                s3[0].push_back(Alphabets[r3letter4_id][0]);
            }
            
        }else if(mx>260&&mx<340&&my>=200&&my<=280){
            // for F
            if(r3letter1==0){
                r3letter1 = 1;
                r3letter1_id = 'f' - 'a';
                s3[0].push_back(Alphabets[r3letter1_id][0]);
            }else if(r3letter2==0){
                r3letter2 = 1;
                r3letter2_id = 'f' - 'a';
                s3[0].push_back(Alphabets[r3letter2_id][0]);
            }else if(r3letter3==0){
                r3letter3 = 1;
                r3letter3_id = 'f' - 'a';
                s3[0].push_back(Alphabets[r3letter3_id][0]);
            }else if(r3letter4==0){
                r3letter4 = 1;
                r3letter4_id = 'f'-'a';
                s3[0].push_back(Alphabets[r3letter4_id][0]);
            }
            
        }else if(mx>340&&mx<420&&my>=200&&my<=280){
            // for O
            if(r3letter1==0){
                r3letter1 = 1;
                r3letter1_id = 'o'-'a';
                s3[0].push_back(Alphabets[r3letter1_id][0]);
            }else if(r3letter2==0){
                r3letter2 = 1;
                r3letter2_id = 'o'-'a';
                s3[0].push_back(Alphabets[r3letter2_id][0]);
            }else if(r3letter3==0){
                r3letter3 = 1;
                r3letter3_id = 'o'-'a';
                s3[0].push_back(Alphabets[r3letter3_id][0]);
            }else if(r3letter4==0){
                r3letter4 = 1;
                r3letter4_id = 'o'-'a';
                s3[0].push_back(Alphabets[r3letter4_id][0]);
            }   
        }else if(mx>180&&mx<260&&my>=100&&my<=180){
            // for L
            if(r3letter1==0){
                r3letter1 = 1;
                r3letter1_id = 'l'-'a';
                s3[0].push_back(Alphabets[r3letter1_id][0]);
            }else if(r3letter2==0){
                r3letter2 = 1;
                r3letter2_id = 'l'-'a';
                s3[0].push_back(Alphabets[r3letter2_id][0]);
            }else if(r3letter3==0){
                r3letter3 = 1;
                r3letter3_id = 'l'-'a';
                s3[0].push_back(Alphabets[r3letter3_id][0]);
            }else if(r3letter4==0){
                r3letter4 = 1;
                r3letter4_id = 'l'-'a';
                s3[0].push_back(Alphabets[r3letter4_id][0]);
            }   
        }else if(mx>340&&mx<420&&my>=100&&my<=180){
            // for I
            if(r3letter1==0){
                r3letter1 = 1;
                r3letter1_id = 'i'-'a';
                s3[0].push_back(Alphabets[r3letter1_id][0]);
            }else if(r3letter2==0){
                r3letter2 = 1;
                r3letter2_id = 'i'-'a';
                s3[0].push_back(Alphabets[r3letter2_id][0]);
            }else if(r3letter3==0){
                r3letter3 = 1;
                r3letter3_id = 'i'-'a';
                s3[0].push_back(Alphabets[r3letter3_id][0]);
            }else if(r3letter4==0){
                r3letter4 = 1;
                r3letter4_id = 'i'-'a';
                s3[0].push_back(Alphabets[r3letter4_id][0]);
            }   
        }else if(mx>100&&mx<=180&&my>=100&&my<=180){
            // for S
            if(r3letter1==0){
                r3letter1 = 1;
                r3letter1_id = 's'-'a';
                s3[0].push_back(Alphabets[r3letter1_id][0]);
            }else if(r3letter2==0){
                r3letter2 = 1;
                r3letter2_id = 's'-'a';
                s3[0].push_back(Alphabets[r3letter2_id][0]);
            }else if(r3letter3==0){
                r3letter3 = 1;
                r3letter3_id = 's'-'a';
                s3[0].push_back(Alphabets[r3letter3_id][0]);
            }else if(r3letter4==0){
                r3letter4 = 1;
                r3letter4_id = 's'-'a';
                s3[0].push_back(Alphabets[r3letter4_id][0]);
            }   
        }else if(mx>260&&mx<340&&my>100&&my<160){
            // for E
            if(r3letter1==0){
                r3letter1 = 1;
                r3letter1_id = 'e'-'a';
                s3[0].push_back(Alphabets[r3letter1_id][0]);
            }else if(r3letter2==0){
                r3letter2 = 1;
                r3letter2_id = 'e'-'a';
                s3[0].push_back(Alphabets[r3letter2_id][0]);
            }else if(r3letter3==0){
                r3letter3 = 1;
                r3letter3_id = 'e'-'a';
                s3[0].push_back(Alphabets[r3letter3_id][0]);
            }else if(r3letter4==0){
                r3letter4 = 1;
                r3letter4_id = 'e'-'a';
                s3[0].push_back(Alphabets[r3letter4_id][0]);
            }   
        }else if(mx>180&&mx<260&&my>=200&&my<=280){
            // for B
            if(r3letter1==0){
                r3letter1 = 1;
                r3letter1_id = 'b'-'a';
                s3[0].push_back(Alphabets[r3letter1_id][0]);
            }else if(r3letter2==0){
                r3letter2 = 1;
                r3letter2_id = 'b'-'a';
                s3[0].push_back(Alphabets[r3letter2_id][0]);
            }else if(r3letter3==0){
                r3letter3 = 1;
                r3letter3_id = 'b'-'a';
                s3[0].push_back(Alphabets[r3letter3_id][0]);
            }else if(r3letter4==0){
                r3letter4 = 1;
                r3letter4_id = 'b'-'a';
                s3[0].push_back(Alphabets[r3letter4_id][0]);
            }   
        }
    }
}
void wrong_answer_click(int button,int state,int mx,int my){
    if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN){
        if(mx>0&&my>0){ // Takes a click from the user if the answer is wrong
        get3 = 0;
        game_state = 1;
        }
    }
}

void iDraw(){
    iClear();
    if(game_state==0){
    iShowBMP(0,0,background);
    iShowBMP2(788,80,sr,0);
    iText(600,200,"SCORE : ",GLUT_BITMAP_TIMES_ROMAN_24);
    sprintf(point,"%d",score);
    iText(700,200,point,GLUT_BITMAP_TIMES_ROMAN_24);
    
    if(round1){
        round_one();
        round_one_letter();
    }
    if(round2){
        get1 = 0;
        round_two();
        round_two_letter();
    }
    if(round3){
        get2 = 0;
        round_three();
        round_three_letter();
    }
    }
    if(game_state==1){
        iShowBMP(0,0,gameover);
    }
}
void iKeyboard(unsigned char key){
    iClear();
}
void iSpecialKeyboard(unsigned char key){
    iClear();    
    if(key==GLUT_KEY_UP){
        
    }else if(key==GLUT_KEY_DOWN){

    }else if(key==GLUT_KEY_LEFT){
        
    }else if(key==GLUT_KEY_RIGHT){
        
    }
}
void iMouseMove(int x,int y){
    iClear();
}

void iMouse(int button,int state,int mx,int my){
    iClear();
    if(round1){
        round_one_move(button,state,mx,my);
    }
    if(get1){
        round_one_click(button,state,mx,my);
    }
    if(round2){
        round_two_move(button,state,mx,my);
    }
    if(get2){
        round_two_click(button,state,mx,my);
    }
    if(round3){
        round_three_move(button,state,mx,my);
    }
    if(get3){
        wrong_answer_click(button,state,mx,my);
    }
    if(button==GLUT_RIGHT_BUTTON&&state==GLUT_UP){

    }
}
int main(){
    iInitialize(screenWidth,screenHeight,"Level Three");
    
    return 0;
}