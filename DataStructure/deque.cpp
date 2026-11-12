namespace hoshi
{
	template<typename T,int N=4096>
	class deque
	{
	private:
		static constexpr unsigned bit_width(unsigned x) noexcept
		{
			unsigned w=0;
			while(x){x>>=1,w++;}
			return w;
		}
		static constexpr int SIZE=1<<bit_width(N);
		static constexpr int MOD=SIZE-1;
		int head,tail;
		T buf[SIZE];
	public:
		deque():head(0),tail(0){}
		bool empty(){return head==tail;}
		const T& front() const {return buf[head];}
		const T& back() const {return buf[(tail-1)&MOD];}
		void push_front(T x)
		{
			head=(head-1)&MOD;
			buf[head]=x;
		}
		void push_back(T x)
		{
			buf[tail]=x;
			tail=(tail+1)&MOD;
		}
		void pop_front(){head=(head+1)&MOD;}
		void pop_back(){tail=(tail-1)&MOD;}
	};
}