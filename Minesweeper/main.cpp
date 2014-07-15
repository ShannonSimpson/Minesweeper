#include "Header.h"
 
int main()
{
    int wait=0;
    int iDigit;
    int extra1 = 0;
    int extra2 = 0;
    char character1;
    char character2;
    char character3;
    char flag = 'n';
    int num = 1;
    int x;
    int y;
    int count = 30;
    char temp;

    srand (time(NULL));
   
	//list of vectors
    vector<char>cover;
    vector<int>numbers;
    vector<int>wait_counter;
    vector<int>mines;
    vector<char>chars;
 
	//flag='n';

    for(int i=0; i<261; i++)
    {
        wait_counter.push_back(0);
        numbers.push_back(0);  //mine locations
        mines.push_back(0);  //loads mines
        chars.push_back('0');  //empty location
        cover.push_back('+');  ////the board
    }
    cout<<"\n";
   
   
    for(int i=0; i<count; i++)
    {
        x = rand();  //random
        y = x%260 + 1;
       
        if(mines[y]==0)
        {
                mines[y]=1;
        }
        else
        {
            i--;
        }
    }    
   
   
   
   
    for(int i=0; i<261; i++)
    {
        if(mines[i]!=0)
		{
            chars[i]='M';
		}
    }
   
   
    x = 0;
   
    if(chars[1]!='M')   //top left
    {
        if(chars[2]=='M')
        {
            numbers[1]++;
        }
        if(chars[27]=='M')
        {
            numbers[1]++;
        }
        if(chars[28]=='M')
        {
            numbers[1]++;
        }
    }
   
    if(chars[26]!='M')  //top right
    {
        if(chars[25]=='M')
        {
            numbers[26]++;
        }
        if(chars[51]=='M')
        {
            numbers[26]++;
        }
        if(chars[52]=='M')
        {
            numbers[26]++;
        }
    }
   
    if(chars[235]!='M') //bottom left
    {
        if(chars[209]=='M')
        {
            numbers[235]++;
        }
        if(chars[210]=='M')
        {
            numbers[235]++;
        }
        if(chars[236]=='M')
        {
            numbers[235]++;
        }
    }
   
    if(chars[260]!='M') //bottom right
    {
        if(chars[233]=='M')
        {
            numbers[260]++;
        }
        if(chars[234]=='M')
        {
            numbers[260]++;
        }
        if(chars[259]=='M')
        {
            numbers[260]++;

        }
    }
   
    for(int i=2; i<26; i++)   //top
    {
        if(chars[i]!='M')
        {
            if(chars[i-1]=='M')
			{
                numbers[i]++;
			}
            if(chars[i+1]=='M')
			{
                numbers[i]++;
			}
            if(chars[i+25]=='M')
			{
                numbers[i]++;
			}
            if(chars[i+26]=='M')
			{
                numbers[i]++;
			}
            if(chars[i+27]=='M')
			{
                numbers[i]++;
			}
        }
    }
   
    for(int i=236; i<260; i++)   //bottom
    {
        if(chars[i]!='M')
        {
            if(chars[i-1]=='M')
			{
                numbers[i]++;
			}
            if(chars[i+1]=='M')
			{
                numbers[i]++;
			}
            if(chars[i-25]=='M')
			{
				numbers[i]++;
			}
            if(chars[i-26]=='M')
			{
                numbers[i]++;
			}
            if(chars[i-27]=='M')
			{
                numbers[i]++;
			}
        }
    }
   
    for(int i=26; i<210; i++)   //left
    {
        if(i%26==1 && chars[i]!='M')
        {
            if(chars[i-26]=='M')
			{
                numbers[i]++;
			}
            if(chars[i-25]=='M')
			{
                numbers[i]++;
			}
            if(chars[i+1]=='M')
			{
                numbers[i]++;
			}
            if(chars[i+26]=='M')
			{
                numbers[i]++;
			}
            if(chars[i+27]=='M')
			{
                numbers[i]++;
			}
        }
    }
   
    for(int i=50; i<235; i++)   //right
    {
        if(i%26==0 && chars[i]!='M')
        {
            if(chars[i-27]=='M')
			{
                numbers[i]++;
			}
            if(chars[i-26]=='M')
			{
                numbers[i]++;
			}
            if(chars[i-1]=='M')
			{
                numbers[i]++;
			}
            if(chars[i+25]=='M')
			{
                numbers[i]++;
			}
            if(chars[i+26]=='M')
			{
                numbers[i]++;
			}
        }
    }
   
    for(int i=28; i<234; i++)   //all else
    {
        if(i%26!=0 && i%26!=1 && chars[i]!='M')
        {
            if(chars[i-27]=='M')
			{
                numbers[i]++;
			}
            if(chars[i-26]=='M')
			{
                numbers[i]++;
			}
            if(chars[i-25]=='M')
			{
                numbers[i]++;
			}
            if(chars[i-1]=='M')
			{
                numbers[i]++;
			}
            if(chars[i+1]=='M')
			{
                numbers[i]++;
			}
            if(chars[i+25]=='M')
			{
                numbers[i]++;
			}
            if(chars[i+26]=='M')
			{
                numbers[i]++;
			}
            if(chars[i+27]=='M')
			{
                numbers[i]++;
			}
        }
    }
   
    for(int i=0; i<261; i++)
    {
        if(numbers[i]==1)
		{
            chars[i] = '1';
		}
        if(numbers[i]==2)
		{
            chars[i] = '2';
		}
        if(numbers[i]==3)
		{
            chars[i] = '3';
		}
        if(numbers[i]==4)
		{
            chars[i] = '4';
		}
        if(numbers[i]==5)
		{
            chars[i] = '5';
		}
        if(numbers[i]==6)
		{
            chars[i] = '6';
		}
        if(numbers[i]==7)
		{
            chars[i] = '7';
		}
        if(numbers[i]==8)
		{
            chars[i] = '8';
		}
    }
   
   
	while(1)
	{
		//print out board labels
		cout << endl <<  "To Flag a mine type 'F' before your selection." << endl;
		cout << "\n\n    a b c d e f g h i j k l m n o p q r s t u v w x y z\n    ---------------------------------------------------\n 0| ";
		num=1;
		for(int i=0; i<260; i++)
		{
			if(cover[i+1]=='+')
			{
				cout<<cover[i+1]<<" ";
			}
			else
			{
				cout<<chars[i+1]<<" ";
			}
       
       
			if(i%26 == 25 && num != 10)
			{
				cout<<"|"<<num-1<<"\n "<<num<<"| ";
				num++;
			}
           
		}
		//print out board labels
		cout << "|9\n    ---------------------------------------------------\n    a b c d e f g h i j k l m n o p q r s t u v w x y z";
   
		cout <<"\n\nMines left: "<< count;
		cout << "\nChoose a space: ";
		cin >> character1 >> character2;
 
		flag = 'n';

		if(character1 == 'F')  //if the space is to be flagged
		{//shift the bits
			cin >> character3;
			character1 = character2;
			character2 = character3;
			if(flag == 'y')
			{
				flag='n';
				count++;
			}
			else
			{
				flag='y';
				count--;
			}
		}
		wait = 1;

		//Allowing for the user to input either the letter or the number first
		if(character1=='a' || character2=='a')
		{
			extra1 = 1;
		}
		else if(character1=='b' || character2=='b')
		{
			extra1 = 2;
		}
		else if(character1=='c' || character2=='c')
		{
			extra1 = 3;
		}
		else if(character1=='d' || character2=='d')
		{
			extra1 = 4;
		}
		else if(character1=='e' || character2=='e')
		{
			extra1 = 5;
		}
		else if(character1=='f' || character2=='f')
		{
			extra1 = 6;
		}
		else if(character1=='g' || character2=='g')
		{
			extra1 = 7;
		}
		else if(character1=='h' || character2=='h')
		{
			extra1 = 8;
		}
		else if(character1=='i' || character2=='i')
		{
			extra1 = 9;
		}
		else if(character1=='j' || character2=='j')
		{
			extra1 = 10;
		}
		else if(character1=='k' || character2=='k')
		{
			extra1 = 11;
		}
		else if(character1=='l' || character2=='l')
		{
			extra1 = 12;
		}
		else if(character1=='m' || character2=='m')
		{
			extra1 = 13;
		}
		else if(character1=='n' || character2=='n')
		{
			extra1 = 14;
		}
		else if(character1=='o' || character2=='o')
		{
			extra1 = 15;
		}
		else if(character1=='p' || character2=='p')
		{
			extra1 = 16;
		}
		else if(character1=='q' || character2=='q')
		{
			extra1 = 17;
		}
		else if(character1=='r' || character2=='r')
		{
			extra1 = 18;
		}
		else if(character1=='s' || character2=='s')
		{
			extra1 = 19;
		}
		else if(character1=='t' || character2=='t')
		{
			extra1 = 20;
		}
		else if(character1=='u' || character2=='u')
		{
			extra1 = 21;
		}
		else if(character1=='v' || character2=='v')
		{
			extra1 = 22;
		}
		else if(character1=='w' || character2=='w')
		{
			extra1 = 23;
		}
		else if(character1=='x' || character2=='x')
		{
			extra1 = 24;
		}
		else if(character1=='y' || character2=='y')
		{
			extra1 = 25;
		}
		else if(character1=='z' || character2=='z')
		{
			extra1 = 26;
		}
		else 
		{
			//If a letter is not typed in for the first or second character
			cout << "No letter found in your input.";
		}
 
		//numbers can be typed in either order
		if(character2=='0' || character1 =='0')
		{
			extra2 = 0;
		}
		else if(character2=='1' || character1 =='1')
		{
			extra2 = 1;
		}
		else if(character2=='2' || character1 =='2')
		{
			extra2 = 2;
		}
		else if(character2=='3' || character1 =='3')
		{
			extra2 = 3;
		}
		else if(character2=='4' || character1 =='4')
		{
			extra2 = 4;
		}
		else if(character2=='5' || character1 =='5')
		{
			extra2 = 5;
		}
		else if(character2=='6' || character1 =='6')
		{
			extra2 = 6;
		}
		else if(character2=='7' || character1 =='7')
		{
			extra2 = 7;
		}
		else if(character2=='8' || character1 =='8')
		{
			extra2 = 8;
		}
		else if(character2=='9' || character1 =='9')
		{
			extra2 = 9;
		}
		else 
		{
			//If a number is not typed in for the first or second character
			cout << endl << "No number found in your input.";
		}
 
		iDigit = extra1 + 26 * extra2;
       
		
	
		if(flag=='y')
		{
			chars[iDigit]='F';
		}
		

		cover[iDigit]='-';
       
		wait_counter[wait]=iDigit;
       
		while(wait!=0 && flag=='n')
		{   
			if(chars[iDigit]=='0')
			{
				if(iDigit==1)   //top left
				{  
					if(numbers[2]==0 && cover[2]=='+')
					{
						wait++;
						wait_counter[wait] = 2;
					}
				
					cover[2]='-';
					
					if(numbers[27]==0 && cover[27]=='+')
					{
						wait++;
						wait_counter[wait] = 27;
					}
					
					cover[27]='-';
					
					if(numbers[28]==0 && cover[28]=='+')
					{
						wait++;
						wait_counter[wait] = 28;
					}
					
					cover[28]='-';
				
				}

				if(iDigit==26 && cover[26]=='+')  //top right
				{
					if(numbers[25]==0 && cover[25]=='+')
					{
						wait++;
						wait_counter[wait] = 25;
					}
				
					cover[25]='-';
					
					if(numbers[51]==0 && cover[51]=='+')
					{
						wait++;
						wait_counter[wait] = 51;
					}
					
					cover[51]='-';
					
					if(numbers[52]==0 && cover[52]=='+')
					{
						wait++;
						wait_counter[wait] = 52;
					}
					
					cover[52]='-';
				}

				if(iDigit==235 && cover[235]=='+') //bottom left
				{
					if(numbers[209]==0 && cover[209]=='+')
					{
						wait++;
						wait_counter[wait] = 209;
					}
				
					cover[209]='-';
           
					if(numbers[210]==0 && cover[210]=='+')
					{
						wait++;
						wait_counter[wait] = 210;
					}
					
					cover[210]='-';
           
					if(numbers[236]==0 && cover[236]=='+')
					{
						wait++;
						wait_counter[wait] = 236;
					}
					
					cover[236]='-';
				}
				if(iDigit==260 && cover[260]=='+') //bottom right
				{
					if(numbers[233]==0 && cover[233]=='+')
					{
						wait++;
						wait_counter[wait] = 233;
					}

					cover[233]='-';
           
					if(numbers[234]==0 && cover[234]=='+')
					{
						wait++;
						wait_counter[wait] = 234;
					}
					
					cover[234]='-';
           
					if(numbers[259]==0 && cover[259]=='+')
					{
						wait++;
						wait_counter[wait] = 259;
					}
						
					cover[259]='-';
           
				}
				for(int i=2; i<26; i++)   //top
				{
					if(iDigit==i)
					{
						if(numbers[i-1]==0 && cover[i-1]=='+')
						{
							wait++;
							wait_counter[wait] = i-1;
						}
					
						cover[i-1]='-';
						
						if(numbers[i+1]==0 && cover[i+1]=='+')
						{
							wait++;
							wait_counter[wait] = i+1;
						}
						
						cover[i+1]='-';
						
						if(numbers[i+25]==0 && cover[i+25]=='+')
						{
							wait++;
							wait_counter[wait] = i+25;
						}
						
						cover[i+25]='-';
						
						if(numbers[i+26]==0 && cover[i+26]=='+')
						{
							wait++;
							wait_counter[wait] = i+26;
						}
						
						cover[i+26]='-';
						
						if(numbers[i+27]==0 && cover[i+27]=='+')
						{
							wait++;
							wait_counter[wait]=i+27;
						}
						
						cover[i+27]='-';
					}
				}
				for(int i=236;i<260;i++)   //bottom
				{
					if(iDigit==i)
					{
						if(numbers[i-1]==0 && cover[i-1]=='+')
						{
							wait++;
							wait_counter[wait] = i-1;
						}
						
						cover[i-1]='-';
               
						if(numbers[i+1]==0 && cover[i+1]=='+')
						{
							wait++;
							wait_counter[wait] = i+1;
						}
				
						cover[i+1]='-';
               
						if(numbers[i-25]==0 && cover[i-25]=='+')
						{
							wait++;
							wait_counter[wait] = i-25;
						}
						
						cover[i-25]='-';
						
						if(numbers[i-26]==0 && cover[i-26]=='+')
						{
							wait++;
							wait_counter[wait] = i-26;
						}
						
						cover[i-26]='-';
						
						if(numbers[i-27]==0 && cover[i-27]=='+')
						{
							wait++;
							wait_counter[wait] = i-27;
						}
						
						cover[i-27]='-';
					}
				}
				for(int i=26; i<210; i++)   //left
				{
					if(i%26==1 && iDigit==i)
					{
						if(numbers[i-26]==0 && cover[i-26]=='+')
						{
							wait++;
							wait_counter[wait] = i-26;
						}
						
						cover[i-26]='-';
						
						if(numbers[i-25]==0 && cover[i-25]=='+')
						{
							wait++;
							wait_counter[wait] = i-25;
						}
						
						cover[i-25]='-';
               
						if(numbers[i+1]==0 && cover[i+1]=='+')
						{
							wait++;
							wait_counter[wait] = i+1;
						}
						
						cover[i+1]='-';
						
						if(numbers[i+26]==0 && cover[i+26]=='+')
						{
							wait++;
							wait_counter[wait] = i+26;
						}
						
						cover[i+26]='-';
						
						if(numbers[i+27]==0 && cover[i+27]=='+')
						{
							wait++;
							wait_counter[wait] = i+27;
						}
						
						cover[i+27]='-';
					}
				}
				for(int i=50; i<235; i++)   //right
				{
					if(i%26==0 && iDigit==i)
					{
						if(numbers[i-27]==0 && cover[i-27]=='+')
						{
							wait++;
							wait_counter[wait] = i-27;
						}
						
						cover[i-27]='-';
						
						if(numbers[i-26]==0 && cover[i-26]=='+')
						{
							wait++;
							wait_counter[wait] = i-26;
						}
						
						cover[i-26]='-';
						
						if(numbers[i-1]==0 && cover[i-1]=='+')
						{
							wait++;
							wait_counter[wait] = i-1;
						}
						
						cover[i-1]='-';
						
						if(numbers[i+25]==0 && cover[i+25]=='+')
						{
							wait++;
							wait_counter[wait] = i+25;
						}
						
						cover[i+25]='-';
						
						if(numbers[i+26]==0 && cover[i+26]=='+')
						{
							wait++;
							wait_counter[wait] = i+26;
						}
						
						cover[i+26]='-';
					}

				}
				for(int i=28;i<234;i++)   //all else
				{
					if(i%26!=0 && i%26!=1 && iDigit==i)
					{
						if(numbers[i-27]==0 && cover[i-27]=='+')
						{
							wait++;
							wait_counter[wait] = i-27;
						}
						
						cover[i-27]='-';
						
						if(numbers[i-26]==0 && cover[i-26]=='+')
						{
							wait++;
							wait_counter[wait] = i-26;
						}
						
						cover[i-26]='-';
						
						if(numbers[i-25]==0 && cover[i-25]=='+')
						{
							wait++;
							wait_counter[wait] = i-25;
						}
						
						cover[i-25]='-';
						
						if(numbers[i-1]==0 && cover[i-1]=='+')
						{
							wait++;
							wait_counter[wait] = i-1;
						}
						
						cover[i-1]='-';
						
						if(numbers[i+1]==0 && cover[i+1]=='+')
						{
							wait++;
							wait_counter[wait] = i+1;
						}
						
						cover[i+1]='-';
						
						if(numbers[i+25]==0 && cover[i+25]=='+')
						{
							wait++;
							wait_counter[wait] = i+25;
						}
						
						cover[i+25]='-';
						
						if(numbers[i+26]==0 && cover[i+26]=='+')
						{
							wait++;
							wait_counter[wait] = i+26;
						}
						
						cover[i+26]='-';
						
						if(numbers[i+27]==0 && cover[i+27]=='+')
						{
							wait++;
							wait_counter[wait] = i+27;
						}
						
						cover[i+27]='-';
					}
				}
			}
       
				iDigit=wait_counter[wait];
				wait--;
		}
	}  
}