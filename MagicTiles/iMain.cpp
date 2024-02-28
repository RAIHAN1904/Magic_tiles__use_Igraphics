#include "iGraphics.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <windows.h>
#include "mmsystem.h"

char background[20] = "bg.bmp";
char home[100] = "homepage.bmp";
#define WINDOW_WIDTH 775
#define WINDOW_HEIGHT 700
int p1, p2, p3;

int f = 0;

int num;
char s[10], n[40];

int x = 300, y = 300, r = 20;
int by = 800, cy = 700, dy = 1000, ey = 1100;
int fy = 800, gy = 700, hy = 1000, jy = 1100;
int py = 800, qy = 700, ry = 1000, sy = 1100;
int person = 0;
char sec[1000];
int score = 0;
char name[40];
char playerName[40];
int indexName = 0;
int TilesCount;

void drawhomepage();
void drawStartPage();
void drawEasyPage();
void drawMediumPage();
void drawHardPage();
void drawCreditsPage();
void drawScorepage();
void drawPausepage();
void drawgameOverPage();

void drawInstructionsPage();
void startbuttonClickHandler();
void easybuttonClickHandler();
void mediumButtonClickHandler();
void HardButtonClickHandler();
void backbuttonclickHandler();
void CreditsPageHandler();
void homebuttonHandaler();
void instructionsPageClickHandler();
void scorePageHandler();
void pausePageHandler();
void gameOverpageHandler();
void okbuttonhandler();
void pausetimer();

int startPage = 0;
int homepage = 1;
int easypage = 0;
int mediumpage = 0;
int hardpage = 0;
int creditspage = 0;
int instructionsPage = 0;
int scorepage = 0;
int pausepage = 0;
int gameOverpage = 0;
bool musicOn = true;
int flag = 0;

void iDraw()
{

	iClear();

	if (homepage == 1)
	{
		drawhomepage();
	}

	else if (startPage == 1)
	{ 

		TilesCount = 0;
		by = 800, cy = 700, dy = 1000, ey = 1100;
		fy = 800, gy = 700, hy = 1000, jy = 1100;
		py = 800, qy = 700, ry = 1000, sy = 1100;
		
		drawStartPage();
	}
	else if (creditspage == 1)
	{
		drawCreditsPage();
	}
	else if (instructionsPage == 1)
	{
		drawInstructionsPage();
	}
	else if (easypage == 1)
	{
		drawEasyPage();
	}
	else if (mediumpage == 1)
	{
		drawMediumPage();
	}
	else if (hardpage == 1)
	{
		drawHardPage();
	}
	else if (scorepage == 1)
	{
		drawScorepage();
	}
	else if (pausepage == 1)
	{
		drawPausepage();
	}
	else if (gameOverpage == 1)
	{
		drawgameOverPage();
	}
}

void iMouseMove(int mx, int my)
{

	printf("x = %d, y= %d\n", mx, my);
}

void reduceBy1()
{
	by -= 5;
	cy -= 5;
	dy -= 5;
	ey -= 5;
}
void reduceBy2()
{
	fy -= 10;
	gy -= 10;
	hy -= 10;
	jy -= 10;
}

void reduceBy3()
{
	py -= 15;
	qy -= 15;
	ry -= 15;
	sy -= 15;
}
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		printf("x=%d y=%d ", mx, my);
		if (homepage == 1 && (mx >= 572 && mx <= 636) && (my >= 103 && my <= 124)){
                 exit(1);
		}
		if (homepage == 1 && (mx >= 288 && mx <= 415) && (my >= 433 && my <= 467))
		{
			startbuttonClickHandler();
			PlaySound(TEXT("sounds/Menu_click_sound.wav"), NULL, SND_ASYNC);
		}
		if (homepage == 1 && (mx >= 292 && mx <= 412) && (my >= 293 && my <= 326))
		{
			CreditsPageHandler();
			PlaySound(TEXT("sounds/Menu_click_sound.wav"), NULL, SND_ASYNC);
		}
		if (startPage == 1 && (mx >= 570 && mx <= 635) && (my >= 104 && my <= 125))
		{
			backbuttonclickHandler();
			PlaySound(TEXT("sounds/Menu_click_sound.wav"), NULL, SND_ASYNC);
		}
		if (startPage == 1 && (mx >= 350 && mx <= 444) && (my >= 472 && my <= 498))
		{
			easybuttonClickHandler();
			PlaySound(TEXT("sounds/Menu_click_sound.wav"), NULL, SND_ASYNC);
		}
		if (startPage == 1 && (mx >= 336 && mx <= 463) && (my >= 371 && my <= 403))
		{
			mediumButtonClickHandler();
			PlaySound(TEXT("sounds/Menu_click_sound.wav"), NULL, SND_ASYNC);
		}
		if ((startPage == 1) && (mx >= 348 && mx <= 445) && (my >= 273 && my <= 306))
		{
			HardButtonClickHandler();
			PlaySound(TEXT("sounds/Menu_click_sound.wav"), NULL, SND_ASYNC);
		}
		if (creditspage == 1 | scorepage == 1 | instructionsPage == 1 && (mx >= 570 && mx <= 635) && (my >= 104 && my <= 125))
		{
			backbuttonclickHandler();
			PlaySound(TEXT("sounds/Menu_click_sound.wav"), NULL, SND_ASYNC);
		}
		if (pausepage == 1 && (mx >= 627 && mx <= 736) && (my >= 101 && my <= 131))
		{

			gameOverpageHandler();
			PlaySound(TEXT("sounds/Menu_click_sound.wav"), NULL, SND_ASYNC);
		}
		if (gameOverpage == 1 && (mx >= 431 && mx <= 484) && (my >= 321 && my <= 346))
		{

			okbuttonhandler();
			PlaySound(TEXT("sounds/Menu_click_sound.wav"), NULL, SND_ASYNC);
		}

		if ((easypage == 1) && (mx >= 656 && mx <= 695) && (my >= 148 && my <= 191))
		{
			pausePageHandler();
			PlaySound(TEXT("sounds/Menu_click_sound.wav"), NULL, SND_ASYNC);
			p1 = 1;
			p2 = 0;
			p3 = 0;
		}
		if ((mediumpage == 1) && (mx >= 656 && mx <= 695) && (my >= 148 && my <= 191))
		{
			pausePageHandler();
			PlaySound(TEXT("sounds/Menu_click_sound.wav"), NULL, SND_ASYNC);
			p1 = 1;
			p2 = 0;
			p3 = 0;
		}
		if ((hardpage == 1) && (mx >= 656 && mx <= 695) && (my >= 148 && my <= 191))
		{
			pausePageHandler();
			PlaySound(TEXT("sounds/Menu_click_sound.wav"), NULL, SND_ASYNC);
			p1 = 0;
			p2 = 0;
			p3 = 1;
		}

		if (homepage == 1 && (mx >= 289 && mx <= 409) && (my >= 221 && my <= 256))
		{
			instructionsPageClickHandler();
			PlaySound(TEXT("sounds/Menu_click_sound.wav"), NULL, SND_ASYNC);
		}
		if (homepage == 1 && (mx >= 290 && mx <= 409) && (my >= 361 && my <= 392))
		{
			scorePageHandler();
			PlaySound(TEXT("sounds/Menu_click_sound.wav"), NULL, SND_ASYNC);
		}
		if ((pausepage == 1) && (mx >= 571 && mx <= 654) && (my >= 204 && my <= 222))
		{
			PlaySound(TEXT("sounds/Menu_click_sound.wav"), NULL, SND_ASYNC);
			if (p1 == 1)
			{
				easybuttonClickHandler();
			}
			if (p2 == 1)
			{
				mediumButtonClickHandler();
			}
			if (p3 == 1)
			{
				HardButtonClickHandler();
			}
		}
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		if (easypage == 1 && (mx >= 0 && mx <= 150) && (my >= by && my <= (by + 90)))
		{
			PlaySound(TEXT("sounds/music1.wav"), NULL, SND_ASYNC);
			score += 10;
			by = 800;
		}
		if (easypage == 1 && (mx >= 150 && mx <= 300) && (my >= cy && my <= (cy + 90)))
		{
			PlaySound(TEXT("sounds/music2.wav"), NULL, SND_ASYNC);
			score += 10;
			cy = 700;
		}
		if (easypage == 1 && (mx >= 300 && mx <= 450) && (my >= dy && my <= (dy + 90)))
		{
			PlaySound(TEXT("sounds/music2.wav"), NULL, SND_ASYNC);
			score += 10;
			dy = 1000;
		}
		if (easypage == 1 && (mx >= 450 && mx <= 600) && (my >= ey && my <= (ey + 90)))
		{
			PlaySound(TEXT("sounds/music1.wav"), NULL, SND_ASYNC);
			score += 10;
			ey = 1100;
		}

		if (mediumpage == 1 && (mx >= 0 && mx < 150) && (my >= gy && my <= (gy + 90)))
		{
			PlaySound(TEXT("sounds/music1.wav"), NULL, SND_ASYNC);
			score += 15;
			gy = 700;
		}
		if (mediumpage == 1 && (mx >= 150 && mx < 300) && (my >= fy && my <= (fy + 90)))
		{
			PlaySound(TEXT("sounds/music2.wav"), NULL, SND_ASYNC);
			score += 15;
			fy = 800;
		}
		if (mediumpage == 1 && (mx >= 300 && mx <= 450) && (my >= hy && my <= (hy + 90)))
		{
			PlaySound(TEXT("sounds/music2.wav"), NULL, SND_ASYNC);
			score += 15;
			hy = 1000;
		}
		if (mediumpage == 1 && (mx >= 450 && mx <= 600) && (my >= jy && my <= (jy + 90)))
		{
			PlaySound(TEXT("sounds/music1.wav"), NULL, SND_ASYNC);
			score += 15;
			jy = 1100;
		}

		if (hardpage == 1 && (mx >= 0 && mx <= 150) && (my >= py && my <= (py + 90)))
		{
			PlaySound(TEXT("sounds/music1.wav"), NULL, SND_ASYNC);
			score += 20;
			py = 800;
		}
		if (hardpage == 1 && (mx >= 150 && mx <= 300) && (my >= qy && my <= (qy + 90)))
		{
			PlaySound(TEXT("sounds/music2.wav"), NULL, SND_ASYNC);
			score += 20;
			qy = 700;
		}
		if (hardpage == 1 && (mx >= 300 && mx <= 450) && (my >= ry && my <= (ry + 90)))
		{
			PlaySound(TEXT("sounds/music2.wav"), NULL, SND_ASYNC);
			score += 20;
			ry = 1000;
		}
		if (hardpage == 1 && (mx >= 450 && mx <= 600) && (my >= sy && my <= (sy + 90)))
		{
			PlaySound(TEXT("sounds/music1.wav"), NULL, SND_ASYNC);
			score += 20;
			sy = 1100;
		}

		
	}
}

void iKeyboard(unsigned char key)
{
	if (key == 'q')
	{
		exit(0);
	}
     
	 
	 int len;
     if (key != '\b')
	{
		name[indexName] = key;
		name[indexName + 1] = '\0';
		indexName++;
		//len=strlen(name);
	}
	
	else
	{

		name[indexName] = '\0';
		indexName--;

		if (indexName < 0)
		{
			indexName = 0;
		}
	}
	
}

void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	if (key == GLUT_KEY_UP)
	{
		if (musicOn == true)
		{
			musicOn = false;
			PlaySound(0, 0, 0);
		}
		else
		{
			musicOn = true;
			PlaySound(TEXT("sounds/intro.wav"), NULL, SND_ASYNC);
		}
	}
}

void drawhomepage()
{

	iShowBMP2(0, 0, "homepage.bmp", 0);
	iShowBMP2(260, 500, "magictiles.bmp", 255);

	iShowBMP2(270, 190, "about.bmp", 0);
	iShowBMP2(570, 100, "exit.bmp", 0);
}

void drawStartPage()
{
	iShowBMP(0, 0, "bg.bmp");
	iShowBMP2(120, 210, "level.bmp", 0);
	iShowBMP(135, 315, "indicator.bmp");
	iShowBMP2(570, 100, "back.bmp", 0);
	iShowBMP2(300, 560, "emoji.bmp", 0);

	score = 0;
	// TilesCount=0;
	
}

void drawEasyPage()
{

	iShowBMP(0, 0, "bg.bmp");
	iSetColor(153, 204, 255);
	iFilledRectangle(0, 0, 150, 700);
	iSetColor(204, 229, 255);
	iFilledRectangle(150, 0, 150, 700);
	iSetColor(153, 204, 255);
	iFilledRectangle(300, 0, 150, 700);
	iSetColor(204, 229, 255);
	iFilledRectangle(450, 0, 150, 700);
	iShowBMP(635, 420, "scores.bmp");

	iSetColor(0, 128, 255);
	iFilledRectangle(150, cy, 150, 80);
	iSetColor(255, 255, 255);
	iFilledRectangle(0, by, 150, 80);
	iSetColor(255, 255, 255);
	iFilledRectangle(300, dy, 150, 80);
	iSetColor(0, 128, 255);
	iFilledRectangle(450, ey, 150, 80);
	iSetColor(255, 255, 255);
	iFilledRectangle(645, 380, 80, 30);
	iShowBMP2(655, 145, "pause.bmp", 0);

	if (by <= 5)
	{
		by = 800;
		TilesCount++;
	}
	if (cy <= 5)
	{
		cy = 700;
		TilesCount++;
	}
	if (dy <= 5)
	{
		dy = 1000;
		TilesCount++;
	}
	if (ey <= 5)
	{
		ey = 1100;
		TilesCount++;
	}

	char counterstring[30];
	int remainingTiles = 8;
	remainingTiles = remainingTiles - TilesCount;
	sprintf(sec, "%d", score);
	sprintf(counterstring, "%d", remainingTiles);
	iSetColor(0, 0, 0);

	iText(655, 385, sec, GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255, 255, 255);
	iFilledRectangle(610, 520, 130, 40);
	iSetColor(153, 255, 153);
	iFilledRectangle(645, 470, 65, 30);
	iSetColor(255, 51, 51);
	iText(662, 475, counterstring, GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255, 51, 51);
	iText(615, 535, "Remaining tiles", GLUT_BITMAP_HELVETICA_18);
	if (remainingTiles <= 0)
	{
		gameOverpageHandler();
		remainingTiles = 10;
		TilesCount = 0;
	}
}
void drawMediumPage()
{
	iShowBMP(0, 0, "bg.bmp");
	iSetColor(153, 204, 255);
	iFilledRectangle(0, 0, 150, 700);
	iSetColor(204, 229, 255);
	iFilledRectangle(150, 0, 150, 700);
	iSetColor(153, 204, 255);
	iFilledRectangle(300, 0, 150, 700);
	iSetColor(204, 229, 255);
	iFilledRectangle(450, 0, 150, 700);
	iShowBMP(635, 420, "scores.bmp");

	iSetColor(255, 255, 255);
	iFilledRectangle(150, fy, 150, 80);
	iSetColor(0, 128, 255);
	iFilledRectangle(0, gy, 150, 80);
	iSetColor(0, 128, 255);
	iFilledRectangle(300, hy, 150, 80);
	iSetColor(255, 255, 255);
	iFilledRectangle(450, jy, 150, 80);
	iSetColor(255, 255, 255);
	iFilledRectangle(645, 380, 80, 30);
	iShowBMP2(655, 145, "pause.bmp", 0);

	if (fy <= 5)
	{
		fy = 800;
		TilesCount++;
	}
	if (gy <= 5)
	{
		gy = 700;
		TilesCount++;
	}
	if (hy <= 5)
	{
		hy = 1000;
		TilesCount++;
	}
	if (jy <= 5)
	{
		jy = 1100;
		TilesCount++;
	}

	char counterstring[30];
	int remainingTiles = 8;
	remainingTiles = remainingTiles - TilesCount;
	sprintf(sec, "%d", score);
	sprintf(counterstring, "%d", remainingTiles);
	iSetColor(0, 0, 0);

	iText(655, 385, sec, GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255, 255, 255);
	iFilledRectangle(610, 520, 130, 40);
	iSetColor(153, 255, 153);
	iFilledRectangle(645, 470, 65, 30);
	iSetColor(255, 51, 51);
	iText(662, 475, counterstring, GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255, 51, 51);
	iText(615, 535, "Remaining tiles", GLUT_BITMAP_HELVETICA_18);
	if (remainingTiles <= 0)
	{
		gameOverpageHandler();
		remainingTiles = 10;
		TilesCount = 0;
	}
}

void drawHardPage()
{

	iShowBMP(0, 0, "bg.bmp");
	iSetColor(153, 204, 255);
	iFilledRectangle(0, 0, 150, 700);
	iSetColor(204, 229, 255);
	iFilledRectangle(150, 0, 150, 700);
	iSetColor(153, 204, 255);
	iFilledRectangle(300, 0, 150, 700);
	iSetColor(204, 229, 255);
	iFilledRectangle(450, 0, 150, 700);
	iShowBMP(635, 420, "scores.bmp");

	iSetColor(255, 255, 255);
	iFilledRectangle(150, qy, 150, 80);
	iSetColor(0, 128, 255);
	iFilledRectangle(0, py, 150, 80);
	iSetColor(0, 128, 255);
	iFilledRectangle(300, ry, 150, 80);
	iSetColor(255, 255, 255);
	iFilledRectangle(450, sy, 150, 80);
	iSetColor(255, 255, 255);
	iFilledRectangle(645, 380, 80, 30);
	iShowBMP2(655, 145, "pause.bmp", 0);
	if (py <= 2)
	{
		py = 800;
		TilesCount++;
	}
	if (qy <= 2)
	{
		qy = 700;
		TilesCount++;
	}
	if (ry <= 2)
	{
		ry = 1000;
		TilesCount++;
	}
	if (sy <= 2)
	{
		sy = 1100;
		TilesCount++;
	}

	char counterstring[30];
	int remainingTiles = 8;
	remainingTiles = 8 - TilesCount;
	sprintf(sec, "%d", score);
	sprintf(counterstring, "%d", remainingTiles);
	iSetColor(0, 0, 0);

	iText(655, 385, sec, GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255, 255, 255);
	iFilledRectangle(610, 520, 130, 40);
	iSetColor(153, 255, 153);
	iFilledRectangle(645, 470, 65, 30);
	iSetColor(255, 51, 51);
	iText(662, 475, counterstring, GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255, 51, 51);
	iText(615, 535, "Remaining tiles", GLUT_BITMAP_HELVETICA_18);
	if (remainingTiles <= 0)
	{
		// remainingTiles=10;
		TilesCount = 0;
		gameOverpageHandler();
	}
}
void drawCreditsPage()
{
	iSetColor(255, 225, 255);
	iFilledRectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	iShowBMP2(65, 160, "credit.bmp", 0);
	iShowBMP2(570, 100, "back.bmp", 0);
}

void drawInstructionsPage()
{
	iShowBMP(0, 0, "bg.bmp");
	iShowBMP2(570, 100, "back.bmp", 0);
	iSetColor(0, 0, 0);
	iText(100, 500, " 1.For easy level to click any tiles to gain point 10", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(100, 470, " 2.For medium level to click any tiles to gain point 15", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(100, 440, " 3.For hard level to click any tiles to gain point 20", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(100, 410, " 4.Iitially remaining tiles have only 8", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(100, 310, " 5.If you skip a tiles then remaining tiles will decrease", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(100, 280, " 6.To exit the game click exit button or press 'q' button ", GLUT_BITMAP_TIMES_ROMAN_24);
}
void drawScorepage()
{
	iSetColor(255, 225, 255);
	iFilledRectangle(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	iShowBMP2(570, 100, "back.bmp", 0);

	FILE *fp;
	fp = fopen("savePoint.txt", "r");
	fgets(n, 40, fp);
	fgets(s, 10, fp);

	sscanf(s, "%d", &num);

	// printf("%d %s", num, n);
	// int a;
	// sscanf(sec,"%d",a);

	if (num > score)
	{
		strcpy(playerName, n);
		sprintf(sec, "%d", num);
		fclose(fp);
		// memset(name, '\0', sizeof(name));
	}

	else
	{
		FILE *fpt;
		fpt = fopen("savePoint.txt", "w");
		sprintf(sec, "%d", score);
		fputs(name, fpt);
		fputs("\n", fpt);
		fputs(sec, fpt);
		strcpy(playerName, name);
		fclose(fpt);
	}

	iSetColor(0, 0, 0);
	iText(200, 460, "High Score", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(200, 420, "Player name:", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(350, 420, playerName, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(350, 385, sec, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(200, 385,"Score" , GLUT_BITMAP_TIMES_ROMAN_24);
}
void drawPausepage()
{
	iShowBMP(0, 0, "bg.bmp");
	iShowBMP(200, 400, "tired.bmp");
	iShowBMP(200, 500, "oh_man.bmp");
	iShowBMP2(570, 200, "resume.bmp", 0);
	iShowBMP2(625, 100, "gameOver.bmp", 0);
     
	



}

void drawgameOverPage()
{
	iShowBMP(0, 0, "bg.bmp");
	iSetColor(0, 51, 0);
	iFilledRectangle(200, 300, 300, 200);
	iSetColor(255, 255, 255);
	iText(240, 470, "Your score :", GLUT_BITMAP_HELVETICA_18);
	iSetColor(0, 153, 0);
	iText(230, 425, "Ener your nickname :", GLUT_BITMAP_HELVETICA_18);
	iSetColor(255, 255, 255);
	iFilledRectangle(230, 355, 200, 35);
	iSetColor(153, 255, 153);
	iFilledRectangle(430, 320, 55, 25);
	iSetColor(0, 0, 0);
	iText(440, 325, "OK", GLUT_BITMAP_HELVETICA_18);
	iSetColor(255, 255, 255);
	iText(350, 470, sec, GLUT_BITMAP_HELVETICA_18);
	iSetColor(0, 0, 0);
	iText(235, 370, name, GLUT_BITMAP_HELVETICA_18);
	


}

void easybuttonClickHandler()
{
	homepage = 0;
	startPage = 0;
	easypage = 1;
	instructionsPage = 0;
}
void mediumButtonClickHandler()
{
	homepage = 0;
	startPage = 0;
	easypage = 0;
	mediumpage = 1;
	instructionsPage = 0;
}
void HardButtonClickHandler()
{
	homepage = 0;
	startPage = 0;
	easypage = 0;
	mediumpage = 0;
	hardpage = 1;
	instructionsPage = 0;
}
void startbuttonClickHandler()
{
	homepage = 0;
	startPage = 1;
	creditspage == 0;
	instructionsPage = 0;
	easypage = 0;
	mediumpage = 0;
	hardpage = 0;
	scorepage = 0;
	pausepage = 0;
	gameOverpage = 0;
}
void backbuttonclickHandler()
{
	homepage = 1;
	startPage = 0;
	easypage = 0;
	creditspage = 0;
	instructionsPage = 0;
}
void CreditsPageHandler()
{
	homepage = 0;
	startPage = 0;
	easypage = 0;
	mediumpage = 0;
	hardpage = 0;
	creditspage = 1;
	instructionsPage = 0;
}
void homebuttonHandaler()
{
	homepage = 1;
	startPage = 0;
	easypage = 0;
	mediumpage = 0;
	hardpage = 0;
	creditspage = 0;
	instructionsPage = 0;

	// sprintf(point,"%d",score);
}

void instructionsPageClickHandler()
{
	homepage = 0;
	startPage = 0;
	easypage = 0;
	mediumpage = 0;
	hardpage = 0;
	creditspage = 0;
	instructionsPage = 1;
}
void scorePageHandler()
{
	homepage = 0;
	startPage = 0;
	easypage = 0;
	mediumpage = 0;
	hardpage = 0;
	creditspage = 0;
	instructionsPage = 0;
	scorepage = 1;
}
void pausePageHandler()
{
	homepage = 0;
	startPage = 0;
	easypage = 0;
	mediumpage = 0;
	hardpage = 0;
	creditspage = 0;
	instructionsPage = 0;
	scorepage = 0;
	pausepage = 1;
}
void gameOverpageHandler()
{
	homepage = 0;
	startPage = 0;
	easypage = 0;
	mediumpage = 0;
	hardpage = 0;
	creditspage = 0;
	instructionsPage = 0;
	scorepage = 0;
	pausepage = 0;
	gameOverpage = 1;
	strcpy(name, "");
	indexName = 0;
}
void okbuttonhandler()
{
	homepage = 1;
	startPage = 0;
	easypage = 0;
	mediumpage = 0;
	hardpage = 0;
	creditspage = 0;
	instructionsPage = 0;
	scorepage = 0;
	pausepage = 0;
	gameOverpage = 0;
}

int main()
{
	int i = 0;
	if (homepage == 1)
	{
		PlaySound(TEXT("sounds/intro.wav"), NULL, SND_ASYNC);
	}
	
	iSetTimer(70, reduceBy1);
	iSetTimer(50, reduceBy2);
	iSetTimer(30, reduceBy3);

	iInitialize(WINDOW_WIDTH, WINDOW_HEIGHT, "Magic tiles");

	return 0;
}
