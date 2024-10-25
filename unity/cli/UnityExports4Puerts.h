﻿/*
 * Tencent is pleased to support the open source community by making Puerts available.
 * Copyright (C) 2020 THL A29 Limited, a Tencent company.  All rights reserved.
 * Puerts is licensed under the BSD 3-Clause License, except for the third-party components listed in the file 'LICENSE' which may
 * be subject to their corresponding license terms. This file is subject to the terms and conditions defined in file 'LICENSE',
 * which is part of this source code package.
 */

#pragma once
namespace puerts
{

#if defined(USE_OUTSIZE_UNITY)

typedef void* (*GetJsClassInfoFunc)(const void* TypeId, bool TryLazyLoad);

typedef const void* (*CSharpTypeToTypeIdFunc)(const void *type);

#else
    
typedef struct JsClassInfoHeader* (*GetJsClassInfoFunc)(const void* TypeId, bool TryLazyLoad);

typedef const void* (*CSharpTypeToTypeIdFunc)(Il2CppObject *type);

#endif

typedef void(*LogCallbackFunc)(const char* value);

struct UnityExports
{
    //.cpp api
    CSharpTypeToTypeIdFunc CSharpTypeToTypeId = nullptr;

    //plugin api
    GetJsClassInfoFunc GetJsClassInfo = nullptr;
    
    LogCallbackFunc LogCallback = nullptr;
};

}