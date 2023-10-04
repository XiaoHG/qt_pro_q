//----------------------------------------------
//概述
//- 请阅读QtHelp: Qt 3D Overview
//    https://www.kdab.com/overview-qt3d-2-0-part-1/
//    http://blog.csdn.net/iron_lzn/article/details/51363959
//- 上youtube 搜索 Qt 3D 视频
//－ 上kdab公司的网站，Qt3D的主要代码都是kdab公司提供的
//- 建模示例：https://www.kdab.com/qt-3d-animation-easter-teaser/
//----------------------------------------------
//功能
//    2D and 3D rendering     : 2d/3d渲染
//    Meshes and Geometry     : 面片和坐标
//    Materials               : 材质
//    Shaders                 : 着色器
//    Shadow mapping          : 阴影贴图（一种实时阴影技术）
//    Ambient occlusion       : 环境光遮蔽（一种全局光技术）
//    High dynamic range      : 高动态范围（HDR)
//    Deferred rendering      : 延迟渲染（一种多光源渲染技术）
//    Multitexturing          : 多材质
//    Instanced rendering     : 实例渲染
//    Uniform Buffer Objects  : 统一缓冲对象(HBO)

//相关库
//    QT += 3dcore 3drender 3dinput 3dlogic 3dextras
//    #include <Qt3DCore>
//    #include <Qt3DRender>
//    #include <Qt3DInput>
//    #include <Qt3DLogic>
//    #include <Qt3DExtras>
//    QT += 3dcore 3drender 3dinput 3dlogic 3dextras qml quick 3dquick
//    import Qt3D.Core 2.0      // 节点实体模型，基础变化
//    import Qt3D.Render 2.0    // 相机，缓冲，滤镜，图层，面片，光照，特效，材质，Shader，
//    import Qt3D.Input 2.0     // 输入
//    import Qt3D.Logic 2.0     // 每帧动画控制
//    import Qt3D.Extras 2.0    // 第一人称相机，轨道相机，反射贴图，基础模型等

//继承关系
//    Node                            // qt3d 所有类的基类
//        Entity                      //
//            Camera                  //
//        Component3D                 //
//            Layer                   //
//            Transform               //
//            CameraLens              //
//            ComputeCommand          //
//            FrameAction             //
//            InputSettings           //
//            KeyboardHandler         //
//            GeometryRenderer        //
//                Mesh                // 面片
//                ConeMesh            // 圆锥体 ConeMesh {bottomRadius: 0.05; topRadius: 0; length : 0.1; rings : 10; slices: 10},
//                CuboidMesh          // 长方体
//                CylinderMesh        // 圆柱体 CylinderMesh{length : size; radius : 0.05; rings : 10; slices: 10}
//                PlaneMesh           // 平面  PlaneMesh {width: 1.0; height: 1.0; meshResolution: Qt.size(2, 2)}
//                SphereMesh          // 球体  SphereMesh {radius: 1}
//                TorusMesh           // 三叶体
//            Light                   // 光照基类
//                DirectionLight      // 方向光（如太阳）
//                PointLight          // 电光源（如灯泡）
//                SportLight          // 聚光
//            Material                               //
//                Texture2D                          //
//                DiffuseMapMaterial                 // 漫反射贴图材质
//                DiffuseSpecularMapMaterial         // 漫反射高光贴图材质
//                GoochMaterial                      // Gooch shading model, popular in CAD and CAM applications
//                NormalDiffuseMapMaterial           //
//                NormalDiffuseMapAlphaMaterial      //
//                NormalDiffuseSpecularMapMaterial   //
//                PhongMaterial                      //
//                PhongAlphaMaterial                 //
//                PerVertexColorMaterial             //
//        AbstractTextureImage        //
//        Effect                      //
//        FilterKey                   //
//        FrameGraphNode              // FrameGraph 配置基类，用于控制渲染
//            LayerFilter             // 层过滤（只显示指定层的对象）
//            CameraSelector          // 相机选择器
//            ClearBuffers            // enables clearing of the specific render target buffers with specific values
//            DispatchCompute         // FrameGraph node to issue work for the compute shader on GPU
//            FrustumCulling          // enables frustum culling of the drawable entities based on the camera view and Geometry bounds of the entities
//            NoDraw                  // Prevents from drawing anything
//            RenderCapture           // Used to request render capture. User can specify a captureId to identify the request.
//            RenderSurfaceSelector   // be used to select the surface
//            RenderTargetSelector    // s used to select active RenderTarget for the FrameGraph
//            RenderPassFilter        //
//            RenderStateSet          //
//            SortPolicy              //
//            TechniqueFilter         //
//            Viewport                //
//        KeyboardDevice              //
//        RenderPass                  //
//        RenderState                 //
//        RenderTargetOutput          //
//        ShaderPrograme
//        CameraController
//            FirstPersonCameraController  // 第一人称相机控制器（类似cs）
//            OrbitCameraController        // 轨道相机控制器（围绕物体旋转）
//        Geometry                    //
//            ConeGeometry            // allows creation of a cone in 3D space
//            CuboidGeometry          // allows creation of a cuboid in 3D space.
//            CylinderGeometry        //
//            PlaneGeometry           //
//            SphereGeometry          //
//            TorusGeometry           //


//eg
//    CuboidMesh {
//        id: mesh
//        property real multiplier: 0.0256
//        xExtent: 512 * multiplier
//        yExtent: 768 * multiplier
//        zExtent: 2.0
//        yzMeshResolution: Qt.size(20, 20)
//        xzMeshResolution: Qt.size(20, 20)
//        xyMeshResolution: Qt.size(20, 20)
//    }

//显示OpenGL版本
//    Rectangle {
//        color: "black"
//        Text {
//            color: "white"
//            anchors.centerIn: parent
//            text: "Open%4 %1.%2 %3"
//                .arg(OpenGLInfo.majorVersion)
//                .arg(OpenGLInfo.minorVersion)
//                .arg({0: "NoProfile", 1: "CoreProfile", 2: "CompatibilityProfile"}[OpenGLInfo.profile])
//                .arg({0: "Unspecified", 1: "GL", 2: "GLES"}[OpenGLInfo.renderableType])
//            styleColor: "#8b8b8b"
//            style: Text.Sunken
//            font.pointSize: 24
//            onTextChanged: {
//                Resources.setGlInfo(OpenGLInfo);
//            }
//        }
//    }

//----------------------------------------------
//Scene3D
//提供3d运行场景，嵌在普通qml中
//----------------------------------------------
//属性
//    activeCamera : Camera3D
//    activeLight : Light3D
//    devicePixelRatio : float
//    graphPositionQuery : point
//    invalidSelectionPoint : point
//    primarySubViewport : rect
//    secondarySubViewport : rect
//    secondarySubviewOnTop : bool
//    selectionQueryPosition : point
//    slicingActive : bool
//    viewport : rect

//示例
//    Scene3D {
//      id: scene3d
//      anchors.fill: parent
//      anchors.margins: 10
//      focus: true
//      aspects: ["input", "logic"]
//      cameraAspectRatioMode: Scene3D.AutomaticAspectRatio
//      AnimatedEntity {}
//    }



//----------------------------------------------
//Entity
//Entity有个属性component，里面可以容纳 Mesh, Transformation, Audio, Material.....，
//这是一种很灵活的方式，可简化3d对象类的层次，也便于扩展。
//----------------------------------------------
//标准写法
//    Entity {
//        components: [
//            Mesh {source: "assets/obj/toyplane.obj"},
//            PhongMaterial {diffuse: "white"; shininess: 50}
//        ]
//    }

//从文件中加载场景
//    Entity {
//        components: [
//            SceneLoader {source: "qrc:/assets/test_scene.dae"}
//        ]
//    }


//----------------------------------------------
//Camera
//import Qt3D.Core 2.0
//import Qt3D.Render 2.0
//----------------------------------------------
//第一人称三角透视相机
//    Camera {
//        id: mainCamera
//        objectName: "mainCamera"
//        projectionType: CameraLens.PerspectiveProjection
//        fieldOfView: 22.5
//        aspectRatio: _window.width / _window.height
//        onAspectRatioChanged: console.log( "aspectRatio = " + aspectRatio )
//        nearPlane:   0.01
//        farPlane:    1000.0
//        viewCenter: Qt.vector3d( 0.0, 0.0, 0.0 )
//        upVector:   Qt.vector3d( 0.0, 1.0, 0.0 )
//    }
//    FirstPersonCameraController { camera: mainCamera }


//轨道透视相机（右键按住拖动，可对准原点旋转相机）
//    components: [
//        RenderSettings {
//            activeFrameGraph: ForwardRenderer {
//                clearColor: Qt.rgba(0, 0.5, 1, 1)
//                camera: camera
//            }
//        },
//        InputSettings { }
//    ]
//    Camera {
//        id: camera
//        projectionType: CameraLens.PerspectiveProjection
//        fieldOfView: 45
//        aspectRatio: 16/9
//        nearPlane : 0.1
//        farPlane : 1000.0
//        position: Qt.vector3d( 0.0, 0.0, -40.0 )
//        upVector: Qt.vector3d( 0.0, 1.0, 0.0 )
//        viewCenter: Qt.vector3d( 0.0, 0.0, 0.0 )
//    }
//    OrbitCameraController { camera: camera}

//多角度观测
//    Viewport {
//          id: mainViewport
//          normalizedRect: Qt.rect(0, 0, 1, 1)
//          ClearBuffers {
//              buffers: ClearBuffers.ColorDepthBuffer
//          }

//          Viewport {
//              id: topLeftViewport
//              normalizedRect: Qt.rect(0, 0, 0.5, 0.5)
//              CameraSelector { id: cameraSelectorTopLeftViewport }
//          }
//          Viewport {
//              id: topRightViewport
//              normalizedRect: Qt.rect(0.5, 0, 0.5, 0.5)
//              CameraSelector { id: cameraSelectorTopRightViewport }
//          }
//          Viewport {
//              id: bottomLeftViewport
//              normalizedRect: Qt.rect(0, 0.5, 0.5, 0.5)
//              CameraSelector { id: cameraSelectorBottomLeftViewport }
//          }
//          Viewport {
//              id: bottomRightViewport
//              normalizedRect: Qt.rect(0.5, 0.5, 0.5, 0.5)
//              CameraSelector { id: cameraSelectorBottomRightViewport }
//          }
//      }




//----------------------------------------------
//Light
//----------------------------------------------
//方向光（平行光，如太阳）
//    Enity {
//        components: [
//            DirectionalLight {
//                worldDirection: Qt.vector3d(0.3, -3.0, 0.0).normalized();
//                color: "#fbf9ce"
//                intensity: 0.3
//            }
//        ]
//    }

//点光源（如灯泡）
//    Entity {
//        components: [
//            PointLight {
//                color: "red"
//                intensity: 0.3
//                constantAttenuation: 1.0
//                linearAttenuation: 0.0
//                quadraticAttenuation: 0.0025
//            }
//        ]
//    }

//聚光（如舞台聚光灯）
//    Entity {
//        components: [
//            SpotLight {
//                localDirection: Qt.vector3d(0.0, -1.0, 0.0)
//                color: "white"
//                intensity: 0.6
//            }
//        ]
//    }





//----------------------------------------------
//Material（材质）
//贴图相关概念
//    https://zhidao.baidu.com/question/167602912.html
//    http://www.cnblogs.com/xiuj/p/5875461.html
//    -------------------------------------------
//    ambient                 : 环境色。物体自己发出的光。
//    diffuse map             : 漫反射贴图(色彩贴图）, 它的作用是给模型上颜色和材质
//    specular map            : 高光贴图，不同材质，在光照下，它们的反射光的强弱都不同
//    normal map              : 法线贴图.用来表现凹凸
//    -------------------------------------------
//    gloss map               : 指示着色器对物体的表面的某些部分着色更亮一点，某些部分更暗一点，因为Gloss Maps只需要单通道, 可用alpha通道的图或灰度图
//    emboss bump map         : 做表面的浮雕效果的
//    opacity map             : 透明贴图。透明通道制作头发或者损坏的衣服布料等等可以用到
//    shininess               : 光泽（0-1）
//    lighting map 和 AO map  : 让材质制作更加逼真，更加方便
//Qt3D中材质
//    用Material组件编写
//    提供了几种材质组件，通常是几种贴图方式的组合
//        PhongMaterial
//        DiffuseMapMaterial
//        NormalDiffuseMapMaterial
//        GoochMaterial
//----------------------------------------------
//简单色彩材质
//    色彩材质
//        ColorMaterial{
//            diffuseColor: Qt.rgba(0.2, 0.5, 0.3, 1.0)
//            specularColor: Qt.rgba(0, 0, 0, 1.0)
//        }
//    Phong 基础光照模型材质
//        PhongMaterial {
//            ambient: Qt.rgba( 0.02, 0.02, 0.02, 1.0 )
//            diffuse: Qt.rgba( 0.8, 0.0, 0.0, 1.0 )
//            specular: Qt.rgba( 0.8, 0.0, 0.0, 1.0 )
//            shininess: 1.0
//        }
//    PhongAlphaMaterial（带透明通道的基础Phong光照模型材质）
//        PhongMaterial {
//            ambient: Qt.rgba( 0.02, 0.02, 0.02, 1.0 )
//            diffuse: Qt.rgba( 0.8, 0.0, 0.0, 1.0 )
//            specular: Qt.rgba( 0.8, 0.0, 0.0, 1.0 )
//            shininess: 1.0
//            alpha: 0.8
//        }
//    GoochMaterial
//        Gooch光照渲染模型。
//        常用于CAD和CAM程序，完全拟真不是该模型的目标，
//        该模型同时使用 color 和 brightness 来显示3d表面的弯曲部分;
//        该模型混合了漫反射光／冷光／暖光来产生渐变色带，冷光和暖光分别由alpha和beta参数影响。色带区间：[cool + alpha * diffuse, warm + beta * diffuse]
//        参数
//            shininess : real
//            diffuse : color
//            specular : color
//            coolColor : color
//            warmColor : color
//            alpha : real
//            beta : real
//    PerVertexColorMaterial
//        Default implementation for rendering the color properties set for each vertex
//        帮助上没有任何参数



//漫反射贴图材质（Phong光照模型)
//    漫反射贴图材质（漫反射由贴图提供）
//        DiffuseMapMaterial {
//            diffuse: "assets/chest/diffuse.webp"
//            specular: Qt.rgba( 0.2, 0.2, 0.2, 1.0 )
//            shininess: 2.0
//            ambient: color
//            textureScale: 1.0
//        }
//    漫反射高光贴图材质（漫反射和高光均有贴图提供）
//        DiffuseSpecularMapMaterial{
//            diffuse: "assets/chest/diffuse.webp"
//            specular: "assets/chest/specular.webp"
//            shininess: 2.0
//            ambient: color
//            textureScale: 1.0
//        }


//凹凸贴图材质（用贴图来模拟细节，减小建模复杂度）
//    法线漫反射贴图材质（实现了phong光照和凹凸贴图模型）
//        NormalDiffuseMapMaterial {
//            ambient: Qt.rgba( 0.05, 0.05, 0.05, 1.0 )
//            shininess: 5.0
//            textureScale: 1.0
//            diffuse: "assets/houseplants/pot.webp"
//            normal: "assets/houseplants/pot_normal.webp"
//            specular: Qt.rgba( 0.75, 0.75, 0.75, 1.0 )
//            }
//    法线漫反射贴图质（和前一个的区别？）
//        NormalDiffuseMapAlphaMaterial {
//            ambient: Qt.rgba( 0.05, 0.05, 0.05, 1.0 )
//            shininess: 1.0
//            textureScale: 1.0
//            diffuse: "qrc:/images/songtitle.png"
//            normal: "qrc:/images/normalmap.png"
//            specular: color
//            }
//    法线漫反射高光贴图材质（高光可以指定贴图）
//        NormalDiffuseSpecularMapMaterial {
//            ambient: Qt.rgba( 0.05, 0.05, 0.05, 1.0 )
//            shininess: 10.0
//            textureScale: 10.0
//            diffuse:  "assets/textures/pattern_09/diffuse.webp"
//            normal:   "assets/textures/pattern_09/normal.webp"
//            specular: "assets/textures/pattern_09/specular.webp"
//            }


//自定义材质（使用Shader技术实现）
//    示例1
//        Material {
//            id: instancedPhongMaterial
//            effect: Effect {
//                techniques: Technique {
//                    graphicsApiFilter {
//                        api: GraphicsApiFilter.OpenGL
//                        profile: GraphicsApiFilter.CoreProfile
//                        minorVersion: 2
//                        majorVersion: 3
//                    }
//                    filterKeys: FilterKey { name: "renderingStyle"; value: "forward" }
//                    renderPasses: RenderPass {
//                        shaderProgram: ShaderProgram {
//                            vertexShaderCode: loadSource("qrc:/instanced.vert")
//                            fragmentShaderCode: loadSource("qrc:/instanced.frag")
//                        }
//                    }
//                }
//            }
//        }
//    线框材质
//        请查看官方示例“Wireframe qml example”
//        WireframeMaterial {
//            id: wireframeMaterial
//            effect: WireframeEffect {}
//            ambient: Qt.rgba( 0.2, 0.0, 0.0, 1.0 )
//            diffuse: Qt.rgba( 0.8, 0.0, 0.0, 1.0 )
//        }
//    详见官方示例：Planets qml example
//    Texture2D {
//          id: diffuseTexture
//          minificationFilter: Texture.LinearMipMapLinear
//          magnificationFilter: Texture.Linear
//          wrapMode {
//              x: WrapMode.Repeat
//              y: WrapMode.Repeat
//          }
//          generateMipMaps: true
//          maximumAnisotropy: 16.0
//          TextureImage {source: "qrc:/texturePalette.png"}
//     }


//----------------------------------------------
//Layer(QLayer>)
//类似ps中的图层，可在程序中控制某些图层显示隐藏
//----------------------------------------------
//  import Qt3D.Core 2.0
//  import Qt3D.Render 2.0
//  Entity {
//      id: root
//      components: RenderSettings {
//          Viewport {
//              ClearBuffers {
//                  buffers: ClearBuffers.ColorDepthBuffer
//                  CameraSelector {
//                      camera: mainCamera
//                      LayerFilter {layers: [layer1]}
//                  }
//              }
//          }
//      }
//      Camera { id: mainCamera }

//      // scene
//      Entity {
//          id: renderableEntity
//          components: [ mesh, layer1 ]
//      }
//      Layer { id: layer1 }
//      GeometryRenderer { id: mesh }
//  }




//----------------------------------------------
//TechniqueFilter e
//----------------------------------------------
//import Qt3D.Core 2.0
//import Qt3D.Render 2.0
//TechniqueFilter {
//    property alias camera: cameraSelector.camera
//    property alias window: surfaceSelector.surface

//    id: root
//    objectName : "techniqueFilter"
//    matchAll: [ FilterKey { name: "renderingStyle"; value: "forward" } ]  // Select the forward rendering Technique of any used Effect

//    RenderSurfaceSelector {
//        id: surfaceSelector
//        Viewport {
//            id: viewport
//            objectName : "viewport"
//            normalizedRect: Qt.rect(0.0, 0.0, 1.0, 1.0)
//            CameraSelector {
//                id : cameraSelector
//                objectName : "cameraSelector"
//                ClearBuffers {
//                    buffers : ClearBuffers.ColorDepthBuffer
//                    clearColor: "black"
//                    SortPolicy {
//                        sortTypes: [
//                            SortPolicy.StateChangeCost,
//                            SortPolicy.Material
//                        ]
//                    }
//                }
//            }
//        }
//    }
//}


//----------------------------------------------
//AspectEngine
//----------------------------------------------
//3d模拟是AspectEngine来执行等
//AbstractAspect
//    Behavior 处理组件数据

//RenderAspect
//InputAspect
//LoginAspect




//----------------------------------------------
//FrameGraph & ViewPort & Layer
//描述了后期处理逻辑，如：阴影／透明／后期处理／多视图/选择渲染
//import Qt3D.Core 2.0
//import Qt3D.Render 2.0
//----------------------------------------------
//默认的RenderSetting
//    Entity {
//        Camera { id:camera ... }
//        FirstPersonCameraController {camera:camera}
//        components: [
//            RenderSetting{
//                activeFrameGraph : ForwardRenderer {camera:camera, clearColor:"transparent"},
//                InputSetting{}
//            }
//        ]
//        ...
//    }

//自定义RenderSetting（多视图）
//    RenderSettings {
//      id: quadViewportFrameGraph
//      property alias topLeftCamera: cameraSelectorTopLeftViewport.camera;
//      property alias topRightCamera: cameraSelectorTopRightViewport.camera;
//      property alias bottomLeftCamera: cameraSelectorBottomLeftViewport.camera;
//      property alias bottomRightCamera: cameraSelectorBottomRightViewport.camera;
//      property alias window: surfaceSelector.surface

//      activeFrameGraph: RenderSurfaceSelector {
//          id: surfaceSelector
//          Viewport {
//              id: mainViewport
//              normalizedRect: Qt.rect(0, 0, 1, 1)

//              ClearBuffers {
//                  buffers: ClearBuffers.ColorDepthBuffer
//              }

//              Viewport {
//                  id: topLeftViewport
//                  normalizedRect: Qt.rect(0, 0, 0.5, 0.5)
//                  CameraSelector { id: cameraSelectorTopLeftViewport }
//              }

//              Viewport {
//                  id: topRightViewport
//                  normalizedRect: Qt.rect(0.5, 0, 0.5, 0.5)
//                  CameraSelector { id: cameraSelectorTopRightViewport }
//              }

//              Viewport {
//                  id: bottomLeftViewport
//                  normalizedRect: Qt.rect(0, 0.5, 0.5, 0.5)
//                  CameraSelector { id: cameraSelectorBottomLeftViewport }
//              }

//              Viewport {
//                  id: bottomRightViewport
//                  normalizedRect: Qt.rect(0.5, 0.5, 0.5, 0.5)
//                  CameraSelector { id: cameraSelectorBottomRightViewport }
//              }
//          }
//      }
//  }

//选择图层渲染
//    RenderSurfaceSelector{
//        RenderTargetSelector{
//            target: sceneTarget
//            CameraSelector{
//                camera: mainCamera
//                ClearBuffer {
//                    buffers: ClearBuffers.ColorDepthBuffer
//                    clearColor: "white"
//                    NoDraw{}
//                }
//                LayerFilter{
//                    layers: [objectsLayer]
//                    RenderPassFilter{
//                        matchAny: FilterKey{name: "renderPass"; value: "allObjects"}
//                    }
//                }
//                LayerFilter{
//                    layers: [enviromentLayer]
//                }
//            }
//        }
//    }


//----------------------------------------------
//CustomMaterial & Effect
//----------------------------------------------
//import Qt3D.Core 2.0
//import Qt3D.Render 2.0
//Material {
//    // 定义材质的参数
//    id: root
//    property color ambient: Qt.rgba( 0.05, 0.05, 0.05, 1.0 )
//    property color diffuse: Qt.rgba( 0.7, 0.7, 0.7, 1.0 )
//    property color specular: Qt.rgba( 0.95, 0.95, 0.95, 1.0 )
//    property real shininess: 150.0
//    property real lineWidth: 0.8
//    property color lineColor: Qt.rgba( 0.0, 0.0, 0.0, 1.0 )
//    parameters: [
//        Parameter { name: "ka"; value: Qt.vector3d(root.ambient.r, root.ambient.g, root.ambient.b) },
//        Parameter { name: "kd"; value: Qt.vector3d(root.diffuse.r, root.diffuse.g, root.diffuse.b) },
//        Parameter { name: "ks"; value: Qt.vector3d(root.specular.r, root.specular.g, root.specular.b) },
//        Parameter { name: "shininess"; value: root.shininess },
//        Parameter { name: "line.width"; value: root.lineWidth },
//        Parameter { name: "line.color"; value: root.lineColor }
//    ]

//    // 具体的效果实现逻辑（使用Shader实现）
//    effect: Effect {
//        parameters: [
//            Parameter { name: "ka";  value: Qt.vector3d( 0.1, 0.1, 0.1 ) },
//            Parameter { name: "kd";  value: Qt.vector3d( 0.7, 0.7, 0.7 ) },
//            Parameter { name: "ks";  value: Qt.vector3d( 0.95, 0.95, 0.95 ) },
//            Parameter { name: "shininess"; value: 150.0 }
//        ]
//        techniques: [
//            Technique {
//                graphicsApiFilter {
//                    api: GraphicsApiFilter.OpenGL
//                    profile: GraphicsApiFilter.CoreProfile
//                    majorVersion: 3
//                    minorVersion: 1
//                }
//                filterKeys: [ FilterKey { name: "renderingStyle"; value: "forward" } ]
//                parameters: [
//                    Parameter { name: "light.position"; value: Qt.vector4d( 0.0, 0.0, 0.0, 1.0 ) },
//                    Parameter { name: "light.intensity"; value: Qt.vector3d( 1.0, 1.0, 1.0 ) },
//                    Parameter { name: "line.width"; value: 1.0 },
//                    Parameter { name: "line.color"; value: Qt.vector4d( 1.0, 1.0, 1.0, 1.0 ) }
//                ]
//                // 渲染通道
//                renderPasses: [
//                    RenderPass {
//                        shaderProgram: ShaderProgram {
//                            vertexShaderCode:   loadSource("qrc:/Materials/Shaders/robustwireframe.vert")
//                            geometryShaderCode: loadSource("qrc:/Materials/Shaders/robustwireframe.geom")
//                            fragmentShaderCode: loadSource("qrc:/Materials/Shaders/robustwireframe.frag")
//                        }
//                    }
//                ]
//            }
//        ]
//    }
//}
//shader 详见Qt3D.Shader章节




//----------------------------------------------
//ObjectPicker & animation(5.9)
//https://www.kdab.com/qt-3d-animation-easter-teaser/
//ClipAnimator 5.9 提供。可加载设计好的动画
//----------------------------------------------
//Entity {
//    id: cube
//    components: [
//        Transform {
//            id: cubeTransform
//        },
//        Mesh {
//            source: "qrc:/assets/egg/egg.obj"
//        },
//        TexturedMetalRoughMaterial {
//            baseColor: TextureLoader {
//                format: Texture.SRGB8_Alpha8
//                source: "qrc:/assets/egg/basecolor.png"
//            }
//            metalness: TextureLoader { source: "qrc:/assets/egg/metalness.png" }
//            roughness: TextureLoader { source: "qrc:/assets/egg/roughness.png" }
//            normal: TextureLoader { source: "qrc:/assets/egg/normal.png" }
//            ambientOcclusion: TextureLoader { source: "qrc:/assets/egg/ambientocclusion.png" }
//        },
//        ObjectPicker {
//            onClicked: animator.running = true
//        },
//        ClipAnimator {
//            id: animator
//            loops: 3
//            clip: AnimationClipLoader { source: "qrc:/jumpinganimation.json" }
//            channelMapper: ChannelMapper {
//                mappings: [
//                    ChannelMapping { channelName: "Location"; target: cubeTransform; property: "translation" },
//                    ChannelMapping { channelName: "Rotation"; target: cubeTransform; property: "rotation" },
//                    ChannelMapping { channelName: "Scale"; target: cubeTransform; property: "scale3D" }
//                ]
//            }
//        }
//    ]
//}




//----------------------------------------------
//-- 批量生成对象
//----------------------------------------------
//   NodeInstantiator {
//      id: collection
//      property int maxCount: parent.numberOfBars
//      model: maxCount
//      delegate: BarEntity {
//          id: cubicEntity
//          entityMesh: CuboidMesh {xExtent: 0.1; yExtent: 0.1; zExtent: 0.1}
//          rotationTimeMs: sceneRoot.barRotationTimeMs
//          entityIndex: index
//          entityCount: sceneRoot.numberOfBars
//          entityAnimationsState: animationState
//          magnitude: 0
//      }
//    }

//    NodeInstantiator {
//        id: grid
//        model: rows * columns
//        property int rows: 6
//        property int columns: 11

//        Entity {
//            property int _row: index / grid.columns
//            property int _col: index % grid.columns

//            components: [ sphereTransform, sphereMesh, sphereMaterial ]
//            SphereMesh {
//                id: sphereMesh
//                slices: 60
//                rings: 60
//                radius: 0.65
//            }
//            Transform {
//                id: sphereTransform
//                translation: Qt.vector3d(-7.5 + _col * 1.5, -4.0 + _row * 1.5, 0)
//            }
//            MetalRoughMaterial {
//                id: sphereMaterial
//                baseColor: scene.baseColor
//                metalness: 0.2 * _row
//                roughness: 0.1 * _col
//            }
//        }
//    }


//----------------------------------------------
//-- 杂
//----------------------------------------------
//KeyboardInput
//    可响应键盘消息


//LogicComponent
//    可设置逻辑。如物体位置／精灵创建／离屏销毁等。


//FrameGraph
//    如何渲染场景


//CameraSelector NoDraw
//    Viewport {
//      CameraSelector {
//          ClearBuffers {
//              buffers: ClearBuffers.ColorDepthBuffer
//              NoDraw { } // Prevents from drawing anything
//          }
//          RenderPassFilter {
//              ...
//          }
//          RenderPassFilter {
//              ...
//          }
//      }
//    }

//ClearBuffers
//    ClearBuffers {
//      buffers: ClearBuffers.DepthBuffer
//      CameraSelector {
//          id: lightCameraSelector
//      }
//    }


//--------------------------------------------------
//三维旋转控制
//--------------------------------------------------
//    // 旋转
//    Transform {
//        id: modelTransform
//        property real angle: 0
//        matrix: {
//            var m = cameraMatrix.inverted();
//            m.translate(Qt.vector3d(6,
//                                    -4 - (1.0 - showDetailsTransitionState) * 10,
//                                    -20 * showDetailsTransitionState));
//            m.rotate(modelTransform.angle, Qt.vector3d(0, 1, 0));  // 动画绕y轴旋转360度
//            m.rotate(15, Qt.vector3d(0, 0, 1)); // 沿z轴倾斜15度
//            return m;
//        }
//    }

//    //
//    Transform {
//        id: cameraRotationTransform
//        matrix: {
//            var m = Qt.matrix4x4();
//            m.rotate(-19 * window.carouselOffset, Qt.vector3d(0.0, 1.0, 0.0));
//            m.rotate(5 * mainCamera.roll, Qt.vector3d(0.0, 0.0, 1.0));
//            m.lookAt(Qt.vector3d( 0.0, 0.0, 0.0 ),
//                     Qt.vector3d(-40 * Math.sin(mainCamera.yaw), mainCamera.roll * 3, -40 * Math.cos(mainCamera.yaw) ),
//                     Qt.vector3d( 0.0, 1.0, 0.0 ));
//            return m;
//        }
//    }

//    Transform {
//        id: modelTransform
//        matrix: {
//            var m = cameraMatrix.inverted();
//            m.translate(Qt.vector3d(0.0, -1.5 + (1.5 * showDetailsTransitionState), -40));
//            m.rotate(40 * Math.min(1.0, showDetailsTransitionState * 1.5), Qt.vector3d(0, 1, 0));
//            m.translate(Qt.vector3d(-25 * Math.max(0, showDetailsTransitionState - 0.4), 0.0, 0.0));
//            return m;
//        }
//    }
//--------------------------------------------------
//贴图位置的控制
//--------------------------------------------------
//import Qt3D.Core 2.0
//import Qt3D.Render 2.0
//Texture2D {
//    property alias source: image.source
//    minificationFilter: Texture.LinearMipMapLinear
//    magnificationFilter: Texture.Linear
//    generateMipMaps: true
//    wrapMode {
//        x: WrapMode.ClampToEdge
//        y: WrapMode.ClampToEdge
//    }
//    TextureImage {
//        id: image
//    }
//}
