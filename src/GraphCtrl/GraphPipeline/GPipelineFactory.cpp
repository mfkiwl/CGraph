/***************************
@Author: Chunel
@Contact: chunel@foxmail.com
@File: GPipelineFactory.cpp
@Time: 2021/6/23 10:25 下午
@Desc: 
***************************/

#include "GPipelineFactory.h"

GPipelinePtrList GPipelineFactory::pipeline_list_;
std::mutex GPipelineFactory::lock_;

GPipelinePtr GPipelineFactory::create() {
    CGRAPH_LOCK_GUARD lock(lock_);

    GPipelinePtr pipeline = nullptr;
    while (!pipeline) {
        pipeline = new(std::nothrow) GPipeline();
    }
    pipeline_list_.emplace_back(pipeline);
    return pipeline;
}


void GPipelineFactory::destroy(GPipelinePtr pipeline) {
    if (nullptr == pipeline) {
        return;
    }

    CGRAPH_LOCK_GUARD lock(lock_);
    pipeline_list_.remove(pipeline);
    CGRAPH_DELETE_PTR(pipeline)
}


void GPipelineFactory::clear() {
    CGRAPH_LOCK_GUARD lock(lock_);

    for (GPipelinePtr pipeline : GPipelineFactory::pipeline_list_) {
        CGRAPH_DELETE_PTR(pipeline)
    }

    pipeline_list_.clear();
}


CSTATUS GPipelineFactory::run() {
    CGRAPH_NO_SUPPORT
}
