#include "SonarCtrl.h"

SonarCtrl::SonarCtrl()
{
    init();
}

void SonarCtrl::init()
{
    m_isStarted = false;
}

void SonarCtrl::OnBnClickedStart()
{
    if (!m_isStarted)
    {
        //m_frame->m_ctrloper.oper_cmd=1;
        //m_frame->SendCtrlPara();
        m_isStarted=true;
        //Sleep(50);
        //m_comb_trigerMode.EnableWindow(false);
        m_frame->StartSonar();
        ////m_frame->SendCtrlOper();
        //if (m_frame->m_operMode==1)
        //{
        //	//if (m_frame->m_language==0)
        //	//	m_startstop_BT.SetWindowText(_T("Stop"));
        //	//else
        //	//	m_startstop_BT.SetWindowText(_T("停止"));
        //}
        //else
        //{
        //	m_isStarted=false;
        //}
        m_start_BT.EnableWindow(false);
        m_stop_BT.EnableWindow(true);
        //m_btSingle.EnableWindow(false);

    }
}

void SonarCtrl::OnBnClickedStop()
{

}


