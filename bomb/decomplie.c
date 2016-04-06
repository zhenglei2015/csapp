
int phase_2() {
	int num[6];
	read_six_nums(num);
	if(num[0] == 1) {
		int* cursor = num[1];
		do{
			int *before = cursor - 1;
			if(*before != *cursor + *cuisor)
				exploade_bomb();
		}while(++cursor <= num[6])
	} else {
		explode_bomb();	
	}
}
