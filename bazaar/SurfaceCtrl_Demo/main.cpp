#include "SurfaceCtrl_Demo.h"


namespace Upp{
	SurfaceCtrl_Demo::SurfaceCtrl_Demo()
	{
		CtrlLayout(*this, "SurfaceCtrl demo. STL viewer");
		filename.SetText( GetFileDirectory(__FILE__) + "Stanford_Bunny_sample.stl" );
				
		butOpen.WhenAction = [&] {
			try {

				Object3D& obj = canvas.CreateObject();
				obj.LoadModel(~filename).AttachTexture(obj.InsertTexture(TM_WATER),0,1).GenerateTextureCoordinate(0,1).Init();
				//obj.LoadModel(~filename).Init();

				obj.GetTransform().Rotate(90.0f,glm::vec3(1.0f,0.0f,0.0f));
				obj.GetTransform().SetScale(glm::vec3(1.0f,1.0f,1.0f));
				obj.SetLineWidth(2.0f);
				
				canvas.SetDefaultShader(obj);
				
				canvas.Refresh();
			} catch (Exc e) {
				Exclamation(DeQtf(e));
			}
		};
		OpenEarth.WhenAction = [&]{
			try {
				Object3D& obj = canvas.CreateObject();
				obj.LoadModel(GetFileDirectory(__FILE__) + "Earth 2K.obj").AttachTexture(obj.InsertTexture(GetFileDirectory(__FILE__) + "Diffuse_2K.png"),0,obj.GetMeshes().GetCount()).Init();
				canvas.SetDefaultShader(obj);
				canvas.Refresh();
			} catch (Exc e) {
				Exclamation(DeQtf(e));
			}
		};
		
		canvas.WhenPaint = [&] {
			canvas.DrawAllObjects();
		};
		Sizeable().Zoomable();
	}
	
	void SurfaceCtrl_Demo::Layout(){
		canvas.GLResize(GetSize().cx,GetSize().cy);
	}
	
	bool SurfaceCtrl_Demo::Key(dword key, int count){
		return canvas.Key(key,count);
	}
}

GUI_APP_MAIN
{
	Upp::StdLogSetup( Upp::LOG_COUT | Upp::LOG_FILE);
	Upp::SurfaceCtrl_Demo().Run();
}
