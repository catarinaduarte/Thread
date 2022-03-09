#include <iostream>
#include <thread>

using namespace std;

void foo() { cout << "foo !" << endl; }

void bar(int x) { cout << "bar : " << x << endl; }

int main()
{
 thread first = thread(foo); // spawn new thread that calls foo()
 thread second = thread(bar, 10); // spawn new thread that calls bar(10)

 cout << "main, foo and bar now execute concurrently...\n";

 // synchronize threads:
 first.join(); // pauses until first finishes
 second.join(); // pauses until second finishes
 cout << "foo and bar completed.\n";

 return 0;
}
