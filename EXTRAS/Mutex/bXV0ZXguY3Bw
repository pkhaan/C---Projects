#include <thread>
#include <mutex>
#include <random>
#include <list>
#include <iostream>
#include <algorithm>

using namespace std;

mutex m;

void RandomFillList(list<float> * a, int num)
{
	for (int j = 0; j < 4; j++)
	{
		vector<float> v;
		v.reserve(num);

		// no mutually exclusive access is required here
		for (int i = 0; i < num; i++)
		{
			v.push_back (powf(rand() / float(RAND_MAX),2.0f));
		}

		// but mutually exclusive access is required during writes
		//m.lock(); // enter critical section
		cout << "thread " << this_thread::get_id() << " enters critical section\n";
		a->insert(a->begin(), v.begin(), v.end());
		a->sort();

		cout << "thread " << this_thread::get_id() << " exits critical section\n";
		//m.unlock(); // exit critical section

		v.clear();
	}
}

void main()
{
	srand(0);

	list<float> a;

	a.resize(1024, 0.0f);
	generate(a.begin(), a.end(), rand);

	thread t1 = thread(RandomFillList, &a, 10000);
	thread t2 = thread(RandomFillList, &a, 10000);

	t1.join();
	t2.join();

	cout << "Number of elements in list = " << a.size();

	getchar();
}
