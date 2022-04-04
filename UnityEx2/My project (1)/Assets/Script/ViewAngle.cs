using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ViewAngle : MonoBehaviour
{
    public float Radius;
    [Range(0.0f, 180.0f)]
    public float Angle;

    [HideInInspector] public List<Transform> TargetList = new List<Transform>();
    [SerializeField] private LayerMask TargetMask;
    [SerializeField] private LayerMask ObstacleMask;

    void Start()
    {
        Radius = 10.0f;
        Angle = 45.0f;
    }

    void Update()
    {
        TargetList.Clear();

        Collider[] TargetColliders =
            Physics.OverlapSphere(transform.position, Radius, TargetMask);

        foreach(Collider Element in TargetColliders)
        {
            Vector3 Direction = (Element.transform.position - transform.position).normalized;

            if(Vector3.Angle(transform.forward, Direction) < Angle)
            {
                float Distance = Vector3.Distance(transform.position, Element.transform.position);
                if(!Physics.Raycast(transform.position, Direction, Distance, ObstacleMask))
                    TargetList.Add(Element.transform);
            }

        }

        
    }
}
