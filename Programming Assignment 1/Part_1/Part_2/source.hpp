#include "iostream"
using namespace std;

int rod_0_order=-1;// I defined these orders as -1 because moving function increase value before the placement
int rod_1_order=-1;
int rod_2_order=-1;
int total_discs;
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
            total_discs=num_of_disc;
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
                if(rod_0_order == -1 && rod_1_order == -1 && rod_2_order == total_discs-1)
                {
                    rod_0_order=-1;
                    rod_1_order=-1;
                    rod_2_order=-1;
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
void helper_solve_Hanoi(Hanoi& game, int disc, int from_rod, int to_rod, int aux_rod){


    if (disc == 0) {
        return;
    }
    helper_solve_Hanoi(game, disc - 1, from_rod, aux_rod, to_rod);
    game.move_to(from_rod, to_rod);
    helper_solve_Hanoi(game, disc - 1, aux_rod, to_rod, from_rod);
    return;

};
void solve_hanoi(Hanoi& game){

    helper_solve_Hanoi(game ,total_discs, 0, 2, 1);
};
/*int main()
{
    Hanoi Hanoi_1(3);
    char str[20]="Alper Kutay OZBEK";
    solve_hanoi(Hanoi_1);
    //Hanoi_1.print_rod();
    //print_backwards(str);
    //cout<<endl;
    //nth_prime(35);
*/

