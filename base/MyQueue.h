#ifndef _MY_QUEUE_H_
#define _MY_QUEUE_H_
#include "mq.h"
#include <iostream>
#include <string>

namespace MyNameSpace
{
	class MyQueue
	{
		public:
			void pushMsg(int len, char *msg)
			{
				queue.pushMsg(len, msg);
			}
			void processMsg()
			{
				MsgPair *tmp = NULL;
				int i = 0;
				while (tmp = queue.getMsg())
				{
					cmdParse(tmp->second, tmp->first);
					queue.pop();
					++i;
				}
//				std::cout << i << std::endl;
			}
			virtual bool cmdParse(const char *msg, int len) = 0;
		private:
			MessageQueue<1024> queue;
	};

	/*
	   class MyClass : public MyQueue
	   {
	   public:
	   virtual void cmdParse(int len, char *msg)
	   {
	   string s;
	   s.assign(msg, len);
	   cout << "len:" << len << "msg:" << s << endl;
	   }
	   };
	   */

}
#endif