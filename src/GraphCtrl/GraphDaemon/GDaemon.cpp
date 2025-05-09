/***************************
@Author: Chunel
@Contact: chunel@foxmail.com
@File: GDaemon.cpp
@Time: 2022/2/3 1:19 下午
@Desc: 
***************************/

#include "GDaemon.h"

CGRAPH_NAMESPACE_BEGIN

CStatus GDaemon::init() {
    CGRAPH_FUNCTION_BEGIN
    timer_.start(interval_, [this] {
        daemonTask(param_);
    }, [this] {
        return modify(param_);
    });
    CGRAPH_FUNCTION_END
}


CStatus GDaemon::destroy() {
    CGRAPH_FUNCTION_BEGIN
    timer_.stop();
    CGRAPH_FUNCTION_END
}


CMSec GDaemon::getInterval() const {
    return interval_;
}


CMSec GDaemon::modify(GDaemonParamPtr param) {
    return 0;
}


CMSec GDaemon::__getInterval_4py() const {
    return getInterval();
}

CGRAPH_NAMESPACE_END
