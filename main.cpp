//C++ STL
/*
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v(6,1);
    cout << "v.capacity(): " << v.capacity() << "/v.size: "<<v.size()<<endl;
    for (auto i = 0; i<v.size();i++)
        cout << v[i] << endl;
    cout << endl << endl;

    v.assign(4,3);
    cout << "v.capacity(): " << v.capacity() << "/v.size: "<<v.size()<<endl;
    for (auto i = 0; i<v.size();i++)
        cout << v[i] << endl;
    cout << endl << endl;

    v[2] = 7;
    for(vector<int>::iterator it = v.begin()+3;it !=v.end();it++)
        *it = 9;
    v.push_back(10);
    v.push_back(20);
    cout << "v.capacity(): " << v.capacity() << "/v.size: "<<v.size()<<endl;
    for (auto i = 0; i<v.size();i++)
        cout << v[i] << endl;
    cout << endl << endl;

    v.push_back(30);
    cout << "v.capacity(): " << v.capacity() << "/v.size: "<<v.size()<<endl;
    for (auto i = 0; i<v.size();i++)
        cout << v[i] << endl;
    cout << endl << endl;

    v.resize(17);
    cout << "v.capacity(): " << v.capacity() << "/v.size: "<<v.size()<<endl;
    for (auto i = 0; i<v.size();i++)
        cout << v[i] << endl;
    cout << endl << endl;

    return 0;
}*/

/*
#include <iostream>
#include <vector>
#include <sting>
#include <algorithm>
using namespace std;

class Person{
private:
    int age;
    string name;
public:
    Person(const int a, const string& n): age(a), name(n){}
    int getName(){return name;}
};

int main(int argc, char** argv)
{
    Person p1{20, "Tom"};
    Person p2{19,"Jane"};

    vector<Person>vec{
        {21, "Smith"},{39,"John"},{23,"Mary"},{45,"Ted"}
    };
    for_each(vec,begin(),vec.end(),[](Person p){
        cout <<p.getAge()<<","<<p.getName()<<endl;
    };)
        return 0;
}*/


//유니폼 초기화
/*
#include <iostream>
#include <vector>
#include <string>       // string 헤더 오타 수정
#include <algorithm>
using namespace std;

class Person {
private:
    int age;
    string name;
public:
    Person(const int a, const string& n) : age(a), name(n) {}

    int getAge() const { return age; }          // getAge 함수 추가
    string getName() const { return name; }     // 반환형 수정 및 const 함수로 선언
};

int main() {
    Person p1{20, "Tom"};
    Person p2{19, "Jane"};

    vector<Person> vec{
        {21, "Smith"}, {39, "John"}, {23, "Mary"}, {45, "Ted"}
    };

    // 올바른 for_each 문
    for_each(vec.begin(), vec.end(), [](const Person& p) {
        cout << p.getAge() << ", " << p.getName() << endl;
    });

    return 0;
}*/
//2 수정 전
/*
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class multiplier{
    int first;
    int second;
private:
    multiplier(int f,int s){
        first = f;
        second = s;
    }
    int getResult(){
        return first* second;
    }
};

int main()
{
    vector<multiplier>multipleData;

    for(int i = 0; i<10; i++){
        multiplier multiple = multiplier(rand() % 10,rand() % 10);
        multipleData.push_back(multiple);
    }

    cout << "정렬되지 않는 결과" <<endl;
    for (vector<Multiplier>::iterator iter=multipleData.begin();iter!= multipleData.end();iter++){
        cout << iter->getResult()<<endl;
    }
    sort(multipleData.begin(),multipleData.end(),[](multiplier& m1,multiplier& m2))
    {
        return m1.getResult()<m2.getResult();
    });
cout<<" "<<endl;
    for(vector<multiplier>::iterator iter=multipleData.begin();iter != multipleData.end();iter++){
    cout << iter->getResult() << endl;
    }
    return 0;
}*/
//2 수정 후
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib> // rand()

using namespace std;

class Multiplier {
    int first;
    int second;
public:
    Multiplier(int f, int s) : first(f), second(s) {}

    int getResult() const {
        return first * second;
    }
};

int main() {
    vector<Multiplier> multipleData;

    for (int i = 0; i < 10; i++) {
        Multiplier multiple(rand() % 10, rand() % 10);
        multipleData.push_back(multiple);
    }

    cout << "Unsorted results:" << endl;
    for (vector<Multiplier>::iterator iter = multipleData.begin(); iter != multipleData.end(); iter++) {
        cout << iter->getResult() << endl;
    }

    // Sort by result value
    sort(multipleData.begin(), multipleData.end(), [](const Multiplier& m1, const Multiplier& m2) {
        return m1.getResult() < m2.getResult();
    });

    cout << "\nSorted results:" << endl;
    for (vector<Multiplier>::iterator iter = multipleData.begin(); iter != multipleData.end(); iter++) {
        cout << iter->getResult() << endl;
    }

    return 0;
}*/

//deque 수정 전
/*
#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);

    cout << "dq.size(): " << dq.size() << endl;
    cout << "[dq]: ";
    for(auto i = 0; i<dq.size(); i++)
        cout << dq[i]<<" ";
    cout << endl;

    for(auto i = 0; i<dq.size();i++)
        cout << "dqress["<<i<<"] address: "<<&dq[i]<<endl;
    cout<<endl;
    deque<int> dq2;
    dq2.push_back(100);
    dq2.push_back(200);
    dq2.push_back(300);

    cout<<"dq2.size(): "<<dq2.size()<<endl;
    cout<<"[dq2]: ";
    for(auto i = 0; i<dq2.size();i++)
        cout <<dq2[i]<<" ";
    cout << endl;
    for(auto i = 0; i<dq2.size();i++)
        cout <<"dq2["<<i<<"]address: "<<&dq2[i]<<endl;
    cout << endl;

    dq.push_back(40);
    dq.push_back(50);
    dq.push_back(60);
    cout<<"dp.size(): "<<dq.size()<<endl;
    cout<<"[dq]: ";
    for(auto i = 0; i<dq.size();i++)
        cout <<dq[i]<<" ";
    cout << endl;
    for(auto i = 0; i<dq.size();i++)
        cout <<"dq["<<i<<"]address: "<<&dq2[i]<<endl;
    cout << endl;

    for(int i = 70;i<2000;i+=10)
        dq.push_back(i);

    cout << "dq.size(): "<<dq.size()<<endl;
    cout << "[dq]: ";

    for(auto i = 0; i<dq.size();i++)
            cout <<dq[i]<<" ";
    cout << endl;
    for(auto i = 0; i<dq.size();i++)
        cout <<"dq["<<i<<"]address: "<<&dq2[i]<<endl;
    cout << endl;

    cout<<"dq[127]("<<&dq[127]<<"):"<<dq[127]<<endl;
    cout<<"dq[128]("<<&dq[128]<<"):"<<dq[128]<<endl;
    deque<int>::iterator i = dq.begin()+127;
    cout << "*i("<<&(i)<<");"<<*i<<endl;
    i++;
    cout<<"*++i("<<&(*i)<<"):"<<*i<<endl;
    int* j=&dq[127];
    cout<<j<<": "<<*j<<endl;
    j++;
    cout<<j<<": "<<*j<<endl;

    return 0;
}*/

//수정 후
#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);

    cout << "dq.size(): " << dq.size() << endl;
    cout << "[dq]: ";
    for (auto i = 0; i < dq.size(); i++)
        cout << dq[i] << " ";
    cout << endl;

    for (auto i = 0; i < dq.size(); i++)
        cout << "dq[" << i << "] address: " << &dq[i] << endl;
    cout << endl;

    deque<int> dq2;
    dq2.push_back(100);
    dq2.push_back(200);
    dq2.push_back(300);

    cout << "dq2.size(): " << dq2.size() << endl;
    cout << "[dq2]: ";
    for (auto i = 0; i < dq2.size(); i++)
        cout << dq2[i] << " ";
    cout << endl;
    for (auto i = 0; i < dq2.size(); i++)
        cout << "dq2[" << i << "] address: " << &dq2[i] << endl;
    cout << endl;

    dq.push_back(40);
    dq.push_back(50);
    dq.push_back(60);
    cout << "dq.size(): " << dq.size() << endl;
    cout << "[dq]: ";
    for (auto i = 0; i < dq.size(); i++)
        cout << dq[i] << " ";
    cout << endl;
    for (auto i = 0; i < dq.size(); i++)
        cout << "dq[" << i << "] address: " << &dq[i] << endl;
    cout << endl;

    for (int i = 70; i < 2000; i += 10)
        dq.push_back(i);

    cout << "dq.size(): " << dq.size() << endl;
    cout << "[dq]: ";
    for (auto i = 0; i < dq.size(); i++)
        cout << dq[i] << " ";
    cout << endl;
    for (auto i = 0; i < dq.size(); i++)
        cout << "dq[" << i << "] address: " << &dq[i] << endl;
    cout << endl;

    cout << "dq[127] (" << &dq[127] << "): " << dq[127] << endl;
    cout << "dq[128] (" << &dq[128] << "): " << dq[128] << endl;

    deque<int>::iterator i = dq.begin() + 127;
    cout << "*i (" << &(*i) << "): " << *i << endl;
    ++i;
    cout << "*++i (" << &(*i) << "): " << *i << endl;

    int* j = &dq[127];
    cout << j << ": " << *j << endl;
    ++j;
    cout << j << ": " << *j << endl;

    return 0;
}

