#ifndef THREAD_H_
#define THREAD_H_

#include <iostream>
#include <vector>
#include <thread>

namespace Thread{


class Thread {

private:
      //std::thread thread;

public:
	Thread();
	virtual ~Thread();
	//Thread(Thread &&other);
	void start();
};

}

#endif /* THREAD_H_ */
