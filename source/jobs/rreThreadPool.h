#ifndef rreThreadPoolH
#define rreThreadPoolH
#include <list>
#include <vector>
#include "rreRoadRunnerThread.h"
//---------------------------------------------------------------------------

namespace rre
{
using namespace std;

class RRE_DECLSPEC ThreadPool
{
    protected:
        list<RoadRunnerThread*>         mThreads;

    public:
                                        ThreadPool();
        virtual                        ~ThreadPool();
        void                            addJob(RoadRunner* rri);
        bool                            isJobQueueEmpty();
        int                             getNumberOfRemainingJobs();
        bool                            isWorking();
        void                            start();
        void                            exitAll();
        void                            waitForStart();
        void                            waitForFinish();
};

}
#endif
