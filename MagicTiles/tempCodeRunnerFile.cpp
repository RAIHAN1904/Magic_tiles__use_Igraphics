
			p2 = 0;
			p3 = 0;
		}
		if ((mediumpage == 1) && (mx >= 656 && mx <= 695) && (my >= 148 && my <= 191))
		{
			pausePageHandler();
			PlaySound(TEXT("sounds/Menu_click_sound.wav"), NULL, SND_ASYNC);
			p1 = 1;
			p2 = 1;
			p3 = 0;
		}
		if ((hardpage == 1) && (mx >= 656 && mx <=695) && (my >= 148 && my <= 191))
		{
			pausePageHandler();
			PlaySound(TEXT("sounds/Menu_click_sound.wav"), NULL, SND_ASYNC);