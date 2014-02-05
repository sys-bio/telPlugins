#ifndef psParameterScanH
#define psParameterScanH
#include <vector>
#include "telProperty.h"
#include "telCPPPlugin.h"
#include "psParameterScanWorker.h"
#include "psArrayedParameter.h"
//---------------------------------------------------------------------------

using namespace tlp;
using std::string;
using std::vector;

class ParameterScan : public CPPPlugin
{
    friend class ParameterScanWorker;

    public:
        //Input
        Property<string>                        mSBML;
        Property<TelluriumData>				    mOutputData;

        //Output
        Property< ArrayedParameter >            mParameters;                        //Parameters to scan

    protected:
        ParameterScanWorker                     mWorker;

    public:
                                                ParameterScan();
                                               ~ParameterScan();
        bool                                    execute(bool inThread = false);
        bool                                    resetPlugin();
        string                                  getImplementationLanguage();
        bool                                    isWorking() const;
        unsigned char*                          getManualAsPDF() const;
        unsigned int                            getPDFManualByteSize();
        void                                    assignPropertyDescriptions();
};

extern "C"
{
RR_PLUGIN_DECLSPEC ParameterScan*   plugins_cc       createPlugin();
RR_PLUGIN_DECLSPEC const char*      plugins_cc       getImplementationLanguage();
}

#endif
