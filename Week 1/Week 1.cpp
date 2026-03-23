/*
#include <iostream>

int main() // function name : main , int : cpp의 예약어(return으로부터 반환되는 것이 int)
{
        std::cout << "Helloworld\n";  
         cout : 표준 출력 스트림, << : 'cout'에 출력하라 라는 의미로 쓰인다.
    return 0; // 함수가 종료된 후, 함수를 실행시킨 주체에게 반환하라는 의미
    }

*/


// 입력 

/*
#include <iostream>

int main()
{
    
    std::cout << "Write first name and Push ENTER\n";
    
    std::string first_name; // first_name : str type variable
    std::cin >> first_name; // Read str type to first_name    
    std::cout<<"Hello " << first_name << "!\n";
    
    }

*/
// LN)
// cout << : 부등호 방향이 우측 : 출력 
// cin >> 부등호 방향이 좌측 : 입력
// 쉽게 말해 out과 in 앞에 접두어 c가 붙었다고 생각하자.

/*
#include <iostream>

int main()
{
    
    std::cout << "Hello plz first name & enter" ;
    std::string first_name;
    std::cin >> first_name;
    std::cout << first_name;
    std::cout << "!\n";

}

*/

/*
#include <iostream>

int main()
{
    std::cout << "first name : "; 
    std::string first_name;
    std::cin >> first_name;
    
    std::cout << "first name" << " is " << first_name;
    
}
*/

//변수 

/*
#include <iostream>

int main()
{
    std::string name = "Jeon";
    int age_Jeon = 21;
    
    std::cout << "His last name is " << name << " and his age is " << age_Jeon;  
    
}

*/

//LN)
// int 는 cpp 기본 예약어이기 때문에 std:: 를 필요로 하지 않는다.


/*
#include <iostream>

int main()
{
    
    std::string name = "Luciano";
    int birth = 50915;
    double GPA = 4.5;
    bool real = true;
    
    std::cout << "my name is \n" << name << "my birth is\n" << birth << "\nand my GPA is " << GPA;
}
*/

// 입력과 타입

/*
#include <iostream>

int main()
{
    
    std::cout << "first name and age";
    std::string first_name;
    int age;
    
    std::cin >> first_name;
    std::cin >> age;
    
    std::cout << "Hi " << first_name << " your age is : " << age;

}

*/

// 대입과 초기화

/*
#include <iostream>

int main()

{
    
    int a = 3;
    
    a =4;
    
    int b = a;
    
    b = a +5;
    
    a = a+7;
    
    std::cout << "a = " << a << "\nb = " << b;
    
    
}
*/

//LN)
//python : changing bind 느낌


// 반복
// - while 

/*
#include <iostream>

int main()
{
    
    int i = 0;
    
    while (i < 100)
        std::cout << i << '\t' << i * 2<< '\n';
    
}
*/

// - for

/*
#include <iostream>

int main() 
{
    
    for (int i =0; i < 5; i++){
        std::cout << i << "\n";
    }
    
    //python : 
    
    //for i in range(5)
    //    print(i)
    
}
*/























































