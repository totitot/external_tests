#include <iostream>

using namespace std;
class Status{
	public:
		void setEnabled( bool enable ){
			if( enable ){
				if( m_status < 0 ) m_status = 0-m_status;
				else m_status++;
			}
			else{
				m_status = 0-m_status;
			}
		}
		bool isEnable(){
			return( m_status > 0 );
		}
	private:
		int m_status=0;
};

int main(){
	Status st;

	st.setEnabled(true);
}
