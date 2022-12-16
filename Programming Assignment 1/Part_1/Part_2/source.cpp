#include "iostream"
using namespace std;

int rod_0_order=-1;// I defined these orders as -1 because moving function increase value before the placement
int rod_1_order=-1;
int rod_2_order=-1;
int STEP_1,STEP_2,STEP_3,STEP_4;//They define step counts of solving hanoi table
int val=0;
class Discs//I define Disc class and it initialized with 0 values to represent disc is empty
{
    private:
        int diameter;

    public:
        Discs(int input=0){
            diameter = input;
        }
        int get_diameter(){
            return diameter;
        }
        void print_disc(){//I used this function to make disc value visible
            cout<<diameter;
        }


};
class Hanoi //We defined Hanoi class which is consist of three rods with 0 initial values.
{
    private:
        Discs rod_0[20];
        Discs rod_1[20];
        Discs rod_2[20];
    public:
        Hanoi(int num_of_disc){
            rod_0_order=num_of_disc-1;
            for(int i = 0; i<num_of_disc;i++){
                rod_0[i] = Discs(num_of_disc-i);
            }
            STEP_1=num_of_disc-1;
            STEP_2=num_of_disc-1;
            STEP_3=num_of_disc-1;
            STEP_4=num_of_disc-2;
        }
        void move_to(int from,int to){//I changed the function name because there is another move function
            if(from>3 || to>3)
            {
                cout<<"This move is illegal"<<endl;
            }
            else{
                if(from == 0 && to == 1){
                    cout<<"Disc"<<ends;
                    rod_0[rod_0_order].print_disc();
                    cout<<" is moved from Rod "<< from<<" to Rod "<<to<<endl;
                    rod_1[++rod_1_order]=rod_0[rod_0_order];
                    rod_0[rod_0_order--]=0;
                }
                else if(from == 0 && to == 2){
                    cout<<"Disc"<<ends;
                    rod_0[rod_0_order].print_disc();
                    cout<<" is moved from Rod "<< from<<" to Rod "<<to<<endl;
                    rod_2[++rod_2_order]=rod_0[rod_0_order];
                    rod_0[rod_0_order--]=0;
                }
                else if(from == 1 && to == 0){
                    cout<<"Disc"<<ends;
                    rod_1[rod_1_order].print_disc();
                    cout<<" is moved from Rod "<< from<<" to Rod "<<to<<endl;
                    rod_0[++rod_0_order]=rod_1[rod_1_order];
                    rod_1[rod_1_order--]=0;
                }
                else if(from == 1 && to == 2){
                    cout<<"Disc"<<ends;
                    rod_1[rod_1_order].print_disc();
                    cout<<" is moved from Rod "<< from<<" to Rod "<<to<<endl;
                    rod_2[++rod_2_order]=rod_1[rod_1_order];
                    rod_1[rod_1_order--]=0;
                }
                else if(from == 2 && to == 0){
                    cout<<"Disc"<<ends;
                    rod_2[rod_2_order].print_disc();
                    cout<<" is moved from Rod "<< from<<" to Rod "<<to<<endl;
                    rod_0[++rod_0_order]=rod_2[rod_2_order];
                    rod_2[rod_2_order--]=0;

                }
                else if(from == 2 && to == 1){
                    cout<<"Disc"<<ends;
                    rod_2[rod_2_order].print_disc();
                    cout<<" is moved from Rod "<< from<<" to Rod "<<to<<endl;
                    rod_1[++rod_1_order]=rod_2[rod_2_order];
                    rod_2[rod_2_order--]=0;
                }
            }
        }
        //I used following functions to make rodes visible
        void print_rod(void)
        {
            int i=0;
            for(int i=1;i<21;i++)
            {
                rod_0[20-i].print_disc();
                cout<<" ";
                rod_1[20-i].print_disc();
                cout<<" ";
                rod_2[20-i].print_disc();
                cout<<endl;
            }
        }
        void solve_Hanoi(Hanoi& game){//I found four steps to complete the game. Each step has recursive and after each one is done, function move to another step
            if(STEP_1>0){
                if(STEP_1!=1)
                {
                    move_to(0,2);
                    STEP_1--;
                    solve_Hanoi(game);
                }
                else if(STEP_1==1)
                {
                    move_to(0,1);
                    STEP_1--;
                    solve_Hanoi(game);
                }
            }
            else if ( STEP_1 == 0 && STEP_2>0)
            {
                if(STEP_2!=1)
                {
                    move_to(2,1);
                    STEP_2--;
                    solve_Hanoi(game);
                }
                else if(STEP_2==1)
                {
                    move_to(0,2);
                    STEP_2--;
                    solve_Hanoi(game);
                }
            }
            else if ( STEP_1 == 0 && STEP_2==0 && STEP_3>0)
            {
                if(STEP_3!=1)
                {
                    move_to(1,0);
                    STEP_3--;
                    solve_Hanoi(game);
                }
                else if(STEP_3==1)
                {
                    move_to(1,2);
                    STEP_3--;
                    solve_Hanoi(game);
                }
            }
            else if ( STEP_1 == 0 && STEP_2==0 && STEP_3==0 && STEP_4>0)
            {
                move_to(0,2);
                STEP_4--;
                solve_Hanoi(game);
            }
        }


};
void print_backwards(char const * str)
{
    if(*str != '\0')//str pointer increases until null-termination shows up
    {
        print_backwards(str+1);
        cout<<*str;
    }
}
int nth_prime(int n)
{
    int primes[n],number=2,index=0;
    while(n!=index)//I aim to find Nth prime number by finding each one of them until N comes
    {
        int divide=2,cnt=0;
        while(number>divide)
        {
            if(number%divide == 0)
            {
                cnt++;
            }
            divide++;
        }
        if(cnt==0)
        {
            primes[index++]=number;

        }
        number++;
    }
    cout<<primes[n-1]<<endl;
}
int main()
{
    Hanoi Hanoi_1(5);
    char str[20]="Alper Kutay OZBEK";
    //Hanoi_1.solve_Hanoi(Hanoi_1);
    //Hanoi_1.print_rod();
    //print_backwards(str);
    //cout<<endl;
    nth_prime(35);
}

