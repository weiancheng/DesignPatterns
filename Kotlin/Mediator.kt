class Mediator() {
    private lateinit var light: Ligth
    private lateinit var switch: Switch
    private lateinit var remote: Remote

    public fun setLight(light: Ligth) {
        this.light = light
    }

    public fun setSwitch(switch: Switch) {
        this.switch = switch
    }

    public fun setRemote(remote: Remote) {
        this.remote = remote
    }

    public fun pressOn() {
        light.enable(true)
        switch.on()
    }

    public fun pressOff() {
        light.enable(false)
        switch.off()
    }

    public fun switchOn() {
        light.enable(true)
        remote.pressOn()
    }

    public fun switchOff() {
        light.enable(false)
        remote.pressOff()
    }
}

class Ligth() {

    private var powerOn: Boolean = false

    public fun isPowerOn(): Boolean = powerOn

    public fun enable(on: Boolean) {
        powerOn = on
    }
}

class Switch(mediator: Mediator) {
    private val mediator: Mediator = mediator
    private var switchOn: Boolean = false

    public fun on() {
        switchOn = true

    }
    public fun off() {switchOn = false }
    public fun isSwitchOn(): Boolean = switchOn
}

class Remote(mediator: Mediator) {
    private val mediator: Mediator = mediator
    private var isOn: Boolean = false

    public fun pressOn() {
        isOn = true
    }

    public fun pressOff() {
        isOn = false
    }

    public fun isRemoteOn(): Boolean = isOn
}

fun main(args: Array<String>) {
    println("This is Mediator Pattern")
    val mediator = Mediator()
    val light = Ligth()
    val remote = Remote(mediator)
    val switch = Switch(mediator)
    mediator.setRemote(remote)
    mediator.setSwitch(switch)
    mediator.setLight(light)

    mediator.pressOn()
    mediator.switchOff()
    println("is light on: " + light.isPowerOn())
}
