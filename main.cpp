#include <iostream>
#include <vector>
#include <thread>

using namespace std;

string watekWszystkieLIczbyPierwsze(int n) {
    for (int i=2; i<n; i++) {
    	bool flag = true;
        for (int j=2; j<=i/2; j++) {
        	if (i%j == 0) {
        		flag = false;
        		break;
			}
		}
		if (flag) cout<<i<<endl;
    }
}

unsigned long watekFibo(int n)
{
  if (n <= 1) return n;
  else return watekFibo (n - 2) + watekFibo (n - 1);
}

int main()
{
    vector <thread *> threads1;

    thread *watek = new thread(watekWszystkieLIczbyPierwsze, 20);
    threads1.push_back(watek);


    thread *watek2 = new thread(watekFibo, 15);
    threads1.push_back(watek2);

    for (vector<thread *>::iterator it = threads1.begin(); it != threads1.end(); ++it) {
        (*it)->join(); //tablica wskaünikÛw na wπtki, a it to wskaünik na wskaünik
        delete *it;
    }

    return 0;
}
