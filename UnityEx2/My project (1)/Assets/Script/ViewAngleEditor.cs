using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;

[CustomEditor(typeof(ViewAngle))]
public class ViewAngleEditor : Editor
{
    Vector3 GetAngle(float _Angle)
    {
        return new Vector3(Mathf.Sin(_Angle * Mathf.Deg2Rad),
            0.0f, Mathf.Cos(_Angle * Mathf.Deg2Rad));
    }

    private void OnSceneGUI()
    {
        ViewAngle Target = (ViewAngle)target;

        Handles.color = Color.white;

        Handles.DrawWireArc(Target.transform.position, Vector3.up, Vector3.forward, 360.0f, Target.Radius);

        Vector3 LeftViewAngle = GetAngle(-Target.Angle + Target.transform.eulerAngles.y);
        Vector3 RightViewAngle = GetAngle(Target.Angle + Target.transform.eulerAngles.y);

        Handles.DrawLine(Target.transform.position,
            Target.transform.position + LeftViewAngle * Target.Radius);
        Handles.DrawLine(Target.transform.position,
            Target.transform.position + RightViewAngle * Target.Radius);

        Handles.color = Color.red;
        foreach (Transform Element in Target.TargetList)
        {
            Handles.DrawLine(Target.transform.position, Element.transform.position);
        }
    }
}
