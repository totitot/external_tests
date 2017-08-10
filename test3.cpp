#include <iostream>
#include <string>
#include <memory>
#include <deque>

using namespace std;
class CShell{ 
	public:
		~CShell(){}
		//friend void delete_cshell( CShell * obj );
		static CShell * create(){
			dqcsh.push_back( new CShell );
			cout << "created new CShell" << endl;
			cout << "# of CShells: " << dqcsh.size() << endl;
			return dqcsh.back();
		}

		static void destroy(){
			delete dqcsh.front();
			dqcsh.pop_front();
			cout << "destroyed latest CShell" << endl;
			cout << "# of CShells: " << dqcsh.size() << endl;
		}

	protected:
		static deque<CShell *> dqcsh;
		CShell(){}
		void operator delete( void * ptr ){
			free(ptr);
		}

		
};

deque<CShell*> CShell::dqcsh;

int main(){
	//CShell *pShell = new CShell;
	CShell *pShell1 = CShell::create();
	CShell *pShell2 = CShell::create();
	CShell *pShell3 = CShell::create();

	//delete pShell;
	CShell::destroy();
	CShell::destroy();
	CShell::destroy();
}


