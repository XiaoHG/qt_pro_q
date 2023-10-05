import QtQuick 2.15

import Qt3D.Core 2.10
import Qt3D.Render 2.10
import Qt3D.Input 2.0
import Qt3D.Extras 2.10

Entity {
    id: root

    PlaneEntity {
        id: planeEntity

        Transform {
            id: tForm
        }

        CuboidMesh {
            id: cMesh
        }

        PhongMaterial {
            id: pMaterial
        }

        components: [ tForm, cMesh, pMaterial ]
    }
}
