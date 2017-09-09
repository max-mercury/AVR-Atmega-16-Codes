#ifndef buttonlib
#define buttonlib

int buttonPressed(int btn_num,unsigned char pinOfBtn, unsigned char portBit, int conf_lvl);

int pressed[numOfBtn];
int pressed_conf_lvl[numOfBtn];
int released_conf_level[numOfBtn];

int buttonPressed(int btn_num,unsigned char pinOfBtn, unsigned char portBit, int conf_lvl)
{
	if(bit_is_clear(pinOfBtn, portBit))
	{
		pressed_conf_lvl[btn_num]++;
		released_conf_level[btn_num]=0;
		if(pressed_conf_lvl[btn_num] > conf_lvl)
		{
			if(pressed == 0)
			{
				pressed[btn_num] = 1;
				return 1;
			}
			pressed_conf_lvl[btn_num]=0;
		}
	}
	else
	{
		released_conf_level[btn_num]++;
		pressed_conf_lvl[btn_num] = 0;
		if(released_conf_level[btn_num] > conf_lvl)
		{
			pressed[btn_num] = 0;
			released_conf_level[btn_num]=0;
		}
	}
	return 0;
}
#endif
