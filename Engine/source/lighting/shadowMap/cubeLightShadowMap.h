//-----------------------------------------------------------------------------
// Copyright (c) 2012 GarageGames, LLC
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//-----------------------------------------------------------------------------

#ifndef _CUBELIGHTSHADOWMAP_H_
#define _CUBELIGHTSHADOWMAP_H_

#ifndef _LIGHTSHADOWMAP_H_
#include "lighting/shadowMap/lightShadowMap.h"
#endif
#ifndef _GFXCUBEMAP_H_
#include "gfx/gfxCubemap.h"
#endif


class CubeLightShadowMap : public LightShadowMap
{
   typedef LightShadowMap Parent;

public:

   CubeLightShadowMap( LightInfo *light );

   // LightShadowMap
   bool hasShadowTex() const override { return mCubemap.isValid(); }
   ShadowType getShadowType() const override { return ShadowType_CubeMap; }
   void _render( RenderPassManager* renderPass, const SceneRenderState *diffuseState ) override;
   void setShaderParameters( GFXShaderConstBuffer* params, LightingShaderConstants* lsc ) override;
   void releaseTextures() override;
   bool setTextureStage( U32 currTexFlag, LightingShaderConstants* lsc ) override;

protected:   

   /// The shadow cubemap.
   GFXCubemapHandle mCubemap;

};

#endif // _CUBELIGHTSHADOWMAP_H_
