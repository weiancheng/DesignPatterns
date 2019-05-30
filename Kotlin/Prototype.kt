interface Profile {
    fun show()
    fun clone(): Profile
}

class Vector3(x: Float, y: Float, z: Float): Profile {
    private val x = x
    private val y = y
    private val z = z
    override public fun show() {
        println("x: " + x + ", y: " + y + ", z: " + z)
    }
    override public fun clone(): Profile {
        return Vector3(x, y, z)
    }
}

class Rotation(w: Float, x: Float, y: Float, z: Float): Profile {
    private val w = w
    private val x = x
    private val y = y
    private val z = z
    override public fun show() {
        println("w: " + w + ", x: " + x + ", y: " + y + ", y: " + y + ", z: " + z)
    }
    override public fun clone(): Profile {
        return Rotation(w, x, y, z)
    }
}

fun main() {
    println("This is Prototype Pattern")
    val v1 = Vector3(1.1f, 2.2f, 3.3f)
    v1.show()
    val v2 = v1.clone()
    v2.show()
    val r1 = Rotation(4.4f, 5.5f, 6.6f, 7.7f)
    r1.show()
    val r2 = r1.clone()
    r2.show()
}
