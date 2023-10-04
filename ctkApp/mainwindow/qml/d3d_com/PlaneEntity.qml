import QtQuick 2.15

import Qt3D.Core 2.10
import Qt3D.Render 2.10
import Qt3D.Input 2.0
import Qt3D.Extras 2.10

Entity {
    id: root

    PlaneMesh {
        id: mesh
        width: 30
        height: 20
    }

    PhongMaterial {
        id: material
        diffuse: "gray"
    }

    Transform {
        id: transform
    }

    components: [mesh, material, transform]
}
