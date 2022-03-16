using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class billboard : MonoBehaviour
{
    [SerializeField] GameObject _player = null;
    float zValue = 0;

    void Start()
    {
        zValue = this.transform.position.z;
    }

    void Update()
    {
        this.transform.position = new Vector3(_player.transform.position.x,
            _player.transform.position.y, zValue);
    }
}
